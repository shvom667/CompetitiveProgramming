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
  ll n, s = 0;
  cin >> n;
  ll a[n];
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  if (s%n) {
    cout << -1 << "\n";
    return;
  }
  ll c = 0;
  for (ll i = 0; i < n; i++) {
    if (a[i] > s / n) c++;
  }
  cout << c << "\n";
}
