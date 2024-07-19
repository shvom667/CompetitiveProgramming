
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
  ll n, q;
  cin>>n>>q;
  string s;
  cin>>s;
  ll f0=-1,f1=-1,l0=-1,l1=-1;
  for(ll i=0;i<n;i++){
    if (s[i]-'0' == 0) l0 = i;
    if (s[i]-'0' == 1) l1 = i;
    if (s[i]-'0' == 0 && f0 == -1) f0 = i;
    if (s[i]-'0' == 1 && f1 == -1) f1 = i;
  }
  ll f[2], l[2];
  f[0] = f0, f[1] = f1;
  l[0] = l0, l[1] = l1;
  if (f[0] == -1) f[0] = 1e9;
  if (f[1] == -1) f[1] = 1e9;
  while (q--) {
    ll a, b;
    cin >> a >> b;
    --a;--b;
    if (f[s[a]-'0'] < a || l[s[b]-'0'] > b) {
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }
}
