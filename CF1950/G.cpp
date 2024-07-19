
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;


// ============

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--) solve();
}
struct song {
  string a, b;
};
void re(song& s) {
  cin >> s.a >> s.b;
}
void solve() {
  ll n;
  cin >> n;
  Vec<song> a(n);
  for (ll i = 0; i < n; i++) {
    re(a[i]);
  }
  bool ma[n][n], mb[n][n];
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      ma[i][j] = 0;
      mb[i][j] = 0;
    }
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++)  {
      if (a[i].a == a[j].a) {
        ma[i][j] = 1;
      }
      if (a[i].b == a[j].b) {
        mb[i][j] = 1;
      }
    }
  }
  bool dp[1<<n][n];
  for (ll i = 0; i < (1<<n); i++) {
    for (ll j = 0; j < n; j++) {
      dp[i][j] = 0;
    }
    if (__builtin_popcount(i) == 1) {
      for (ll j = 0; j < n; j++) {
        if (i == (1<<j)) {
          dp[i][j] = 1;
        }
      }
    }
  }
  ll m = 0;
  for (ll b = 2; b <= n; b++) {
    for (ll i = 0; i < (1<<n); i++) {
      if (__builtin_popcount(i) == b) {
        for (ll lb = 0; lb < n; lb++) {
          if ((1<<lb) & i) {
            //dp[i][lb] ?
            for (ll llb = 0; llb < n; llb++) {
              ll l2 = (i^(1<<lb));
              dp[i][lb] |= (dp[l2][llb] && (ma[lb][llb] || mb[lb][llb]));
            }
            if (dp[i][lb]) {
              m = max(m, b);
            }
          }
        }
      }
    }
  }
  cout << n - max(1ll, m) <<  '\n';
}

