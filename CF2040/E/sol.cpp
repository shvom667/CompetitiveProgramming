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
    ll n,q;cin>>n>>q;

    vector<ll>f(n,0);
    vector<vector<ll>> adj(n);

    for(ll i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    Vec<ll>cntch(n,0), dep(n, 0);
    Vec<ll>par(n,-1);

    function<void(ll,ll)> dfs2 = [&] (ll i, ll p) {

        for(auto&ch: adj[i]) {
            if (ch == p) continue;
            cntch[i]++;
            dep[ch]  = dep[i] + 1;
            dfs2(ch, i);
            
        }
        
    };



    dfs2(0,-1);


    function<void(ll,ll)> dfs1 = [&] (ll i, ll p) {

        for(auto&ch: adj[i]) {
            if (ch == p) continue;
            if (p != -1)
                f[ch] = f[p] + 2 * cntch[ch] + 2;
            else {
                f[ch] = 2 * cntch[ch] + 1;
            }
            par[ch] = i;
            dfs1(ch, i);
            
        }
        
    };

    dfs1(0,-1);

    dbg(f);

    Vec<ll>fans;

    while (q--) {
        ll v, p;
        cin >> v >> p;
        p *= 2;
        dbg(p);
        --v;
        if(p>=dep[v]){
            fans.pb(dep[v]);
        }
        else {
            ll cnt = 0;
            ll res = 0;
            dbg(p);
            while(p) {
                v = par[v];
                p--;
                res++;
                cnt++;
            }
            assert(p==0);

            ll p = par[v];
            dbg(v, p, res+1+f[p]);

            if (p == -1) {
                fans.pb(res+1);
            }else{
                fans.pb(res+1+f[p]);
            }

            // if(cnt&1) {//start from even
            //     ll res;
            //     res = f[v];
            //     fans.pb(res);
            //     assert(false);
            // }else{//start from odd
            //     ll res;
            //     ll p = par[v];
            //     if (p == -1) {
            //         fans.pb(1);
            //     }else{
            //         fans.pb(1+f[p]);
            //     }
            // }
        } 
    }

    for(auto&x:fans){
        cout<<x<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    // auto res = solve();
	    // cout << res << "\n";
        solve();
    }
    return 0;
}
