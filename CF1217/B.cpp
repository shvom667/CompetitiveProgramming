
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
ll INF = 1e9;
void solve() {
  ll n, x;
  cin >> n >> x;
  Vec<ll> d(n), h(n);
  ll m = INF;
  ll M = -INF;
  for (ll i = 0; i < n; i++) {
    cin >> d[i] >> h[i];
    M = max(M, d[i]);
    m = min(m, h[i] - d[i]);
  }
  if (m >= 0 && M < x) {
    cout << -1 << '\n';
    return;
  }
  if (M >= x) {
    cout << 1 << '\n';
    return;
  }
  ll l = 1, r = 1e9;
  while (l <= r) {
    ll mid = l + (r - l) / 2;
    bool ok = false;
    ok = mid*m + x <= M;
    if (ok) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << l + 1 << '\n';
}
