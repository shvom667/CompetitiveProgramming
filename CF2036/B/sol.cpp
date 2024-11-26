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
    ll n,k,fans=0;cin>>n>>k;
    map<ll,ll>mp;
    for(ll i=0;i<k;i++){
        ll b,c;cin>>b>>c;
        mp[b]+=c;
    }
    vector<ll>v;
    for(auto&[x,y]:mp){
        v.pb(y);
    }
    sort(begin(v),end(v),greater<ll>());
    for(ll i=0;i<min(n,(ll)v.size());i++){
        fans+=v[i];
    }
    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
