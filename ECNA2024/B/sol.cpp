#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
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

/*
LCA
-> 1 based indexing
-> Binary Lifting
-> Distance Queries On Tree
-> O(log(n))*Q + O(n*log(n)) 
-> 0 as ancestor of root
-> depth of root = 1
*/

const ll L=20;
const ll N=2e5+20;
vector<vector<ll>> adj, up, radj;
ll timer;
vector<ll> tin, tout, depth;
vector<bool> seen;

void dfs(ll v, ll p) {
    seen[v] = true;
    tin[v] = ++timer;
    up[v][0] = p;
    for (ll i = 1; i < L; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for (auto& ch : adj[v]) {
        if (ch != p) {
            dbg(ch, p);
            depth[ch] = depth[v]+1;
            dfs(ch, v);
        }
    }
    tout[v] = ++timer;
}

bool is_ancestor(ll u, ll v) {
    if (u==0) return true;
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (ll i = L - 1; i >=0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

ll dist(ll u, ll v) {
    ll w = lca(u, v);
    return depth[u]+depth[v]-2*depth[w];
}
const ll INF = 1e18;
int main(){

    ll n, m;
    cin >> n >> m;

    vector<ll> pages(n + 1, 0);
    vector<ll> dp(n + 1, 0);

    for (ll i = 1; i <= n; i++) cin >> pages[i];
    

    DSU d(n + 1);

    adj = vector<vector<ll>> (n+1);
    radj = vector<vector<ll>> (n+1);
    up = vector<vector<ll>> (n+1, vector<ll>(L, 0));

    depth = tout = tin = vector<ll> (n+1, 0);
    seen = vector<bool> (n + 1, false);
    timer = 0;

    for (ll i=0;i<m;i++) {
        ll u,v;
        cin>>u>>v;
        d.unite(u, v);
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    for (ll i = 1; i <= n; i++) {
        dp[i] = pages[i];
        for (auto&ch : radj[i]) {
            dp[i] += dp[ch];
        }
    }

    seen[0] = true;

    for (ll i = 1; i <= n; i++) {
        if (seen[i]) continue;
        depth[i] = 1;
        dbg(i);
        dfs(i, 0);

    }

    dbg(tin);
    dbg(tout);
    dbg(dp);

    vector<ll> leaf;
    for (ll i = 1; i <= n; i++) {
        if (adj[i].size() == 0) {
            leaf.push_back(i);
        }
    }

    dbg(leaf);
    ll res = INF;
    for (ll i = 0; i < leaf.size(); i++) {
        for (ll j = i + 1; j < leaf.size(); j++) {
            ll fans = dp[leaf[i]] + dp[leaf[j]];
            if (d.same_set(leaf[i], leaf[j])) {
                ll l = lca(leaf[i], leaf[j]);
                fans -= dp[l];
            }
            res = min(res, fans);
        }
    }

    cout << res << "\n";
}
