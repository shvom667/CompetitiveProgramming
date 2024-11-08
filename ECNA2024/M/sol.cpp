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

auto chmin(auto&x, auto y) {
    x = min(x, y);
}

auto solve() {
    ll M, N, K;
    cin >> M >> N >> K;

    ll dp[M][N][2][K][51];

    for (ll i = 0; i < M; i++) for (ll j = 0; j < N; j++) for (ll d = 0; d < 2; d++) 
        for (ll k = 0; k < K; k++) for (ll p = 0; p <= 50; p++) dp[i][j][d][k][p] = INF;

    char G[M][N];

    for (ll i = 0; i < M; i++) for (ll j = 0; j < N; j++) cin >> G[i][j];

    vector<string> W(K);
    for (ll i = 0; i < K; i++) cin >> W[i];

    // 0 -> left 1->right dir

    for (ll j = 0; j < N; j++) {
        for (ll d = 0; d < 2; d++) {
            for (ll k = 0; k < K; k++) {
                if (W[k][0] == G[0][j])
                    dp[0][j][d][k][0] = 1;
            }
        }
    }

    for (ll j = N - 2; j >= 0; j--) { // moving direction left
        for (ll k = 0; k < K; k++) {
            for (ll p = 1; p < W[k].size(); p++) {
                if (W[k][p] == G[0][j])
                    chmin(dp[0][j][0][k][p], dp[0][j + 1][0][k][p - 1] +  1);
            }
            // p == 0
            for (ll x = 0; x < K; x++) {
                if (W[k][0] == G[0][j]) 
                    chmin(dp[0][j][0][k][0], dp[0][j + 1][0][x][W[x].size() - 1] + 1);
            }
        }
    }

    for (ll j = 1; j < N; j++) { // moving direction right
        for (ll k = 0; k < K; k++) {
            for (ll p = 1; p < W[k].size(); p++) {
                if (W[k][p] == G[0][j])
                    chmin(dp[0][j][1][k][p], dp[0][j - 1][1][k][p - 1] +  1);
            }
            for (ll x = 0; x < K; x++) {
                if (W[k][0] == G[0][j]) 
                    chmin(dp[0][j][1][k][0], dp[0][j - 1][1][x][W[x].size() - 1] + 1);
            }
        }
    }

    for (ll i = 1; i < M; i++) {

        for (ll j = 0; j < N; j++) {
            for (ll d = 0; d < 2; d++) {
                for (ll k = 0; k < K; k++) {
                    for (ll p = 1; p < W[k].size(); p++) {
                        if (W[k][p] == G[i][j]) {
                            chmin(dp[i][j][d][k][p], dp[i - 1][j][0][k][p - 1] + 1);
                            chmin(dp[i][j][d][k][p], dp[i - 1][j][1][k][p - 1] + 1);
                        }
                    }
                    // p = 0
                    for (ll x = 0; x < K; x++) {
                        if (W[k][0] == G[i][j]) {
                            chmin(dp[i][j][d][k][0], dp[i - 1][j][0][x][W[x].size() - 1] + 1);
                            chmin(dp[i][j][d][k][0], dp[i - 1][j][1][x][W[x].size() - 1] + 1);
                        }
                    }
                }
            }
        }


        for (ll j = N - 2; j >= 0; j--) { // moving direction left
            for (ll k = 0; k < K; k++) {
                for (ll p = 1; p < W[k].size(); p++) {
                    if (W[k][p] == G[i][j])
                        chmin(dp[i][j][0][k][p], dp[i][j + 1][0][k][p - 1] +  1);
                }
                // p == 0
                for (ll x = 0; x < K; x++) {
                    if (W[k][0] == G[i][j]) 
                        chmin(dp[i][j][0][k][0], dp[i][j + 1][0][x][W[x].size() - 1] + 1);
                }
            }
        }


        for (ll j = 1; j < N; j++) { // moving direction right
            for (ll k = 0; k < K; k++) {
                for (ll p = 1; p < W[k].size(); p++) {
                    if (W[k][p] == G[i][j])
                        chmin(dp[i][j][1][k][p], dp[i][j - 1][1][k][p - 1] +  1);
                }
                for (ll x = 0; x < K; x++) {
                    if (W[k][0] == G[i][j]) 
                        chmin(dp[i][j][1][k][0], dp[i][j - 1][1][x][W[x].size() - 1] + 1);
                }
            }
        }

    }


    ll fans = INF;

    for (ll j = 0; j < N; j++) {
        for (ll d = 0; d < 2; d++) {
            for (ll k = 0; k < K; k++) {

                chmin(fans, dp[M-1][j][d][k][W[k].size() - 1]);
            }
        }
    }


    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        
        if (res >= 2500 + 10 ) {
            cout << "impossible\n";
        } else {
            cout << res << "\n";
        }
    }
    return 0;
}
