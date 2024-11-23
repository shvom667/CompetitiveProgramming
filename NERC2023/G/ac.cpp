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

const ll N = 501;

ll pdp[N][N][N];

auto solve() {
    ll n, p, M;
    cin >> n >> p >> M;
    
    pdp[0][0][0] = 1;
    for(ll i=1;i<N;i++) pdp[0][0][i] = 1;
    
    for (ll sum = 1; sum <= n - p; sum++) {
        for (ll x = 0; x < N; x++) {
            for (ll m = 0; m < N; m++) {
                // for (ll md = 0; md <= m; md++) {
                //     if (sum-m >= 0)
                //         dp[sum][x][m] += dp[sum-m][x^m][md];
                // }
                ll var = 0;
                if(sum-m>=0)
                    var += pdp[sum-m][x^m][m];
                pdp[sum][x][m] = var + (m >= 1 ? pdp[sum][x][m-1] : 0);
                pdp[sum][x][m] %= M;
            }
        }
    }
    
    ll fans = 0;
    // for (ll m = 1; m < N; m++) {
    //     fans += dp[n-p][p][m];
    // }
    // return fans;
    return pdp[n-p][p][N-1];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
