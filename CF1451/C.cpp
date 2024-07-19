
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
  string a,b;
  cin>>n>>k>>a>>b;
  Vec<ll> fa(26,0), fb(26,0);
  for(ll i=0; i<n; i++){
    fa[a[i]-'a']++;
    fb[b[i]-'a']++;
  }
  ll p=0;
  bool ok=true;
  for (ll i=25;i>=0;i--){
    ll cur=fb[i]-fa[i];
    if(cur%k!=0)ok=false;
    p += cur;
    if(p<0) ok=false;
  }
  if(ok){
    cout<<"YES\n";
  }else{
    cout<<"NO\n";
  }
}
