
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
  ll w, f, n;
  cin >> w >> f >> n;
  ll s[n];
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    cin >> s[i];
    sum += s[i];
  }
  Vec<ll> dp(sum+1, 0);
  dp[s[0]] = 1;
  dp[0] = 1;
  for (ll i = 1; i < n; i++) {
    Vec<ll> ndp(sum + 1, 0);
    for (ll j = 0; j < sum + 1; j++) {
      if (dp[j]) ndp[j] = 1;
      if (j - s[i] >= 0) {
        if (dp[j-s[i]]) {
          ndp[j] = 1;
        }
      }
    }
    dp = ndp;
  }
  ll l = 0, r = 2e6;
  
  while (l <= r) {
    ll m = l + (r-l)/2;
    bool ok = false;
    for (ll j = 0; j <= sum; j++) {
      if (dp[j]) {
        ll s1 = j, s2 = sum - j;
        if ((s1<=m*w && s2<=m*f) || (s1<=m*f&&s2<=m*w)) {
          ok = true;
        }
      }
    }

    if (ok) {
      r = m-1;
    } else {
      l = m+1;
    }
  }
  cout << l << "\n";
}
