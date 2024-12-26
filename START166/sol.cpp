#include <bits/stdc++.h>
using namespace std;
using ll = int;
#define pb push_back
template <typename T>
using Vec = vector<T>;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif


// ============

vector<int> MinPrime;
vector<int> PRIME;
void pre_calc_sieve(int N) {
	MinPrime = vector<int> (N + 1, 0);
	for (int i = 2; i <= N; ++i) {
		if (MinPrime[i] == 0) {
			MinPrime[i] = i;
			PRIME.push_back(i);
		}
		for (int j = 0; i * PRIME[j] <= N; ++j) {
			MinPrime[i * PRIME[j]] = PRIME[j];
			if (PRIME[j] == MinPrime[i]) {
				break;
			}
		}
	}
}

// ============

const ll mod = 998244353;
int prod(int a, int b) {
    long long res = 1;
    res *= a;
    res *= b;
    if (res >= mod) {
        res %= mod;
    }    
    return res;
}

int p(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int res = p(a, b / 2);
    long long fans = res;
    fans = fans * res;
    if (fans >= mod) {
        fans %= mod;
    }
    if (b & 1) fans *= a;
    if (fans >= mod) {
        fans %= mod;
    }
    return (int)fans;
}

int by(int a, int b) {
    return prod(a, p(b, mod - 2));
}
int add(int a, int b) {
    a += b;
    if (a >= mod)
        a %= mod;
    return a;
}

const ll N = 5e5 + 10;
ll l2[N];
vector<int> phi(N + 1);
void phi_1_to_n(int n) {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
}

ll ub(ll x, ll y) {
    return (x + y - 1) / y;
}

ll lb(ll x, ll y) {
    return x / y;
}

int getAns(int r, int k) {
    int fans = 0;
    // [r == k]
    if (r >= k && k == 1) {
        fans += 1;
    }
    // [1...k - 1]

    if (k - 1 >= 1 && k - 1 <= r) {
        fans = add(fans, phi[k]);
    }
    // dbg(k - 1, fans);
    // [k + 1 ... r]

    int kk = k;
    vector<ll> pf = {};
    while (kk > 1) {
        ll mp = MinPrime[kk];
        pf.push_back(mp);
        while (kk % mp == 0) {
            kk /= mp;
        }
    }

    auto get_div = [&] (ll x, ll y, ll val) {
        return lb(y, val) - lb(x - 1, val);
        // return y / val - (x - 1) / val;
    };

    ll sz = (ll) pf.size();
    ll F[1 << sz];

    F[0] = 1;
    for (ll sb = 1; sb <= sz; sb++) {
        for (ll i = 0; i < (1 << sz); i++) {
            if (__builtin_popcount(i) == sb) {
                F[i] = F[i - (i & -i)] * pf[l2[(i & -i)]];
            }
        }
    }
    // dbg(fans);
    ll cur = 0;
    if (k + 1 <= r) {
        for (ll i = 1; i < (1 << sz); i++) {
            if ((__builtin_popcount(i)) & 1) {
                cur += get_div(k + 1, r, F[i]);
            } else {
                cur -= get_div(k + 1, r, F[i]);
            }
        }
        // dbg(cur);
        fans += (r - k) - cur;
    }

    return fans;
}

auto solve() {
    ll n, m;
    cin >> n >> m;
    ll fans = 0;

    // ll res = getAns(10, 6);
    // dbg(res);
    // exit(0);

    // for (ll g = 1; g <= m; g++) {
    //     ll r = m / g;
    //     // [1...r]
    //     for (ll x = 1; x <= r; x++) {
    //         ll cnt = 0;
    //         for (ll v = 1; v <= r; v++) {
    //             if (gcd(v,x) == 1)  {
    //                 cnt++;
    //             }
    //         }
    //         fans = add(fans, p(cnt, n));
    //     }
    // }
    
    // O(m * m)

    // for (ll k = 1; k <= m; k++) {
    //     ll den = k;
    //     ll g = m / den;
    //     ll cnt = 0;
    //     for (ll i = 1; i <= m; i++) {
    //         if (gcd(i, k) == 1) {
    //             cnt++;
    //         }
    //         while (i == m / g) {
    //             fans = add(fans, p(cnt, n));
    //             g--;
    //             if (g == 0) break;
    //         }
    //     }
    // }

    for (ll k = 1; k <= m; k++) {
        // ll den = k;
        // ll g = m / den;
        // ll cnt = 0;
        // for (ll i = 1; i <= m; i++) {
        //     if (gcd(i, k) == 1) {
        //         cnt++;
        //     }
        //     while (i == m / g) {
        //         fans = add(fans, p(cnt, n));
        //         g--;
        //         if (g == 0) break;
        //     }
        // }
        // ll pr = -1;
        for (ll g = 1; g * k <= m; g++) {
            ll r = m / g;   
            // [1..r] and k
            // if (pr == r) continue;
            // dbg(r, k);
            ll cnt = getAns(r, k);
            fans = add(fans, p(cnt, n));
            dbg(fans);
            // pr = r;
        }
    }
    cout << fans << '\n';
    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    l2[1] = 0;
    ll cnt = 1;
    for (ll j = 2; j < N; j *= 2) {
        l2[j] = cnt++;
    }
    for (ll i = 1; i < N; i++) {
        if (l2[i] == 0) {
            l2[i] = l2[i - 1];
        }
    }

    ll T;
    phi_1_to_n(N);
    pre_calc_sieve(N);

    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
    }
    return 0;
}
