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
const ll INF64 = 2e18;
void solve() {
  ll n;
  cin >> n;
  Vec<ll> a(n);
  ll total_sum = 0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    total_sum += a[i];
  }
  sort(begin(a), end(a));
  ll m;
  cin >> m;
  while (m--) {
    ll x, y;
    cin >> x >> y;
    ll fans = INF64;
    auto it = upper_bound(begin(a), end(a), x);
    if (it != end(a)) {
      fans = min(fans, max(0ll, y - (total_sum - *it)));
    }
    if (it != begin(a)) {
      it--;
      fans = min(fans, max(0ll, x - *it + max(0ll, y - (total_sum - *it))));
    }
    cout << fans << "\n";
  }
}
