
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
  ll n,k;
  cin>>n>>k;
  ll p[n+1];
  ll I[n+1];
  for (ll i=1;i<=n;i++) {
    cin>>p[i];
    I[p[i]]=i;
  }
  set<ll>s;
  for (ll i = 1; i <= k; i++)
    s.insert(I[i]);
  ll f=*s.rbegin()-*s.begin();
  for (ll i=k+1;i<=n;i++){
    s.erase(I[i-k]);
    s.insert(I[i]);
    f=min(f,*s.rbegin()-*s.begin());
  }
  cout<<f<<"\n";

}
