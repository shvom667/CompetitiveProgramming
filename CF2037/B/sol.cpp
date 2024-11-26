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
    ll k; cin >> k; ll a[k];
    for (ll i = 0; i < k; i++)cin>>a[i];
    map<ll,ll>mp;
    for(ll i=0;i<k;i++)mp[a[i]]++;

    for(ll i=0;i<k;i++){
        if(mp[a[i]]>=2 && k-2==a[i]*a[i]){
            return make_pair(a[i],a[i]);
        }
    }
    for(ll i=0;i<k;i++){
        if((k-2)%a[i]==0){
            ll b=(k-2)/a[i];
            if(b!=a[i] && mp[b] >= 1){
                return make_pair(a[i],b);
            }
        }
    }
    return make_pair(0ll,0ll);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout<<res.first<<" "<<res.second<<'\n';
    }
    return 0;
}
