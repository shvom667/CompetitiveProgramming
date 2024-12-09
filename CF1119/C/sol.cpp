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
    ll n, m;cin>>n>>m;ll g[n][m];
    for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)cin>>g[i][j];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ll x;cin>>x;g[i][j]^=x;
        }
    }
    map<ll,ll>r,c;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++){
            if(g[i][j]==1){
                r[i]++;
                c[j]++;
            }
        }
    }
    for(auto&[x,y]:r){
        if(y&1){
            return "No";
        }
    }
    for(auto&[x,y]:c){
        if(y&1){
            return "No";
        }
    }
    return "Yes";
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
