
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
  t=1;
  while (t--) solve();
}
ll ub(ll x,ll y){
  return (x+y-1)/y;
}
void solve() {
  ll n;
  cin>>n;
  Vec<ll> v(n+1), pv(n+1, 0), dp(n+1,0);
  for(ll i=1;i<=n;i++){
    cin>>v[i];
    pv[i]=v[i];
    pv[i]+=pv[i-1];
  }
  ll b=1;
  dp[0]=1e18;
  dp[1] = pv[n];
  for(ll i=2;i<=n;i++){
    dp[i]=ub(pv[n],i);
    if(i*pv[b]<=pv[i]*b){
      b=i;
    }
    dp[i]=max(dp[i],ub(pv[b],b));
  }
  ll q;
  cin>>q;
  while(q--){
    ll t;
    cin>>t;
    ll l=0,r=n;
    while(l<=r){
      ll m=l+(r-l)/2;
      if(dp[m]<=t){
        r=m-1;
      }else{
        l=m+1;
      }
    }
    if(l==n+1){
      cout<<-1<<"\n";
    }else{
      cout<<l<<"\n";
    }
  }
}
