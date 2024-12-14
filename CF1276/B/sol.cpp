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
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<vector<ll>> adj(n + 1), adj_a(n + 1), adj_b(n + 1);

    for (ll i = 1; i <= m; i++) {
        ll x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);

        if (x != b && y != b) {
            adj_a[x].pb(y);adj_a[y].pb(x);
        } 
        if (x != a && y != a) {
            adj_b[x].pb(y),adj_b[y].pb(x);
        }
    }

    vector<ll> cnt_a(n + 1 , 0),cnt_b(n+1,0);
    Vec<bool> sa(n + 1, false), sb(n + 1, false);

    function<void(ll, ll)> dfs_a = [&] (ll i, ll p) {
        sa[i] = true;
        dbg(i,p);
        cnt_a[i]++;
        for (auto&ch : adj_a[i]){
            if (sa[ch]) continue;
            if(ch == p) continue;
            dfs_a(ch, i);
        }
    };


    function<void(ll, ll)> dfs_b = [&] (ll i, ll p) {
        dbg(i,p);
        cnt_b[i]++;
        sb[i] = true;
        for (auto&ch : adj_b[i]){
            if (sb[ch]) continue;
            if(ch == p) continue;
            dfs_b(ch, i);
        }
    };

    dbg(a, b);

    dfs_a(a, 0);
    dfs_b(b, 0);


    ll va, vb; va = vb = 0;
    for(ll i=1;i<=n;i++){
        if(cnt_a[i] == 1 && cnt_b[i] == 1) {
            continue;
        }
        va += cnt_a[i];
        vb += cnt_b[i];
    }

    dbg(va, vb);

    dbg(cnt_a);
    dbg(cnt_b);
    
    return (va - 1) * (vb - 1);
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
