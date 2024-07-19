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

void solve() {
  ll n;
  cin >> n;
  Vec<ll> s(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> s[i];
  }
  sort(begin(s) + 1, end(s));
  ll l = 0, r = n/2;
  auto cond = [&] (ll mid) {
    bool ok = true;
    for (ll i = 1; i <= mid; i++) {
      if (s[i] * 2 <= s[n-mid + i]) {
      } else {
        ok = false;
      }
    }
    return ok;
  };
  while (l <= r) {
    ll mid = l + (r - l) / 2;
    if (cond(mid)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << n - r << "\n";
}
