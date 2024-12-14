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

auto solve() {
    ll n;
    cin >> n;
    vector<ll> t(n);
    for (ll i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(begin(t), end(t));

    vector<vector<ll>> dp(n, vector<ll> (500, 1e10));

    for (ll v = 1; v < 500; v++) {
        dp[0][v] = abs(t[0] - v);
    }

    for (ll i = 1; i < n; i++) {
        for (ll v = 1; v < 500; v++) {
            for (ll pv = 1; pv < v; pv++) {
                dp[i][v] = min(dp[i][v], dp[i - 1][pv] + abs(v - t[i]));
            }
        }
    }

    ll fans = 1e18;

    // dbg(dp[0][4]);
    // dbg(dp[1][5]);
    // dbg(dp[2][6]);
    // dbg(dp[3][7]);
    // dbg(dp[4][8]);

    // dbg(dp[5][9]);
    // dbg(dp[6][10]);


    // dbg(dp[n - 1][10]);


    for (ll v = 1; v < 500; v++) {
        fans = min(fans, dp[n - 1][v]);
    }

    return fans;
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
