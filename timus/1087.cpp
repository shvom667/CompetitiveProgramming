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

  ll n, m;
  cin >> n >> m;
  ll a[m];
  for (ll i = 0; i < m; i++) {
    cin >> a[i];
  }
  sort(a, a+m);
  Vec<ll> dp(n + 1);
  for (ll i = 0; i < a[0]; i++) {
    dp[i] = 1;
  }
  dp[a[0]] = 0;
  for (ll i = a[0] + 1; i <= n; i++) {
    bool win = false;
    for (ll j = 0; j < m; j++) {
      if (i - a[j] >= 0 && dp[i- a[j]] == false) {
        win = true;
      }
    }
    if (win) dp[i] = 1;
    else dp[i] = 0;
  }
  if (dp[n]) {
    cout << 1 << "\n";
  } else {
    cout << 2 << "\n";
  }
}
