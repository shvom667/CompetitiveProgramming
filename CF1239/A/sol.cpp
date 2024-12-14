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
const ll mod = 1e9 + 7;
ll add(ll& a, ll b) {
    a += b;
    if (a >= mod) a %= mod;
    return a;
}
auto solve() {
    ll n,m;cin>>n>>m;
    vector<vector<ll>>dp(max(n+1,m+1),vector<ll>(2, 0));
    dp[1][0]=2;
    for(ll i=2;i<=max(n,m);i++){
        dp[i][1] = dp[i - 1][0];
        dp[i][0] = dp[i-1][1] + dp[i - 1][0];
        if (dp[i][1] >= mod) dp[i][1] %= mod;
        if (dp[i][0] >= mod) dp[i][0] %= mod;
    }

    ll fans = dp[n][0];
    add(fans, dp[n][1]);
    add(fans, dp[m][0]);
    add(fans, dp[m][1]);
    fans -= 2;
    fans += mod;
    fans %= mod;
    return fans;
    // return dp[n][0] + dp[n][1] + dp[m][0] + dp[m][1]  - 2;
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
