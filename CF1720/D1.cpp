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
  Vec<ll> a(n, 0), dp(n, 0);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (ll i = 0; i < n; i++) {
    dp[i] = 1;
    for (ll j = max(0ll, i - 300); j < i; j++) {
      if((a[i]^j) - (a[j] ^ i) > 0)
        dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  ll f = *max_element(begin(dp), end(dp));
  cout << f << '\n';
}
