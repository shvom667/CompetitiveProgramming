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
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<ll>> adj(n), dp(n, vector<ll> (2, 0));
    for (ll i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    function<void(ll, ll)> dfs = [&] (ll i, ll p) {

        for (auto&ch : adj[i]) {
            if (ch == p) continue;

            dfs(ch, i);
            dp[i][0] += max(dp[ch][0], dp[ch][1]);
            dp[i][1] += max(dp[ch][0], dp[ch][1] - 2 * c);

        }
        dp[i][1] += a[i];
    };

    dfs(0, -1);

    return max(dp[0][0], dp[0][1]);
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
