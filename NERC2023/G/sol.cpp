#include<bits/stdc++.h>
using namespace std;
using ll=int;
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
    // Vec<Vec<Vec<ll>>> pdp(N + 1, Vec<Vec<ll>> (N + 1, Vec<ll> (N + 1, 0)));
auto solve() {
    ll n, p, M;
    cin >> n >> p >> M;
    
    // ll pdp[n + 1][n + 1][n + 1];
    // for (ll i = 0; i <= n; i++)for(ll j=0;j<=n;j++)for(ll k=0;k<=n;k++) pdp[i][j][k]=0;
    
    
    pdp[0][0][0] = 1;
    for(ll i=1;i<N;i++) pdp[0][0][i] = 1;

    for (ll sum = 1; sum <= n - p; sum++) {
        for (ll x = 0; x < N; x++) {
            for (ll m = 0; m < N; m++) {
                if (m > sum) {
                    pdp[sum][x][m] = pdp[sum][x][m-1];
                    continue;
                }
                ll var = 0;
                if(sum-m>=0)
                    var += pdp[sum-m][x^m][m];
                long long ans = (long long)var + (long long)(m >= 1 ? pdp[sum][x][m-1] : 0ll);

                if(ans>=M)
                ans = ans%M;
                pdp[sum][x][m] = ans;
            }
        }
    }
    
    ll fans = 0;
    
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
