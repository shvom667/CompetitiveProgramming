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


// ============

struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }
    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool same_set(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

// ============


auto solve() {
    ll n, m;
    cin >> n >> m;
    ll n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<vector<ll>> adj(n + 1, vector<ll> ());
    vector<pair<ll, ll>> edges;

    for (ll i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        edges.pb({u,v});
    }

    vector<bool> seen(n + 1, false);
    vector<ll> color(n + 1, 0);
    function<void(ll)> dfs = [&] (ll i) {
        seen[i] = true;
        for (auto& ch : adj[i]) {
            if (!seen[ch]) {
                color[ch] = color[i] ^ 1;
                dfs(ch);
            }
        }
    };

    for (ll i = 1; i <= n; i++) {
        if (!seen[i]) {
            dfs(i);
        }
    }

    for (auto&[u,v]:edges) {
        if (color[u] == color[v]) {
            cout << "NO\n";
            return 0;
        }
    }

    DSU d(n + 1);

    for (auto& [u, v]: edges) {
        d.unite(u,v);
    }

    map<ll, pair<ll, ll>> mp;

    map<ll, vector<ll>> nodes;

    for (ll i = 1; i <= n; i++) {
        if (mp.find(d.get(i)) == mp.end()) {
            mp[d.get(i)] = {0,0};
        }
        if (color[i] == 0) {
            mp[d.get(i)].first++;
        } else {
            mp[d.get(i)].second++;
        }
        nodes[d.get(i)].push_back(i);
    }

    dbg(mp);

    vector<pair<ll, ll>> vp;
    vector<ll> p;

    for (auto&[u,v]: mp) {
        p.pb(u);
        vp.pb(v);
    }

    dbg(p);
    dbg(vp);

    ll sz = (ll)vp.size();

    bool dp[sz][n+1][2];
    for(ll i = 0; i < sz; i++) {
        for (ll j = 0; j <= n; j++) {
            for (ll k = 0; k < 2; k++) {
                dp[i][j][k] = false;
            }
        }
    }

    dp[0][vp[0].first][0] = true;
    dp[0][vp[0].second][1] = true;


    for(ll i = 1; i < sz; i++) {
        for (ll j = 0; j <= n; j++) {
            if (j - vp[i].first >= 0) {
                dp[i][j][0] |= dp[i - 1][j - vp[i].first][1];
                dp[i][j][0] |= dp[i - 1][j - vp[i].first][0];
            }
            if (j - vp[i].second >= 0) {
                dp[i][j][1] |= dp[i - 1][j - vp[i].second][1];
                dp[i][j][1] |= dp[i - 1][j - vp[i].second][0];
            }
        }
    }


    if (dp[sz - 1][n2][0] || dp[sz - 1][n2][1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        return 0;
    }

    vector<ll> n2p;
    ll cn2 = n2;
    for (ll i = sz - 1; i >= 0; i--) {
        if (dp[i][n2][0]) {
            n2p.pb(vp[i].first);
            n2 -= vp[i].first;
        }else{
            n2p.pb(vp[i].second);
            n2 -= vp[i].second;
        }
    }

    reverse(begin(n2p),end(n2p));

    dbg(nodes);

    dbg(n2p);
    n2 = cn2;

    vector<ll> final_color(n+1,0);

    for (ll i = 0; i < (ll)n2p.size(); i++) {
        vector<ll> c0, c1;
        for(auto&x: nodes[p[i]]) {
            // dbg(x);
            if (color[x] == 0) c0.pb(x);
            else c1.pb(x);
        }
        if ((ll)c0.size() == n2p[i]) {
            for (auto& x : c0) {
                final_color[x] = 1;
            }
        } else {
            for (auto& x : c1) {
                final_color[x] = 1;
            }
        }
    }

    dbg(final_color);

    for (ll i = 1; i <= n; i++) {
        if (final_color[i] == 1) {
            final_color[i] = 2;
        } else {
            if (n1 > 0) {
                n1--;
                final_color[i] = 1;
            } else {
                n3--;
                final_color[i] = 3;
            }
        }
    }

    for(ll i = 1; i <= n; i++) {
        cout << final_color[i];
    }   cout << '\n';

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
