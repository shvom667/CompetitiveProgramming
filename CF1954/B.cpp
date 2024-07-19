
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
  Vec<ll> a(n + 1);
  map<ll, ll> mp;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  if((ll)mp.size() == 1) {
    cout << -1 << "\n";
    return;
  }
  if (a[1] != a[n]) {
    cout << 0 << "\n";
    return;
  }
  for (ll i = 2; i <= n; i++) {
    if (a[i] == a[i-1] && a[i] != a[1]) {
      cout << 0 << '\n';
      return;
    }
  }
  Vec<ll> val(n + 2, 0);
  Vec<ll> dp(n + 2, 0);
  ll fans = 1e18;
  for (ll i = 1; i <= n; i++) {
    if (a[i] == a[1]) {
      val[i] = 1;
    }
  }
  for (ll i = 1; i <= n + 1; i++) {
    if (val[i] == 1) {
      dp[i] = 1 + dp[i-1];
    } else {
      dp[i] = 0;
      fans = min(fans, dp[i-1]);
    }
  }
  cout << fans << '\n';
}
