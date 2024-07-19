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
  ll n, m;
  cin >> n >> m;
  Vec<ll> a(n + 1, 0), b(n + 1, 0);
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (ll i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] += b[i-1];
  }
  Vec<ll> dp(n + 2, 0);
  dp[n + 1] = 0;
  ll pmin = b[n];
  for (ll i = n ; i >= 1; i--) {
    dp[i] = a[i] - b[i] + pmin;
    pmin = min(pmin, dp[i] + b[i-1]);
  }
  ll fans = 1e16;
  for (ll i = 1; i <= m; i++) {
    fans = min(fans, dp[i]);
  }
  cout << fans << "\n";
}

