#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

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
	    ret = (unsigned)((unsigned long long)ret * self % mod);
	}
	self = (unsigned)((unsigned long long)self * self % mod);
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
	if (ok) return i;
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
    static_assert(mod < (1u << 31),
                  "`mod` must be less than (1u << 31) = 2147483648.");

    unsigned val;

   public:
    static constexpr unsigned get_mod() { return mod; }

    constexpr ModInt() : val(0) {}
    template <typename T, std::enable_if_t<std::is_signed_v<T>> * = nullptr>
    constexpr ModInt(T x)
        : val((unsigned)((long long)x % (long long)mod + (x < 0 ? mod : 0))) {}
    template <typename T, std::enable_if_t<std::is_unsigned_v<T>> * = nullptr>
    constexpr ModInt(T x) : val((unsigned)(x % mod)) {}

    static constexpr ModInt raw(unsigned x) {
	ModInt<mod> ret;
	ret.val = x;
	return ret;
    }

    constexpr unsigned get_val() const { return val; }

    constexpr ModInt operator+() const { return *this; }
    constexpr ModInt operator-() const { return ModInt<mod>(0u) - *this; }

    constexpr ModInt &operator+=(const ModInt &rhs) {
	val += rhs.val;
	if (val >= mod) val -= mod;
	return *this;
    }
    constexpr ModInt &operator-=(const ModInt &rhs) {
	if (val < rhs.val) val += mod;
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
	    if (x & 1) ret *= self;
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

#include <cassert>
#include <vector>

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

    inline int n_max() const { return (int)fac.size() - 1; }

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
void __print(Mint x){
    cerr<<x;
}
// ============

auto prev_state(ll p, ll a, ll b, ll c, ll x) {
    if (p == 1)a--;
    if (p == 2)b--;
    if (p == 3)c--;

    p ^= (1ll << x);

    if (p >= 4) {
        p = 7 - p;
    }
    return make_tuple(p,a,b,c);
}

auto solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = "$" + s;

    Mint dp[n+1][4][n+2][n+2][n+2];

    dp[0][0][0][0][0] = 1;

    for (ll i = 1; i <= n; i++) {
        for (ll a = 0; a <= i+1; a++) {
            for (ll b = 0; a + b <= i+1; b++) {
                for (ll c = 0; a + b + c <= i+1; c++) {
                    for (ll p = 0; p < 4; p++) {
                        for (ll x = 0; x < 3; x++) {
                            if (s[i] == '?' || s[i] == (char)('A' + x)) {
                                // check if the state is valid
                                auto [pp,aa,bb,cc]=prev_state(p,a,b,c,x);
                                
                                if (aa >= 0 && bb >= 0 && cc >= 0) {
                                    dp[i][p][a][b][c] += dp[i - 1][pp][aa][bb][cc];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    Mint fans = 0;

    auto calc = [&] (ll a, ll b, ll c, ll d) {
        ll res = 0;
        res += (a * (a - 1)) / 2;
        res += (b * (b - 1)) / 2;
        res += (c * (c - 1)) / 2;
        res += (d * (d - 1)) / 2;
        return res;
    };
    
    for (ll a = 0; a <= n + 1; a++) {
        for (ll b = 0; a + b <= n + 1; b++) {
            for (ll c = 0; a + b + c <= n + 1; c++) {
                ll d = n + 1 - a - b - c;
                if (calc(a, b, c, d) >= k) {
                    for (ll p = 0; p < 4; p++) {
                        fans += dp[n][p][a][b][c];
                    }
                }
            }
        }
    }

    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	auto res = solve();
	cout << res << "\n";
    }
    return 0;
}