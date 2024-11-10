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
const ll INF = 1e18;
struct p4
{
    ll max1, max2, min1, min2;
    /* data */
};

void print(p4 p) {
    cout << p.min1 << " " << p.min2 << " " << p.max2 << " " << p.max1 << "\n";
}


p4 new_p4() {
    p4 p;
    p.max1 = -INF;
    p.min1 = INF;
    p.min2 = INF;
    p.max2 = -INF;
    return p;
}

p4 update_p4(p4 p, ll u) {

    
    p.max2 = max(p.max2, u);
    p.min2 = min(p.min2, u);

    if (p.max2 > p.max1) {
        swap(p.max1, p.max2);
    }
    if (p.min2 < p.min1) {
        swap(p.min1, p.min2);
    }
    return p;
}
p4 update_p4(p4 p, p4 q) {
    // dbg("$$$$$$$$$$$$$$$$$$");
    // print(p);
    // print(q);
    p.max2 = max(p.max2, q.max2);
    if (p.max2 > p.max1) {
        swap(p.max2, p.max1);
    }
    p.max2 = max(p.max2, q.max1);
    if (p.max2 > p.max1) {
        swap(p.max2, p.max1);
    }

    p.min2 = min(p.min2, q.min2);
    if (p.min2 < p.min1) {
        swap(p.min1, p.min2);
    }

    p.min2 = min(p.min2, q.min1);
    if (p.min2 < p.min1) {
        swap(p.min1, p.min2);
    }
    // print(p);
    // dbg("$$$$$$$$$$$$$$$$$$");
    return p;
}

/*
LCA
-> 1 based indexing
-> Binary Lifting
-> Distance Queries On Tree
-> O(log(n))*Q + O(n*log(n)) 
-> 0 as ancestor of root
-> depth of root = 1
*/

using ll=long long;
const ll L=20;
const ll N=2e5+20;
const ll M = 2;
vector<vector<ll>> adj, up;
ll timer;
vector<ll> tin, tout, depth, parent, sq_up;

void dfs(ll v, ll p) {
    tin[v] = ++timer;
    parent[v] = p;
    up[v][0] = p;
    for (ll i = 1; i < L; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for (auto& ch : adj[v]) {
        if (ch != p) {
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

vector<p4> sq_up_p4;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);  

    ll n; cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) cin >> a[i];

    adj = vector<vector<ll>> (n+1);
    up = vector<vector<ll>> (n+1, vector<ll>(L, 0));
    depth = tout = tin = parent = sq_up =  vector<ll> (n+1, 0);
    timer = 0;


    for (ll i=1;i<n;i++) {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 1;
    dfs(1, 0);

    dbg(depth);

    sq_up_p4 = vector<p4> (n + 1);
    for (ll i = 1; i <= n; i++) {
        p4 p = new_p4();
        ll cur_node = i;
        for (ll l = 1; l <= min(depth[i], M); l++) {
            dbg(i, cur_node);
            p = update_p4(p, a[cur_node]);
            sq_up[i] = cur_node;
            cur_node = parent[cur_node];
        }
        sq_up_p4[i] = p;
    }

    
    for (ll i = 1; i <= n; ++i) {
        dbg(i);
        print(sq_up_p4[i]);
    }

    dbg(sq_up);

    auto travel_lca = [&] (ll ch, ll ancestor) {

        assert(lca(ch, ancestor) == ancestor);
        p4 p = new_p4();

        while (depth[ch] - depth[ancestor] + 1 >= M) {
            
            p = update_p4(p, sq_up_p4[ch]);
            ch = parent[sq_up[ch]];

            if (ch == 0) break;
        }
        dbg(ch);
        while (depth[ch] >= depth[ancestor]) {
            p = update_p4(p, a[ch]);
            ch = parent[ch];
        }
        return p;
    };  
    
    p4 res = travel_lca(6, 1);
    print(res);


    auto travel_path = [&] (ll x, ll y) {
        ll cn = lca(x, y);
        p4 p = travel_lca(x, cn);
        p4 q = travel_lca(y, cn);
        p = update_p4(p, q);
        return p;
    };

    ll q;
    cin >> q;
    while (q--) {
        ll l, r, x;
        cin >> l >> r >> x;

        p4 res = travel_path(l, r);

        print(res);
        ll fans = 0;
        fans = max(fans, res.max1 - res.min1);
        fans = max(fans, res.max1 + res.max2 - 2 * x);
        fans = max(fans, 2 * x - res.min1 - res.min2);
        cout << fans << "\n";
    }
}

