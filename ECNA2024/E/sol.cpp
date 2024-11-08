#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;


// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif

 
auto bf() {

    vector<ll> v;
    ll n = 10;
    for (ll i = 1; i <= n; i++) v.push_back(i);
    assert((ll)v.size() == n);

    ll den = 0;
    ll num = 0;
    set<vector<ll>> s;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            vector<ll> u;
            for (ll k = 0; k < n; k++) {
                if (k != i && k != j) {
                    u.push_back(v[k]);
                }
            }
            // dbg(u);
            ll sq = 4;
            do {
                bool ok = true;
                assert((ll)u.size() == 2 * sq);
                for (ll i = 0; i < 2 * sq; i+=2) {
                    // u[i], u[i + 1]
                    ll cnt = 0;
                    cnt += (u[i] >= 1 && u[i] <= 4);
                    cnt += (u[i + 1] >= 1 && u[i + 1] <= 4);
                    if (cnt != 1) {
                        ok = false;
                    }
                }
                if (ok) {
                    dbg(u);
                    s.insert(u);
                    num++;
                }

                den++;
            } while (next_permutation(begin(u), end(u)));
        }
    }
    dbg(s.size());

    cout << num << " " << den << "\n";
}

const ll M = 50;
ll C[M][M];
ll F[M];

ll gcd(ll x, ll y) {
    if (min(x, y) == 0) return max(x, y);
    return __gcd(x, y);
}
    
ll dp[M][M][M];

void init() {
    C[0][0] = 1;
    for (ll i = 1; i < M; i++) {
        C[i][0] = 1;
    }

    for (ll i = 1; i < M; i++) {
        for (ll j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }

    F[0] = 1;
    for (ll i = 1; i < M; i++) {
        F[i] = F[i - 1] * i;
    }

    dp[0][0][0] = 1;
    dp[1][0][0] = 1;
    dp[1][1][0] = 1;

    for (ll i = 2; i < M; i++) {
        for (ll p = 0; p <= i; p++) {
            for (ll s = 0; s + p <= i; s++) {
                if (p >= s) {
                    dp[i][p][s] += dp[i-1][p][s];
                    dp[i][p][s] += dp[i-1][p][s-1] * (p - s + 1);
                    if (p >= s + 1) {
                        dp[i][p][s] += dp[i - 1][p - 1][s];
                    }
                }
            }
        }
    }

    // for (ll i = 1; i <= 5; i++) {
    //     for (ll p = 1; p <= 5; p++) {
    //         for (ll s = 1; s <= 5; s++) {
    //             dbg(i,p,s,dp[i][p][s]);
    //         }
    //     }
    // }
}



void solve() {
    ll N, M, P;
    
    cin >> M >> N >> P;

    if (P == 0) {
        if (N == 0) {
            cout << "1/1" << "\n";
        } else {
            cout << "0/1" << "\n";
        }
        return;
    }

    ll num = 0;

    for (ll s = 0; s <= N - 1; s++) {
        dbg(P-1, N-1, s, dp[P-1][N-1][s]);
        num += dp[P - 1][N - 1][s] * C[M - P][N  - s] * F[N - s];
    }

    ll den = ( C[M][2 * N] * F[2 * N] / F[N] ) / (1ll<<N);

    ll g = gcd(num, den);


    dbg(M, N, P);
    dbg(num, den);

    num /= g;
    den /= g;


    dbg(num, den);

    cout << num << "/" << den << "\n";
}   

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    init();
    for (ll tc = 1; tc <= T; tc++) {
        solve();
        // auto res = solve();
        // cout << res << "\n";
    }
    return 0;
}
