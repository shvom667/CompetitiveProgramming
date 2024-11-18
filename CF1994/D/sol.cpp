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

auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<pair<ll,ll>> edges;

    for (ll i = 0; i < n; i++) cin >> a[i];

    DSU d(n);

    for (ll op = n - 1; op >= 1; op--) {
        set<ll> nodes;
        for (ll i = 0; i < n; i++) nodes.insert(d.get(i));
        assert((ll)nodes.size() == op + 1);
        vector<vector<ll>> adj(op);
        for (auto&x:nodes) {
            adj[a[x]%op].pb(x);
            if((ll)adj[a[x]%op].size() == 2ll) {
                edges.push_back({adj[a[x]%op][0],adj[a[x]%op][1]});
                d.unite(adj[a[x]%op][0], adj[a[x]%op][1]);
                break;
            }

        }
    }
    reverse(begin(edges),end(edges));
    cout << "YES\n";
    for (auto&[u,v]:edges){
        cout << u + 1 << " " << v + 1 << "\n";
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
    }
    return 0;
}
