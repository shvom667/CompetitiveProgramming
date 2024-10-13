#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;


auto solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll a[n];
    for (ll i = 0; i < n; i++) cin>>a[i];
    ll l,r;
    l=1,r=1e10;
    while(l<=r){
        ll mid=l+(r-l)/2;
        ll rqd=1;
        ll sum=0;
        for(ll i=0;i<n;i++){
            if(rqd>m)break;
            if(sum+a[i]<=k*mid){
                sum+=a[i];
            }else{
                sum=a[i];
                if(a[i]>mid*k){
                    rqd=m+1;
                    break;
                }
                rqd++;
            }
        }
        if(rqd<=m){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<l<<'\n';
}

int main() {
    ll T;
    T=1;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
        
    }
    return 0;
}
