#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
void pre();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  pre();
  while (t--) solve();
}
const ll N = 210;
ll dp[N][N][N];
void pre() {
  dp[0][0][0] = 1;
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      for (ll k = 0; k < N; k++) {
        ll add = 0;
        add = ((k+i)%2==0 && (k+j)%2==0);
        if (i) {
          dp[i][j][k] = max(dp[i-1][j][k] + add, dp[i][j][k]);
        }
        if (j) {
          dp[i][j][k] = max(dp[i][j-1][k] + add, dp[i][j][k]);
        }
        if (k) {
          dp[i][j][k] = max(dp[i][j][k-1] + add, dp[i][j][k]);
        }
      }
    }
  }
  //cout << dp[1][2][0] << '\n';
  //cout << dp[2][1][0] << '\n';
  //cout << dp[2][2][0] << '\n';
  //cout << dp[1][1][1] << '\n';
}
void solve() {
  ll c1,c2,c3,c4;
  cin>>c1>>c2>>c3>>c4;
  if (c4&1) c4--;
  ll res = 0;
  res += c4/2;
  res += dp[c1][c2][c3]-1;
  cout << res << '\n';
}
