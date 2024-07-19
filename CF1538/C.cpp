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
  ll n, l, r;
  cin >> n >> l >> r;
  ll a[n];
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    ll u = lower_bound(a, a+n, l - a[i]) - a;
    ll v = upper_bound(a, a+n, r - a[i]) - a;
    sum += v - u;
    if (i >= u && i < v) {
      sum--;
    }
  }
  cout << sum / 2 << "\n";
}
