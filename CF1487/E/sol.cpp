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
const ll inf = 1e9;
auto solve() {
    ll n1, n2, n3, n4;
    cin >> n1  >> n2 >> n3 >> n4;

    Vec<ll> a(n1), b(n2), c(n3), d(n4);

    for (auto& x: a) cin >> x;
    for (auto& x: b) cin >> x;
    for (auto& x: c) cin >> x;
    for (auto& x: d) cin >> x;
    
    vector<vector<ll>> adj1(n2), adj2(n2), adj3(n3);
    set<pair<ll, ll>> set1, set2, set3; 
    ll m1;cin>>m1;
    for(ll i=0;i<m1;i++){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        adj1[v].pb(u);
        set1.insert({v,u});
    }
    ll m2;cin>>m2;
    for(ll i=0;i<m2;i++){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        adj2[u].pb(v);
        set2.insert({u,v});
    }

    ll m3;cin>>m3;
    for(ll i=0;i<m3;i++){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        adj3[u].pb(v);
        set3.insert({u,v});
    }

    // n2 and n1
    vector<ll> nb(n2, 0);
    if (true) {
        vector<ll> I(n1, 0); for(ll i=0;i<n1;i++)I[i] = i;
        sort(begin(I),end(I),[&](auto x, auto y) {
            return a[x] < a[y];
        });
        for (ll i = 0; i < n2; i++) {
            ll fans = inf;
            for (ll j=0;j<n1;j++){
                if (set1.find({i,I[j]}) == set1.end()){
                    fans = min(fans, b[i] + a[I[j]]);
                    break;
                }
            }
            nb[i] = fans;
        }
    }
    vector<ll> nc(n3, 0);
    if (true) {
        vector<ll> I(n4, 0); for(ll i=0;i<n4;i++)I[i] = i;
        sort(begin(I),end(I),[&](auto x, auto y) {
            return d[x] < d[y];
        });
        for (ll i = 0; i < n3; i++) {
            ll fans = inf;
            for (ll j=0;j<n4;j++){
                if (set3.find({i,I[j]}) == set3.end()){
                    fans = min(fans, c[i] + d[I[j]]);
                    break;
                }
            }
            nc[i] = fans;
        }
    }

    vector<ll> fa(n2);
    if (true) {
        vector<ll> I(n3, 0); for(ll i=0;i<n3;i++)I[i] = i;
        sort(begin(I),end(I),[&](auto x, auto y) {
            return nc[x] < nc[y];
        });
        for (ll i = 0; i < n2; i++) {
            ll fans = inf;
            for (ll j=0;j<n3;j++){
                if (set2.find({i,I[j]}) == set2.end()){
                    fans = min(fans, nb[i] + nc[I[j]]);
                    break;
                }
            }
            fa[i] = fans;
        }
    }
    dbg(nb);
    dbg(nc);
    dbg(fa);
    ll res = *min_element(begin(fa), end(fa));
    if (res < inf) {
        return res;
    }
    return -1ll;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
