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
  ll a[n];
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll i = min_element(a, a+n) - a;
  ll j = max_element(a, a+n) - a;
  if (i > j) swap(i, j);
  cout << min({j+1, i+1+n-j, n-i}) << "\n";
}
