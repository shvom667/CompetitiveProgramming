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
    ll n,k,q;cin>>n>>k>>q;vector<ll>fans;
    vector<vector<ll>> a(n, vector<ll>(k));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<k;j++){
            cin>>a[i][j];
        }
    }
    for(ll j=0;j<k;j++){
        for(ll i=1;i<n;i++){
            a[i][j] |= a[i-1][j];
        }
    }
    //     for(ll i=0;i<n;i++){
    // for(ll j=0;j<k;j++){
    //         cout<<a[i][j]<<" ";
    //     }cout<<'\n';
    // }
    while (q--) {
        bool ok=true;
        ll m;cin>>m;
        ll bl=0,bu=1e9;
        while(m--) {
            ll r,c;char o;
            cin >> r >> o >> c;r--;
            if (o == '>') {
                ll L,R; L=0,R=n-1;
                auto cond=[&](ll mid){
                    return a[mid][r]>c;
                };
                while(L<=R){
                    ll mid=L+(R-L)/2;
                    if(cond(mid)){
                        R=mid-1;
                    }else{
                        L=mid+1;
                    }
                }
                dbg(L);
                if(!(L>=0&&L<n))ok=false;
                bl = max(bl, L);
            }else {
                ll L,R; L=0,R=n-1;
                auto cond=[&](ll mid){
                    return a[mid][r]<c;
                };
                while(L<=R){
                    ll mid=L+(R-L)/2;
                    if(cond(mid)){
                        L=mid+1;
                    }else{
                        R=mid-1;
                    }
                }
                dbg(R);
                if(!(R>=0&&R<n))ok=false;
                bu = min(bu, R);

            }
        }      
        dbg(bl,bu); 
        if (!ok){
            fans.pb(-2);
        }
        else{
            if(bl>bu){
                fans.pb(-2);
            }else{
                
                fans.pb((bl<0?0:bl));
            }
        }
    }
    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T=1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        // cout << res << "\n";
        for(auto&x:res){
            cout<<x+1<<'\n';
        }
    }
    return 0;
}
