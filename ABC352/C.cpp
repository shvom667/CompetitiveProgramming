
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

void solve() {
  ll n;
  cin>>n;
  ll a[n],b[n];
  ll s=0;
  ll f=0;
  for(ll i=0;i<n;i++){
    cin>>a[i]>>b[i];
    s+=a[i];
  }
  for(ll i=0;i<n;i++){
    f=max(f,s-a[i]+b[i]);
  }
  cout<<f<<'\n';
}
