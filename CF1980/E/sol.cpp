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
using pl=pair<ll,ll>;
auto solve() {
    ll n, m;
    cin >> n >> m;
    
    ll g[n][m],f[n][m];
    map<ll,ll>ri,rf,ci,cf;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>g[i][j];
            ri[g[i][j]]=i;
            ci[g[i][j]]=j;
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>f[i][j];

        }
    }
    bool ok=true;
    for(ll i=0;i<n;i++){
        for(ll j=1;j<m;j++){
            if(ri[f[i][j]] != ri[f[i][j-1]])ok=false;
        }
    }
    for(ll j=0;j<m;j++){
        for(ll i=1;i<n;i++){
            if(ci[f[i][j]] != ci[f[i-1][j]])ok=false;
        }
    }
    
    if(ok)return "Yes";
    return "No";
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
