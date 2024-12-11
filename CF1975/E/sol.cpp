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
                if (col[ch]) cnt[i]++;
                dfs(ch, i);
            }
        }
    };
    dfs(0, -1);

    vector<ll> cnt_nodes(n + 1, 0);

    for(ll i = 0; i < n; i++) {
        if (col[i] == 0) continue;
        cnt_nodes[cnt[i]] += 1;
    }

    set<ll> black;
    for(ll i = 0; i < n; i++) {
        if (col[i] == 1) {
            black.insert(i);
        }
    }

    dbg(cnt);
    dbg(cnt_nodes);
    dbg(black);

    vector<string>fans; string y="Yes", no="No";
    
    set<pair<ll, ll>> s;

    for(ll i = 0; i < n; i++) {
        if (col[i] == 1)
            s.insert({dep[i], i});
    }

    while (q--) {
        ll u; cin >> u; --u;
        dbg(u);
        dbg(col);
        dbg(cnt);
        if (col[u] == 1) {

            if (par[u] != -1 && col[par[u]] == 1) {
                cnt_nodes[cnt[par[u]]] -= 1;
                cnt_nodes[cnt[par[u]]-1] += 1;
            }

            if (par[u] != -1) {
                cnt[par[u]] -= 1;
            }
                        
            cnt_nodes[cnt[u]]--;

            col[u] = 0;
            s.erase({dep[u],u});
            black.erase(u);
        }
        else {

            if (par[u] != -1 && col[par[u]] == 1) {
                cnt_nodes[cnt[par[u]]] -= 1;
                cnt_nodes[cnt[par[u]]+1] += 1;
            }
            if (par[u] != -1) {
                cnt[par[u]] += 1;
            }
            cnt_nodes[cnt[u]]++;
            col[u] = 1;
            s.insert({dep[u],u});
            black.insert(u);
        }

        dbg(cnt_nodes);
        dbg(black);
        if((ll)black.size() == 0) {
            fans.pb(no);
            continue;
        }
        if ((ll)black.size() == 1) {
            fans.pb(y);
            continue;
        }
        if (cnt_nodes[0] == 1 && cnt_nodes[1] == (ll)black.size() - 1) {
            fans.pb(y);
            continue;
        }
        if (cnt_nodes[0] == 2 && cnt_nodes[2] == 1 && cnt_nodes[1] == (ll)black.size() - 3 && cnt[(*s.begin()).second] == 2) {
            fans.pb(y);
            continue;
        }
        fans.pb(no);
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
        for(auto&x:res){
            cout<<x<<'\n';
        }
    }
    return 0;
}
