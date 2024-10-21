#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
/*
This will work for n <= 85 * 2
*/
const ll INF=1e18;
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= k;
    }
    ll m = 85;
    vector<vector<ll>> dp(n, vector<ll> (m, INF));
    dp[0][0] = a[0];

    for (ll i = 1; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            for (ll p = 0; p < m; p++) {
                dp[i][j] = min(dp[i][j], dp[i-1][p] 
                    + max(0ll, a[i] + j * k  - a[i-1] - p * k)
                );
            }
        }
    }


    return min(dp[n-1][0], dp[n-1][1]);
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
