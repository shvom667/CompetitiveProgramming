
#include<bits/stdc++.h>
using namespace std;



using ll=long long;

template <typename T>
using Vec = vector<T>;

#define pb push_back

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)solve();
}

void solve() {
  ll n;
  cin >> n;
  Vec<ll> a(n+1), dp(n+1, 0);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    dp[i] = n-i;
  }
  for (ll i = n - 1; i >= 0; i--) {
    dp[i] = min(dp[i], 1 + dp[i+1]);
    if (i + a[i] < n)
      dp[i] = min(dp[i], dp[i+a[i]+1]);
  }
  cout << dp[0] << "\n";
}
