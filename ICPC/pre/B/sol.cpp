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
 
auto solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n + 1, -1);

    vector<array<ll,3>> b(k);
    map<ll, vector<pair<ll,ll>>> mp;
    for (ll i = 0; i < k; i++) {
        ll p,q,r;cin>>p>>q>>r;
        b[i] = {p,q,r};
        mp[r].pb({p,q});
    }
    // ll cnt = 0;
    function<void(ll,ll,ll)> dfs = [&] (ll l, ll r, ll m) {
        if (m > n) return;
        dbg(l,r,m);
        // cnt++;
        for (ll i = l; i <= r; i++) { // bad
            a[i] = m;
        }   
        

        for(auto&[p,q]:mp[m]){
            if(p>=l&&q<=r){
                for(ll j=p;j<=q;j++){ // bad
                    a[j] = -1;
                }
            }
        }


        ll s=l,e=-1;
        vector<pair<ll,ll>> vp;
        for (ll i = l; i <= r; i++) {
            if (a[i] > 0) {
                e = i - 1;
                if (s<=e) {
                    vp.pb({s,e});
                }
                s=i+1;
                e=-1;
            } else {
                e=i;
            }
        }
        if(s<=e)
            if(vp.empty() || vp.back()!=make_pair(s,e)){
                vp.pb({s,e});
            }
        dbg(a);
        dbg(vp);
        for(auto&[a,b]:vp) {
            dfs(a,b,m+1);
        }
    };

    dfs(1,n,1);

    for (ll i = 1;  i <= n; i++) {
        if (a[i] == -1) {
            cout << -1 << "\n";
            return;
        }
    }

    for(ll i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }   cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        // auto res = solve();
        // cout << res << "\n";
        solve();
    }
    return 0;
}
