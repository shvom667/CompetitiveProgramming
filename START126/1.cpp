#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

// =================

// Debugging template
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A>
void __print(const A &x);
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename... A>
void __print(const tuple<A...> &t);
template <typename T>
void __print(stack<T> s);
template <typename T>
void __print(queue<T> q);
template <typename T, typename... U>
void __print(priority_queue<T, U...> q);
/*
void __print(Mint x) {
	cerr << x;
}
*/
template <typename A>
void __print(const A &x) {
	bool first = true;
	cerr << '{';
	for (const auto &i : x) {
		cerr << (first ? "" : ","), __print(i);
		first = false;
	}
	cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p) {
	cerr << '(';
	__print(p.first);
	cerr << ',';
	__print(p.second);
	cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t) {
	bool first = true;
	cerr << '(';
	apply([&first](const auto & ...args) { ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
	cerr << ')';
}
template <typename T>
void __print(stack<T> s) {
	vector<T> debugVector;
	while (!s.empty()) {
		T t = s.top();
		debugVector.push_back(t);
		s.pop();
	}
	reverse(debugVector.begin(), debugVector.end());
	__print(debugVector);
}
template <typename T>
void __print(queue<T> q) {
	vector<T> debugVector;
	while (!q.empty()) {
		T t = q.front();
		debugVector.push_back(t);
		q.pop();
	}
	__print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q) {
	vector<T> debugVector;
	while (!q.empty()) {
		T t = q.top();
		debugVector.push_back(t);
		q.pop();
	}
	__print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
	__print(H);
	if (sizeof...(T))
		cerr << ", ";
	_print(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dbg(...)
#endif

// =================
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

using Mint = ModInt<mod1000000007>;
// ============
void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t;
  while (t--) solve();
}

ll M, N;
const ll o = 1;


Mint subsequence_and_zero(vector<ll> A) {
  ll n = (ll) A.size();
  vector<Mint> dp1(N, 0);
  for (ll i = 0; i < n; i++) {
    dp1[A[i]] += 1;
  }
  for (ll b = 0; b < M; b++) {
    for (ll s = N - 1; s >= 0; s--) {
      if (((1ll << b) & s) == 0) {
        dp1[s] += dp1[s ^ (1ll << b)];
      }
    }
  }

  vector<Mint> dp(N, 0);
  Mint two = 2;

  for (ll s = 0; s < N; s++) {
    dp[s] = two.pow(dp1[s].get_val()) - 1;
  }
  for (ll b = 0; b < M; b++) {
    for (ll s = N - 1; s >= 0; s--) {
      if (((1ll << b) & s) == 0) {
        dp[s] -= dp[s ^ (1ll << b)];
      }
    }
  }
  return dp[0];
}
Vec<ll> pf = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
void solve() {
  ll n, k;
  cin >> n >> k;
  for (ll j = 0; j < pf.size(); j++) {
    if (pf[j] == k)
      M = j;
  }
  N = (1ll << M);

  Vec<ll> a(n), b;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (ll i = 0; i < n; i++) {
    if (a[i] % k != 0) continue;
    ll x = 0;
    for (ll j = 0; j < (ll)pf.size(); j++) {
      if (a[i] % k == 0  && pf[j] < k && a[i] % pf[j] == 0) {
        x ^= (1ll << j);
      }
    }
    b.pb(x);
  }
  if (b.size() == 0) {
    cout << 0 << '\n';
    return;
  }
  if (binary_search(begin(pf), end(pf), k)) {
    cout << subsequence_and_zero(b) << "\n";
  } else {
    cout << 0 << "\n";
  }
}
