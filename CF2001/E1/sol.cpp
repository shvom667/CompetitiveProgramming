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

const ll maxn = 505;

ll N, K, P;

ll dp[maxn][maxn], pdp[maxn][maxn], out[maxn][maxn];



auto solve() {
    cin >> N >> K >> P;


    for (ll d = 0; d <= N; d++) for (ll k = 0; k <= K; k++) {
        dp[d][k] = pdp[d][k] = out[d][k] = 0;
    }

    for (ll k = 0; k <= K; k++) {
        dp[1][k] = 1;
        pdp[1][k] = k + 1;
    }

    for (ll d = 2; d <= N; d++) {
        for (ll k = 0; k <= K; k++) {
            for (ll v = 0; v <= k; v++) {
                dp[d][k] += dp[d-1][v] * pdp[d - 1][k -v];
                dp[d][k] %= P;
            }
            pdp[d][k] += dp[d][k];
            pdp[d][k] %= P;
            if (k) {
                pdp[d][k] += pdp[d][k - 1];
                pdp[d][k] %= P;
            }
        }
    }

    for (ll k = 0; k <= K; k++) {
        out[1][k] = 1;   
    }
    for (ll d = 2; d <= N; d++) {
        out[d][0] = 0;
    }

    for (ll d = 2; d <= N; d++) {
        for (ll k = 1; k <= K; k++) {
            for (ll vd = 1; vd <= k; vd++) {
                ll z = min(k - vd, vd - 1);
                assert(z >= 0);
                out[d][k] += 2 * out[d - 1][vd] * pdp[d - 1][z];
                out[d][k] %= P;
            }
        }
    }


    return out[N][K];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
