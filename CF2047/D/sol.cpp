#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

auto solve() {
  ll n;cin>>n; ll a[n];for(ll i=0;i<n;i++)cin>>a[i];
  ll L=1,R=1e9+1;
  auto cond=[&](ll m){
    vector<ll>x;
    for(ll i=0;i<n;i++){
      if(a[i]<m){
        x.pb(a[i]);
      }
    }
    if(x.empty())return true;
    
    for(ll i=1;i<x.size();i++){
      if(x[i]<x[i-1]){
        return false;
      }
    }
    return true;
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
  vector<ll>fans;
  ll last=-1;
  for(ll i=0;i<n;i++){
    if(a[i]<R){
      fans.pb(a[i]);
      last=i;
    }
  }
  vector<ll> res;
  dbg(fans);
  dbg(last);
  for(ll j=0;j<last;j++){
    if(a[j]>=R)
      res.pb(a[j]+1);
  }
  dbg(res);
  ll ml=R+1;
  vector<ll>fp;
  for(ll i=n-1;i>last;i--){
    if(a[i]>ml){
      res.pb(a[i]+1);
    }
    if(a[i]==ml){
      fp.pb(a[i]);
    }
    if(a[i]<ml){
      ml=a[i];
      fp.pb(a[i]);
    }
  }
  while(!fp.empty()){
    fans.pb(fp.back());fp.pop_back();
  }
  // for(ll j=last+1;j<n;j++){
  //   if(a[j]==R+1){
  //     fans.pb(R+1);
  //   }else{
  //     res.pb(a[j]+1);
  //   }
  // }
  sort(begin(res),end(res));
  for(auto&x:res)fans.pb(x);
  return fans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  for (ll tc = 1; tc <= T; tc++) {
    auto res = solve();
    for(auto&x:res){
      cout<<x<<" ";
    } cout<<'\n';
  }
  return 0;
}
