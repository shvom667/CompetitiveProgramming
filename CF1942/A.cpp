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
  cin >> n >> k;
  if (k == n) {
    for (ll i = 1; i <= n; i++) {
      cout << 1 << " ";
    } cout << '\n';
    return;
  }
  if (k == 1) {
    for (ll i = 1; i <= n; i++) {
      cout << i << " ";
    } cout << '\n';
    return;
  }
  cout << -1 << '\n';
}
