
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
  string a,b;
  cin>>a>>b;
  ll sa,sb;
  sa=a.size(),sb=b.size();
  ll j=0;
  Vec<ll>ans;
  for (ll i=0;i<sb;i++){
    if (b[i]==a[j]){
      j++;
      ans.pb(i);
    }
  }
  for(auto&x:ans)
    cout<<x+1<<" ";
  cout<<'\n';
}
