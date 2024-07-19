
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
  t = 1;
  while (t--) solve();
}

ll ub(ll x, ll y) {
  return (x + y - 1) / y;
}
void solve() {
  ll n, a, b, k;
  cin >> n >> a >> b >> k;
  Vec<ll> h(n), res(n);
  for (ll i = 0; i < n; i++)
    cin >> h[i];
  for (ll i = 0; i < n; i++) {
    ll l = 0, r = 1e9+10;
    while (l <= r) {
      ll mid = l + (r - l) / 2;
      bool ok = false;
      ll v = h[i] - ((mid + 1) / 2) * a - b * (mid / 2);
      ok = (v > 0);
      if (ok)
        l = mid + 1;
      else
        r = mid - 1;
    }
    if (r&1) {
      ll v = h[i] - ((r + 1) / 2) * a - b * (r / 2);
      res[i] = ub(v, a);
    } else {
      res[i] = 0;
    }
  }
  sort(begin(res), end(res));
  ll f = 0;
  for (ll i = 0; i < n; i++) {
    if (k >= res[i]) {
      k -= res[i];
      f++;
    }
  }
  cout << f << "\n";
}
