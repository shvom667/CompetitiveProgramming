
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
  ll a[n];
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  for (ll i = 1; i < n; i++) {
    if (a[i] > a[0]) {
      cout << i + 1 << '\n';
      return;
    }
  }
  cout<<-1<<'\n';
}
