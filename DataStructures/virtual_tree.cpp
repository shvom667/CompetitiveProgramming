#include<bits/stdc++.h>
using namespace std;

/*
Virtual Tree
    -> 1 based indexing
    -> if k is the number of vertices selected, then max vertices in virtual tree = 2*k-1
    -> Blog : https://codeforces.com/blog/entry/76955
    -> YT : https://www.youtube.com/watch?v=czySm7bUHgY
*/

/*
    Algortihm:
    P-I
        -> sort v[1], v[2] .... v[k] by dfs_lca order
        -> add lca v[i], v[i+1] to list of vertices
        -> again sort by dfs_lca order
    P-II
        -> maintain a stack and initially it will contain topmost vertex
        -> go thorugh the vertex in order of dfs_lca time and change this stack
*/


#define SZ(x) (ll)x.size()
#define ALL(x) begin(x), end(x)
template <typename T>
void makeUniq(vector<T>& vec) {
    vec.resize(unique(ALL(vec)) - vec.begin());
}
using ll=long long;
const ll L=20;
const ll N=2e5+20;
vector<vector<ll>> adj, up;
ll timer;
vector<ll> tin, tout, depth;

void dfs_lca(ll v, ll p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (ll i = 1; i < L; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for (auto& ch : adj[v]) {
        if (ch != p) {
            depth[ch] = depth[v]+1;
            dfs_lca(ch, v);
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

// list of vertices
vector<ll> v;
ll k;
vector<vector<ll>> adj_vt;
ll virtual_tree() {
    vector<ll> stack_of_vertices;
    stack_of_vertices.push_back(v[0]);

    for (ll i = 1; i < k; i++) {
        ll u = v[i];
        while (stack_of_vertices.size()>=2&& !is_ancestor(stack_of_vertices.back(), u))
        {   
            adj_vt[stack_of_vertices[SZ(stack_of_vertices)-2]].push_back(stack_of_vertices.back());
            stack_of_vertices.pop_back();
        }
        stack_of_vertices.push_back(u);
    }
    while (stack_of_vertices.size()>=2)
    {   
        adj_vt[stack_of_vertices[SZ(stack_of_vertices)-2]].push_back(stack_of_vertices.back());
        stack_of_vertices.pop_back();
    }

    return stack_of_vertices[0];
}

int main(){

    ll n,q;
    cin>>n>>q;
    adj = vector<vector<ll>> (n+1);
    up = vector<vector<ll>> (n+1, vector<ll>(L, 0));
    depth = tout = tin = vector<ll> (n+1, 0);
    timer = 0;
    for (ll i=1;i<n;i++) {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 1;
    dfs_lca(1, 0);

    k = v.size();
    sort(begin(v), end(v), [&] (ll u, ll v) {
        return tin[u] < tin[v];
    });
    
    vector<ll> _lca;
    for (ll i = 1; i < (ll) (v.size()); i++) {
        _lca.push_back(lca(v[i-1], v[i]));
    }

    for (auto& u : _lca) v.push_back(u);

    sort(begin(v), end(v), [&] (ll u, ll v) {
        return tin[u] < tin[v];
    });
    makeUniq(v);

    k = v.size();
    adj_vt = vector<vector<ll>> (k+1);
    // part 1 of the algorithm done upto here

    ll virtual_root = virtual_tree();


}