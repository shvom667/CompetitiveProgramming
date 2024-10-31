#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
const ll INF = 1e18;
using i64 = long long;

/*
In that moment we knew, home was a penn, humanity cattle
*/

// ============

template<class T, class U>
// T -> node, U->update.
struct Lsegtree {
	vector<T>st;
	vector<U>lazy;
	ll n;
	T identity_element;
	U identity_update;
	Lsegtree(ll n, T identity_element, U identity_update) {
		this->n = n;
		this->identity_element = identity_element;
		this->identity_update = identity_update;
		st.assign(4 * n, identity_element);
		lazy.assign(4 * n, identity_update);
	}
	T combine(T l, T r) {
		// change this function as required.
		T ans = (l + r);
		return ans;
	}
	void buildUtil(ll v, ll tl, ll tr, vector<T>&a) {
		if (tl == tr) {
			st[v] = a[tl];
			return;
		}
		ll tm = (tl + tr) >> 1;
		buildUtil(2 * v + 1, tl, tm, a);
		buildUtil(2 * v + 2, tm + 1, tr, a);
		st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
	}
	// change the following 2 functions, and you're more or less done.
	T apply(T curr, U upd, ll tl, ll tr) {
		T ans = (tr - tl + 1) * upd;
		return ans;
	}
	U combineUpdate(U old_upd, U new_upd, ll tl, ll tr) {
		U ans = old_upd;
		ans = new_upd;
		return ans;
	}
	void push_down(ll v, ll tl, ll tr) {
		if (lazy[v] == identity_update)return;
		st[v] = apply(st[v], lazy[v], tl, tr);
		if (2 * v + 2 < 4 * n) {
			ll tm = (tl + tr) >> 1;
			lazy[2 * v + 1] = combineUpdate(lazy[2 * v + 1], lazy[v], tl, tm);
			lazy[2 * v + 2] = combineUpdate(lazy[2 * v + 2], lazy[v], tm + 1, tr);
		}
		lazy[v] = identity_update;
	}
	T queryUtil(ll v, ll tl, ll tr, ll l, ll r) {
		push_down(v, tl, tr);
		if (l > r)return identity_element;
		if (tr < l or tl > r) {
			return identity_element;
		}
		if (l <= tl and r >= tr) {
			return st[v];
		}
		ll tm = (tl + tr) >> 1;
		return combine(queryUtil(2 * v + 1, tl, tm, l, r), queryUtil(2 * v + 2, tm + 1, tr, l, r));
	}

	void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd) {
		push_down(v, tl, tr);
		if (tr < l or tl > r)return;
		if (tl >= l and tr <= r) {
			lazy[v] = combineUpdate(lazy[v], upd, tl, tr);
			push_down(v, tl, tr);
		} else {
			ll tm = (tl + tr) >> 1;
			updateUtil(2 * v + 1, tl, tm, l, r, upd);
			updateUtil(2 * v + 2, tm + 1, tr, l, r, upd);
			st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
		}
	}



	void build(vector<T>a) {
		assert((i64)a.size() == n);
		buildUtil(0, 0, n - 1, a);
	}
	T query(ll l, ll r) {
		return queryUtil(0, 0, n - 1, l, r);
	}
	void update(ll l, ll r, U upd) {
		updateUtil(0, 0, n - 1, l, r, upd);
	}
};


// ============

#include <cassert>
#include <iostream>
#include <type_traits>

// ============

