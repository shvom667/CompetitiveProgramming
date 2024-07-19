
/*
  And all I am is a man
  I want the world in my hands
  I hate the beach
  But I stand in California with my toes in the sand
  Use the sleeves of my sweater
  Let's have an adventure
  Head in the clouds but my gravity centered
  Touch my neck and I'll touch yours
  You in those little high waisted shorts, oh
*/

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
  ll n;
  cin >> n;
  ll p[n+1];
  map<ll,ll>mp;
  for (ll i=1;i<=n;i++){
    cin>>p[i];
    mp[p[i]]=i;
  }
  bool ok=true;
  for(ll i=2;i<n;i+=2){
    if (p[i]==1)
      ok=false;
  }
  Vec<ll> res(n+1,-1);
  if (ok) {
    Vec<ll>val;
    Vec<ll>seen;
    for(ll i=2;i<n;i+=2){
      val.pb(p[i]);
      seen.pb(i);
    }
    sort(begin(val),end(val));
    ll B=n;
    for(auto&x:val){
      res[mp[x]] = B--;
    }
    Vec<ll>rem;
    for(ll i=1;i<=n;i++){
      if(!binary_search(begin(seen),end(seen),i))
        rem.pb(i);
    }
    val.clear();
    for(auto&i:rem){
      val.pb(p[i]);
    }
    sort(begin(val),end(val));
    for(auto&x:val){
      res[mp[x]]=B--;
    }
  }
  else{
    Vec<ll>val;
    Vec<ll>seen;
    for(ll i=3;i<n;i+=2){
      val.pb(p[i]);
      seen.pb(i);
    }
    sort(begin(val),end(val));
    ll B=n;
    for(auto&x:val){
      res[mp[x]] = B--;
    }
    Vec<ll>rem;
    for(ll i=1;i<=n;i++){
      if(!binary_search(begin(seen),end(seen),i))
        rem.pb(i);
    }
    val.clear();
    for(auto&i:rem){
      val.pb(p[i]);
    }
    sort(begin(val),end(val));
    for(auto&x:val){
      res[mp[x]]=B--;
    }
  }
  for(ll i=1;i<=n;i++)
    cout<<res[i]<<" ";
  cout<<'\n';
}
