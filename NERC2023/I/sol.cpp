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
ll ask(ll i,ll j){
    cout<<i<<" "<<j<<endl;
    ll res;cin>>res;return res;
}
auto solve() {
    ll n;cin>>n;ll k;cin>>k;
    if(k==n){
        return;
    }
    for(ll i=1;i<=n;i++){
        ll pm=0;
        ll bm=0;
        ll pans=k;
        ll last_mask=-1;
        for(ll m=1;m<(1ll<<(n-i+1));m++){
            ll mask=m^(m >> 1);
            dbg(mask,pm);
            last_mask=mask;
            for(ll bit=0;bit<n-i+1;bit++){
                if ((mask&(1<<bit)) != (pm&(1<<bit))){
                    ll cur_res=ask(i,i+bit);
                    if(cur_res>k){
                        k=cur_res;
                        bm=mask;
                    }
                    pm=mask;
                }
            }
        }
        dbg(bm,k);
        for(ll bit=0;bit<n-i+1;bit++){
            if(last_mask&(1<<bit)){
                ask(i,i+bit);
            }
        }
        ll nk=-1;
        for(ll bit=0;bit<n-i+1;bit++){
            if(bm&(1<<bit)){
               nk=ask(i,i+bit); 
            }
        }
        if(nk==-1)nk=k;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T=1;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
    }
    return 0;
}
