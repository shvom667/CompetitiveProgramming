#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif

const ll INF = 1e18;
 
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    k = min(n - 1, k);
    dbg(k);
    vector<vector<ll>> dp(n + 1, vector<ll> (12, INF));
    for (ll i = 1; i <= n; i++) {
        dp[i][0] = a[i];
        if (i > 1) {
            dp[i][0] += dp[i-1][0];
        }
    }
    vector<vector<ll>> sum(n + 1, vector<ll> (12, INF));

    for (ll i  = 1; i <= n; i++) {
        sum[i][0] = a[i];
    }
    for (ll i = 1; i <= n; i++) {
        for (ll x = 1; x <= 11; x++) {
            if (i - x >= 1) {
                ll totSum = 0;
                ll minVal = INF;
                for (ll ind = i - x; ind <= i; ind++) {
                    // totSum += ;
                    minVal = min(minVal, a[ind]);
                }
                sum[i][x] = minVal * (x + 1);
            }
        }
    }

    // dbg(sum[2][1]);

    for (ll i = 1; i <= n; i++) {
        for (ll x = 1; x <= k; x++) {
            for (ll z = 0; z <= x; z++) {
                ll first = 0;
                if (i - z - 1 >= 1) {
                    first = dp[i - z - 1][x - z];
                }
                ll val = sum[i][z];
                ll third = 0;
                if (i - z >= 0) {

                }
                dp[i][x] = min(first+ val + third, dp[i][x]);
            }
        }
    }
    ll fans = INF;
    // cout << dp[2][1] << "\n";
    for (ll x = 0; x <= k; x++) 
        fans = min(fans, dp[n][x]);

    return fans;
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
