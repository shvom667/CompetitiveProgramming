
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
  ll n, k;
  cin >> n >> k;
  ll a[n + 1];
  for (ll i = 1; i <= n; i++)
    cin >> a[i];
  ll f = 0;
  ll left = 0;
  for (ll i = 1; i <= n; i++) {
    if (left == 0) {
      left = k;
      f++;
    }
    if (left < a[i]) {
      left = k;
      f++;
    }
    left -= a[i];
  }
  cout << f << '\n';
}
