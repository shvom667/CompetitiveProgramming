
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
template <typename T>
using Vec = vector<T>;
using ll = long long;
void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--) solve();
}

void solve() {
    ll n;
    cin>>n;
    Vec<ll>a(n+1);
    ll sum=0;
    for(ll i=1;i<=n;i++){
      cin>>a[i];
      sum+=a[i];
    }
    ll res=0;
    ll f=a[1];
    for(ll i=2;i<=n;i++){
      ll diff=abs(a[i]-a[i-1]);
      res+=abs(a[i]-a[i-1]);
      if(a[i-1]>a[i]){
        f -= diff;
      }else{
      }
    }
    cout<<res+abs(f)<<'\n';
}
