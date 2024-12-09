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
const ll INF = 1e18;
auto solve() {
    ll n;
    cin >> n;
    vector<Vec<ll>> adj(n);

    for(ll i = 1; i < n; i++) {
        ll u, v;
        cin >> u >>v;
        dbg(u,v);
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dbg(adj);
    ll val=2;
    Vec<ll>f(n,0);
    Vec<ll> inc(n,0);
    function<void(ll,ll)> dfs = [&] (ll i, ll p) {
        f[i] = val;
        val+=2;
        ll mc=INF;
        ll mi=-1;
        for(auto&ch: adj[i]) {
            if (ch == p) continue;
            dfs(ch, i);
            mc = min(mc, f[ch]);
            if (mc == f[ch]) {
                mi = ch;
            }
        }
        if(mc!=INF && mc - f[i] == 2) {
            inc[mi] += -1;
            dbg(i);
        }
    };

    dfs(0,-1);
    

    function<void(ll,ll)> dfs2 = [&] (ll i, ll p) {

        for(auto&ch: adj[i]) {
            if (ch == p) continue;
            inc[ch] += inc[i];
            f[ch] += inc[ch];
            dfs2(ch, i);
            
        }
        
    };

    dfs2(0,-1);

    // dbg(f);
    // dbg(inc);

    for(auto&x:f){
        cout<<x<<" ";
    }   cout<<'\n';
    // return 0;
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
	    // auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
