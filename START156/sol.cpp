#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif
auto solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    vector<ll> depth(n + 1, 0);
    function<void(ll, ll)>dfs=[&](ll i, ll p) {
        for (auto& ch : adj[i]) {
            if (ch != p) {
                depth[ch] = depth[i] + 1;
                dfs(ch, i);
            }
        }
    };
    dfs(1,-1);
    ll max_depth=-1,max_depth_node=-1;
    for (ll i = 1; i <= n; i++) {
        if (depth[i] > max_depth) {
            max_depth = depth[i];
            max_depth_node = i;
        }
    }
    dbg(max_depth_node);

    depth=vector<ll> (n + 1, 0);
    function<void(ll, ll)>dfs1=[&](ll i, ll p) {
        for (auto& ch : adj[i]) {
            if (ch != p) {
                depth[ch] = depth[i] + 1;
                dfs1(ch, i);
            }
        }
    };
    dfs1(max_depth_node,-1);
    ll max_depth2=-1,max_depth2_node=-1;
    for (ll i = 1; i <= n; i++) {
        if (depth[i] > max_depth2) {
            max_depth2 = depth[i];
            max_depth2_node = i;
        }
    }
    dbg(max_depth2_node);
    vector<ll> dia;
    bool found=false;
    function<void(ll, ll)>dfs2=[&](ll i, ll p) {
        dia.pb(i);
        if (i == max_depth2_node) {
            found=true;
        }
        if(found)return;
        for (auto& ch : adj[i]) {
        if(found)return;
            if (ch != p) {
        if(found)return;
                depth[ch] = depth[i] + 1;
        if(found)return;
                dfs2(ch, i);
 
        if(found)return;           }
        }
        if(found)return;
        dia.pop_back();
        if(found)return;
    };
    dfs2(max_depth_node, -1);
    dbg(dia);
    vector<ll> ord;
    function<void(ll, ll)>dfs3=[&](ll i, ll p) {
        ord.pb(i);
        for (auto& ch : adj[i]) {
            if (ch != p) {
                depth[ch] = depth[i] + 1;
                dfs3(ch, i);
            }
        }
    };
    dfs3(max_depth_node, -1);

    vector<bool> seen(n+1,false);

    for(auto&x:dia){
        seen[x]=true;
    }
    vector<ll> res;
    if ((ll)dia.size() <= 3) {
        res.clear(); res.pb(-1);
        return res;
    }

    ll sz = (ll)dia.size();
    for (ll j = (sz + 2) / 2 - 1; j < sz; j++) {
        res.pb(dia[j]);
    }
    for (ll j = (sz + 2) / 2 - 2; j >= 0; j--) {
        res.pb(dia[j]);
    }
    dbg(ord);
    for(auto&x:ord){
        if(seen[x]) continue;
        else res.pb(x);
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        for (auto&x : res) {
            cout << x << " ";
        }   cout << "\n";
        // solve();
    }
    return 0;
}