constexpr bool is_prime(unsigned n) {
    if (n == 0 || n == 1) {
        return false;
    }
    for (unsigned i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

constexpr unsigned mod_pow(unsigned x, unsigned y, unsigned mod) {
    unsigned ret = 1, self = x;
    while (y != 0) {
        if (y & 1) {
            ret = (unsigned) ((unsigned long long) ret * self % mod);
        }
        self = (unsigned) ((unsigned long long) self * self % mod);
        y /= 2;
    }
    return ret;
}

template <unsigned mod>
constexpr unsigned primitive_root() {
    static_assert(is_prime(mod), "`mod` must be a prime number.");
    if (mod == 2) {
        return 1;
    }

    unsigned primes[32] = {};
    int it = 0;
    {
        unsigned m = mod - 1;
        for (unsigned i = 2; i * i <= m; ++i) {
            if (m % i == 0) {
                primes[it++] = i;
                while (m % i == 0) {
                    m /= i;
                }
            }
        }
        if (m != 1) {
            primes[it++] = m;
        }
    }
    for (unsigned i = 2; i < mod; ++i) {
        bool ok = true;
        for (int j = 0; j < it; ++j) {
            if (mod_pow(i, (mod - 1) / primes[j], mod) == 1) {
                ok = false;
                break;
            }
        }
        if (ok)
            return i;
    }
    return 0;
}

// y >= 1
template <typename T>
constexpr T safe_mod(T x, T y) {
    x %= y;
    if (x < 0) {
        x += y;
    }
    return x;
}

// y != 0
template <typename T>
constexpr T floor_div(T x, T y) {
    if (y < 0) {
        x *= -1;
        y *= -1;
    }
    if (x >= 0) {
        return x / y;
    } else {
        return -((-x + y - 1) / y);
    }
}

// y != 0
template <typename T>
constexpr T ceil_div(T x, T y) {
    if (y < 0) {
        x *= -1;
        y *= -1;
    }
    if (x >= 0) {
        return (x + y - 1) / y;
    } else {
        return -(-x / y);
    }
}
// ============

template <unsigned mod>
class ModInt {
    static_assert(mod != 0, "`mod` must not be equal to 0.");
    static_assert(
        mod < (1u << 31),
        "`mod` must be less than (1u << 31) = 2147483648.");

    unsigned val;

  public:
    static constexpr unsigned get_mod() {
        return mod;
    }

    constexpr ModInt() : val(0) {}
    template <typename T, std::enable_if_t<std::is_signed_v<T>> * = nullptr>
    constexpr ModInt(T x) : val((unsigned) ((long long) x % (long long) mod + (x < 0 ? mod : 0))) {}
    template <typename T, std::enable_if_t<std::is_unsigned_v<T>> * = nullptr>
    constexpr ModInt(T x) : val((unsigned) (x % mod)) {}

    static constexpr ModInt raw(unsigned x) {
        ModInt<mod> ret;
        ret.val = x;
        return ret;
    }

    constexpr unsigned get_val() const {
        return val;
    }

    constexpr ModInt operator+() const {
        return *this;
    }
    constexpr ModInt operator-() const {
        return ModInt<mod>(0u) - *this;
    }

    constexpr ModInt &operator+=(const ModInt &rhs) {
        val += rhs.val;
        if (val >= mod)
            val -= mod;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &rhs) {
        if (val < rhs.val)
            val += mod;
        val -= rhs.val;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &rhs) {
        val = (unsigned long long)val * rhs.val % mod;
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt &rhs) {
        val = (unsigned long long)val * rhs.inv().val % mod;
        return *this;
    }

    friend constexpr ModInt operator+(const ModInt &lhs, const ModInt &rhs) {
        return ModInt<mod>(lhs) += rhs;
    }
    friend constexpr ModInt operator-(const ModInt &lhs, const ModInt &rhs) {
        return ModInt<mod>(lhs) -= rhs;
    }
    friend constexpr ModInt operator*(const ModInt &lhs, const ModInt &rhs) {
        return ModInt<mod>(lhs) *= rhs;
    }
    friend constexpr ModInt operator/(const ModInt &lhs, const ModInt &rhs) {
        return ModInt<mod>(lhs) /= rhs;
    }

    constexpr ModInt pow(unsigned long long x) const {
        ModInt<mod> ret = ModInt<mod>::raw(1);
        ModInt<mod> self = *this;
        while (x != 0) {
            if (x & 1)
                ret *= self;
            self *= self;
            x >>= 1;
        }
        return ret;
    }
    constexpr ModInt inv() const {
        static_assert(is_prime(mod), "`mod` must be a prime number.");
        assert(val != 0);
        return this->pow(mod - 2);
    }

    friend std::istream &operator>>(std::istream &is, ModInt<mod> &x) {
        long long val;
        is >> val;
        x.val = val % mod + (val < 0 ? mod : 0);
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const ModInt<mod> &x) {
        os << x.val;
        return os;
    }

    friend bool operator==(const ModInt &lhs, const ModInt &rhs) {
        return lhs.val == rhs.val;
    }

    friend bool operator!=(const ModInt &lhs, const ModInt &rhs) {
        return lhs.val != rhs.val;
    }
};

[[maybe_unused]] constexpr unsigned mod998244353 = 998244353;
[[maybe_unused]] constexpr unsigned mod1000000007 = 1000000007;

// ============
// ============

#include <vector>
#include <cassert>

template <typename T>
class FactorialTable {
    std::vector<T> fac;
    std::vector<T> ifac;

  public:
    FactorialTable() : fac(1, T(1)), ifac(1, T(1)) {}

    FactorialTable(int n) : fac(n + 1), ifac(n + 1) {
        assert(n >= 0);
        fac[0] = T(1);
        for (int i = 1; i <= n; ++i) {
            fac[i] = fac[i - 1] * T(i);
        }
        ifac[n] = T(1) / T(fac[n]);
        for (int i = n; i > 0; --i) {
            ifac[i - 1] = ifac[i] * T(i);
        }
    }

    void resize(int n) {
        int old = n_max();
        if (n <= old) {
            return;
        }
        fac.resize(n + 1);
        for (int i = old + 1; i <= n; ++i) {
            fac[i] = fac[i - 1] * T(i);
        }
        ifac.resize(n + 1);
        ifac[n] = T(1) / T(fac[n]);
        for (int i = n; i > old; --i) {
            ifac[i - 1] = ifac[i] * T(i);
        }
    }

    inline int n_max() const {
        return (int) fac.size() - 1;
    }

    inline T fact(int n) const {
        assert(n >= 0 && n <= n_max());
        return fac[n];
    }

    inline T inv_fact(int n) const {
        assert(n >= 0 && n <= n_max());
        return ifac[n];
    }

    inline T choose(int n, int k) const {
        assert(k <= n_max() && n <= n_max());
        if (k > n || k < 0) {
            return T(0);
        }
        return fac[n] * ifac[k] * ifac[n - k];
    }

    inline T multi_choose(int n, int k) const {
        assert(n >= 1 && k >= 0 && k + n - 1 <= n_max());
        return choose(k + n - 1, k);
    }

    inline T n_terms_sum_k(int n, int k) const {
        assert(n >= 0);
        if (k < 0) {
            return T(0);
        }
        if (n == 0) {
            return k == 0 ? T(1) : T(0);
        }
        return choose(n + k - 1, n - 1);
    }
};

using Mint = ModInt<mod998244353>;
const ll  N = 1e6;
vector<Mint> catalan(N);
FactorialTable<Mint> table(N);
// ============

template<typename T>
vector<T> make_unique(vector<T> a) {
    set<T> s;
    for (auto&x : a) {
        s.insert(x);
    }
    vector<T> fans;
    for (auto&val : s) {
        fans.push_back(val);
    }
    return fans;
}

auto solve() {
    ll n;
    cin >> n;
    ll q;
    cin >> q;

    Vec<pair<ll, ll>> in;
    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        in.pb({l ,r});
    }
    if (n & 1) {
        return 0ll;
    }

    for (ll i = 0; i < q; i++) {
        if ((in[i].second - in[i].first + 1) & 1) return 0ll;
    }

    if (true) 
    {
        set<ll> st, en;
        for (ll i  = 0; i < q; i++) {
            st.insert(in[i].first);
            en.insert(in[i].second);
        }
        for (auto&s: st) {
            if (en.count(s)) {
                return 0ll;
            }
        }
    }

    vector<pair<ll, ll>> use;

    vector<vector<ll>> ep(n + 1), sp(n + 1);

    for (ll i = 0; i < q; i++) {
        sp[in[i].second].pb(in[i].first);
        ep[in[i].first].pb(in[i].second);
    }

    for (ll i = 1; i <= n; i++) {
        assert(min((ll)sp[i].size(), (ll)ep[i].size()) == 0ll);
    }

    if (true) {
        multiset<ll> en;
        for (ll i = 1; i <= n; i++) {
            ll E = INF;
            auto it = en.upper_bound(i);
            if (it == end(en)) {

            } else {
                E = *it;
            }
            for (auto& e : ep[i]) {
                if (E < e) {
                    use.pb({i, e});
                }
                en.insert(e);
            }
            en.erase(i);
        }
    }

    if (true) {
        multiset<ll> st;
        for (ll i = n; i >= 1; i--) {
            ll S = -1;
            auto it = st.lower_bound(i);
            if (it == begin(st)) {

            } else {
                it--;
                S = *it;
            }

            for (auto& s : sp[i]) {
                if (S > s) {
                    use.push_back({s, i});
                }
                st.insert(s);
            }
            st.erase(i);
        }
    }

    if (true) {
        multiset<ll> st, en;
        for (ll i = 1; i <= n; i++) {
            for (auto&e : ep[i]) {
                st.insert(i);
                en.insert(e);
            }
            
            if (sp[i].size() == 0) continue;
            ll E = *en.rbegin();
            ll S = INF;
            for (auto&s : sp[i]) {
                if (E == i) {
                    S = min(S, s);
                }    
                st.erase(st.find(s));
                en.erase(en.find(i));
            }
            if (S != INF) {
                use.push_back({S, E});
            }
        }
    }

    use = make_unique<pair<ll, ll>>(use);


    dbg(use);   

    for (ll i = 1; i <= n; i++) {
        sp[i].clear();
        ep[i].clear();
    }

    for (auto& [x, y] : use) {
        sp[y].push_back(x);
        ep[x].push_back(y);
    }

    vector<bool> empty(n + 1, false);

    if (true) {
        vector<ll> freq(n + 2, 0);
        for (auto&[x, y] : use) {
            freq[x] += 1;
            freq[y + 1] += -1;
        }
        for (ll i = 1; i <= n; i++) {
            freq[i] += freq[i - 1];
        }
        for (ll i = 1; i <= n; i++) {
            if (freq[i] == 0) {
                empty[i] = true;
            }
        }
    }
    
    vector<pair<ll, ll>> smi;

    vector<bool> is_start(n + 1, false);
    vector<bool> is_end(n + 1, false);
    
    for (auto&[x, y] : use) {
        is_start[x] = true;
        is_end[y] = true;
    }


    if (true) {
        multiset<ll> st, en;        
        for (ll i = 1; i <= n; i++) {
            for (auto& e : ep[i]) {
                st.insert(i);
                en.insert(e);
            }


            if (is_start[i]) {
                if (!smi.empty() && smi.back().second == -1) {
                    auto b = smi.back();
                    smi.pop_back();
                    b.second = i - 1;
                    smi.push_back(b);
                }
                smi.push_back({i, -1});
            }

            if (is_end[i]) {
                if (!smi.empty() && smi.back().second == -1) {
                    auto b = smi.back();
                    smi.pop_back();
                    b.second = i;
                    smi.push_back(b);
                } else {
                    smi.push_back({smi.back().second + 1, i});
                }
            }

            if (st.empty()) {
                // then it is empty
            }


            for (auto&s : sp[i]) {
                st.erase(st.find(s));
                en.erase(en.find(i));
            }
        }
    }

    for (auto& [u, v] : smi) {
        if (u == -1 || v == -1) {
            assert(false);
        }
    }

    ll cnt_global = 0;
    for (ll i = 1; i <= n; i++) {
        if (empty[i]) cnt_global++;
    }

    if (cnt_global&1) {
        return 0ll;
    }

    for (auto& [u, v] : smi) {
        // if (n == 300000 && q == 300000) assert(false);
        if ((v - u + 1) & 1) return 0ll;
    }
    
    Mint fans = 1;


    // for (auto& [u, v] : smi) {
    //     fans *= catalan[v - u + 1];
    // }

    // fans *= catalan[cnt_global];

    dbg(smi);

    set<pair<ll, ll>> used;
    for (auto& [x, y] : use) {
        used.insert({x, y});
    }
    dbg(used);
    Vec<pair<ll, ll>> xtra;
    for (auto& [x, y] : in) {
        if (used.count({x, y}) == 0) {
            xtra.push_back({x, y});
        }
    }

    dbg(xtra);

    Vec<pair<ll, ll>> all_intervals;
    for (auto& [x, y] : smi) {
        all_intervals.push_back({x, y});
    } 
    for (auto& [x, y] : xtra) {
        all_intervals.push_back({x, y});
    }

    sort(begin(all_intervals), end(all_intervals), [&] (auto x, auto y) {
        return x.second - x.first < y.second - y.first;
    });

    dbg(all_intervals);

    Lsegtree<ll, ll> seg(n + 1, 0, INF);


    vector<ll> dummy(n + 1, 0);
    seg.build(dummy);

    dbg(seg.query(0, n + 1));

    dbg(seg.query(200, 801));

    dbg(fans.get_val());
    for (auto [x, y] : all_intervals) {
        ll q = seg.query(x, y);
        dbg(x,y);
        seg.update(x, y, 1);
        dbg(x, y, q);
        ll lft = (y - x + 1) - q;
        fans *= catalan[lft];
    }

    fans *= catalan[cnt_global];

    return (ll)fans.get_val();
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       
    catalan[0] = 1;

    for (ll i = 2;  i < N; i+=2) {
        catalan[i] = table.choose(i, i / 2);
        catalan[i] /= (i / 2 + 1);
    }

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
