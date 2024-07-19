
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
const ll N = 1e4;
const ll K = 1e5;

void solve() {
  ll n, l;
  cin >> n >> l;
  Vec<ll> res;
  if (l >= 1e4) {
    for (ll i = 1; i <= n; i++) {
      res.pb(i);
    }
  }
  else {
    ll M = 1e9;
    for (ll i = 1; i <= n; i++) {
      res.pb(M - (i - 1) * K);
    }
  }
  for(auto& x : res) {
    cout << x << " ";
  } 
  cout << '\n';
}
