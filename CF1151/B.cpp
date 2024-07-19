
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  t = 1;
  while (t--)
    solve();
}

void solve() {
  ll n, m;
  cin >> n >> m;
  ll a[n][m];
  for(ll i=0;i<n;i++)
    for(ll j=0;j<m;j++)
      cin>>a[i][j];
  set<ll> mp[n];
  ll x=0;
  Vec<ll> res(n,0);
  for(ll i=0;i<n;i++){
    res[i]=0;
    x ^= a[i][0];
  }
  bool ok=false;
  if(x==0) {
    for(ll i=0;i<n;i++){
      for(ll j=0;j<m;j++) {
        if(a[i][j] != a[i][0])
        {
          ok=true;
          res[i]=j;
          break;
        }
      }
      if(ok)
        break;
    }
  } else{
    ok=true;
  }
  if(!ok)
    cout<<"NIE\n";
  else{
    cout<<"TAK\n";
    for(ll i=0;i<n;i++)
      cout<<res[i]+1<<" ";
    cout<<'\n';
  }

}
