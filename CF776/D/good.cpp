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


// ============

auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> r(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> r[i];
    }

    dbg(r);

    vector<ll> g[m + 1];
    for (ll i = 1; i <= m; i++) {
        ll sz; cin >> sz;
        if (sz == 0) continue;
        g[i] = vector<ll> (sz);
        for (auto& x : g[i])
            cin >> x;
    }

    vector<ll> d[n + 1];
    for (ll i = 1; i <= m; i++) {
        for (auto x : g[i]) {
            d[x].pb(i);
        }
    }
    for (ll i = 1; i <= n; i++) {
        dbg(d[i]);
    }


    vector<vector<ll>> adj(max(n, m) + 1);

    map<pair<ll, ll>, ll> mp;
    for (ll i = 1; i <= n; i++) {
        adj[d[i][0]].pb(d[i][1]);
        adj[d[i][1]].pb(d[i][0]);
        mp[{d[i][1], d[i][0]}] = r[i];
        mp[{d[i][0], d[i][1]}] = r[i];
    }
    vector<bool> seen(max(n, m) + 1, false);
    vector<ll> color(max(n,m)+1, 0);
    function<void(ll,ll)> dfs = [&] (ll i, ll p) {
        seen[i] = true;
        for (auto ch : adj[i]) {
            if (!seen[ch]) {
                if (mp[{ch,i}] == 1) {
                    color[ch] = color[i];
                } else {
                    color[ch] = color[i]^1;
                }
                dfs(ch, i);
            }
        }
    };
    for (ll i = 1; i <= max(n, m); i++) {
        if (!seen[i]) {
            dfs(i,-1ll);
        }
    }

    bool ok = true;

    for (ll i = 1; i <= n; i++) {
        if (r[i] == 1) {
            if (color[d[i][1]] != color[d[i][0]])ok=false;
        }else{
            if (color[d[i][1]] == color[d[i][0]])ok=false;
        }
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
    }
    return 0;
}
