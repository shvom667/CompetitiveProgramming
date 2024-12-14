#include <bits/stdc++.h>
using namespace std;
using ll = int;
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
    ll n,k;cin>>n>>k;
    vector<vector<pair<ll, ll>>> adj(n);
    // map<pair<ll,ll>, ll> wt;

    for(ll i=1;i<n;i++){
        ll u,v,w;cin>>u>>v>>w;--u;--v;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        // wt[{u,v}]=w;
        // wt[{v,u}]=w;
    }

    dbg(adj);
    Vec<vector<long long>> dp(n, vector<long long> (2, 0));

    Vec<bool> used(n, false);
    vector<ll> weight(n, 0);

    function<void(ll, ll)> dfs = [&] (ll i, ll p) {

        vector<ll> cand;
        long long fixed = 0;

        for (auto&[ch, wt] : adj[i]) {
            if (ch == p) continue;
            dfs(ch, i);
            weight[ch] = wt;
            if (dp[ch][0] + wt > dp[ch][1]){
                cand.pb(ch);
            } else {
                fixed += dp[ch][1];
            }
        }

        sort(begin(cand),end(cand),[&] (auto x, auto y) {
            return dp[x][0] + weight[x] - dp[x][1] > dp[y][0] + weight[y] - dp[y][1];
        });


        dp[i][0] = dp[i][1] = fixed;

        for (ll j  = 0; j < min(k - 1, (ll)cand.size()); j++) {
            used[cand[j]] = true;
            dp[i][0] += dp[cand[j]][0] + weight[cand[j]];
        }
        for (auto x : cand) {
            if (!used[x]) dp[i][0] += dp[x][1];
            used[x] = false;
        }

        for (ll j  = 0; j < min(k, (ll)cand.size()); j++) {
            used[cand[j]] = true;
            dp[i][1] += dp[cand[j]][0] + weight[cand[j]];
        }
        for (auto x : cand) {
            if (!used[x]) dp[i][1] += dp[x][1];
            used[x] = false;
        }
    };


    dfs(0, -1);


    cout << max(dp[0][0], dp[0][1]) << '\n';

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
