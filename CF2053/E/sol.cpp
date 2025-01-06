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
    vector<ll> adj[n + 1];
    ll leaf = 0;
    vector<bool> isLeaf(n + 1, false);
    for (ll i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (ll i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            isLeaf[i] = true;
            leaf++;
        }
    }
    Vec<bool> leafConn(n + 1, false);
    for (ll i = 1; i <= n; i++) {
        if (isLeaf[i]) continue;
        for (auto v : adj[i]) {
            if (isLeaf[v]) {
                leafConn[i] = true;
            }
        }
    }
    vector<ll> cntNonLeaf(n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        if (leafConn[i]) {
            for (auto& v : adj[i]) {
                if (!isLeaf[v]) {
                    cntNonLeaf[i]++;
                }
            }
        }
    }

    ll fans = leaf * (n - leaf);

    ll p = 0;
    for (ll i = 1; i <= n; i++) {
        if (!leafConn[i] && !isLeaf[i]) {
            p++;
        }
    }
    dbg(p);
    dbg(leafConn);

    ll q = 0;
    dbg(cntNonLeaf);
    for (ll i = 1; i <= n; i++) {
        if (cntNonLeaf[i] >= 2) {
            q += cntNonLeaf[i] - 1;
        }
    }
    dbg(q);
    fans += p * q;
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
