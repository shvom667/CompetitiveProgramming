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
const string Y="Yes";
const string N="No";

auto solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> col(n, 0);
    for(ll i = 0; i < n; i++) {
        cin >> col[i];
    }
    vector<vector<ll>> adj(n);
    for(ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    vector<ll> par(n, -1);
    Vec<ll> cnt(n, 0);
    vector<ll> dep(n, 0);
    function<void(ll,ll)>dfs=[&](ll i, ll p){
        par[i] = p;
        for(auto&ch : adj[i]) {
            if (ch != p) {
                dep[ch] = dep[i] + 1;
                if (col[i] == 1 && col[ch]) cnt[i]++;
                dfs(ch, i);
            }
        }
    };
    dfs(0, -1);

    set<ll> black;
    set<ll> dfs_path;
    Vec<Vec<ll>> cur_adj(n);

    bool ok=false;

    function<void(ll, ll)> dfs2 = [&] (ll i, ll p) {
        dfs_path.insert(i);
        if (dfs_path == black) ok = true;
        for(auto&ch: cur_adj[i]) {
            if (ch == p) continue;
            dfs2(ch, i);
        }
        dfs_path.erase(i);
    };
    Vec<string>fans;

    dbg(col);

    dbg(adj);

    dbg(adj[0]);

    while(q--) {

        dbg(q);
        ll x; cin >> x; --x;

        col[x] ^= 1;

        black.clear();
        cur_adj = vector<vector<ll>> (n);

        for(ll i = 0; i < n; i++) {
            if (col[i] == 1) black.insert(i);
        }

        if ((ll)black.size() == 0) {
            fans.pb(N);
            continue;
        }
        if((ll)black.size() == 1) {
            fans.pb(Y);
            continue;
        }
        dbg(col);
        
        for(ll y = 0; y < n; y++) {
            dbg(y, adj[y].size());
            for (ll j = 0; j < (ll)adj[y].size(); j++) {
                if (col[y] == 1 && col[adj[y][j]] == 1) {
                    cur_adj[y].pb(adj[y][j]);
                    cur_adj[adj[y][j]].pb(y);
                }
            }
        }
        dbg(cur_adj);
        for(ll i=0;i<n;i++){
            if(col[i]==1){
                ok=false;
                dfs_path.clear();
                dfs2(i,-1);
                if (ok) {
                    fans.pb(Y);
                    break;
                }
            }
        }
        if (!ok) {
            fans.pb(N);
        }
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
        for (auto&x: res) {
            cout << x << '\n';
        }
    }
    return 0;
}
