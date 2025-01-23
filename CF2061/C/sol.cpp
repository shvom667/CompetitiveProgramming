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
const ll mod = 998244353;

auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<ll>> dp(n, vector<ll> (2, 0));
    dp[0][0] = 1;

    if (a[0] == 0)
        dp[0][1] = 1;

    for (ll i = 1; i < n; i++) {
        dp[i][0] = (dp[i - 1][1]) % mod;

        if ((i - 2 < 0 && a[i] == 1)|| a[i - 2] + 1 == a[i])
            dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;
        
        if (a[i - 1] == a[i])
            dp[i][1] = (dp[i][1] + dp[i - 1][1]) % mod;

    }

    // for (ll i = 0; i < n; i++) {
    //     cout << dp[i][0] <<  " ";
    // }   cout << '\n';
    // for (ll i = 0; i < n; i++) {
    //     cout << dp[i][1] <<  " ";
    // }   cout << '\n';

    return (dp[n - 1][1] + dp[n - 1][0]) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
