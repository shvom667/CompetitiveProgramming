
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--) solve();
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for(ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    ll fans=1e18;
    for (ll m=1;m<=3000;m++){
        ll gm=-1;
        bool ok=true;
        for (ll i=0;i<n;i++){
            ll l=1,r=k;
            while(l<=r){
                ll mid=l+(r-l)/2;
                bool cond = a[i]/mid>=m;
                if(cond){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            if (r<=0){
                ok=false;
            }
            if (r>0 && a[i]/r<m){
                ok=false;
            }
            if(r>0 && a[i]/r>=m){
                gm=max(gm,a[i]/r);
            }
        }
        if(ok){
            fans=min(fans,gm-m);
        }
    }
    cout<<fans<<'\n';
}
