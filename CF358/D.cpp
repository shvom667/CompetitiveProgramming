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
void chmax(ll &x, ll y) {
  x = max(x, y);
}
const ll N = 3050;
ll dp1[N][N];
ll dp2[N], a[N], b[N], c[N], pa[N], pb[N], pc[N];
void solve() {
  ll n;
  cin >> n;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    pa[i] = a[i];
    pa[i] += pa[i - 1];
  }
  for (ll i = 1; i <= n; i++) {
    cin >> b[i];
    pb[i] = b[i];
    pb[i] += pb[i - 1];
  }
  for (ll i = 1; i <= n; i++) {
    cin >> c[i];
    pc[i] = c[i];
    pc[i] += pc[i - 1];
  }

  for (ll i = 2; i <= n - 1; i++) {
    dp1[i][i] = c[i];
  }
  for (ll l = 2; l <= n; l++) {
    for (ll i = 2; i + l - 1 < n; i++) {
      ll j = i + l - 1;
      chmax(dp1[i][j], dp1[i + 1][j] + b[i]);
      chmax(dp1[i][j], dp1[i][j - 1] + b[j]);
      chmax(dp1[i][j], pb[j] - pb[i] + c[i]);
      chmax(dp1[i][j], pb[j-1] - pb[i-1] + c[j]);
    }
  }
  dp1[1][1] = b[1];
  for (ll j = 2; j < n; j++) {
    chmax(dp1[1][j], dp1[2][j] + a[1]);
    chmax(dp1[1][j], dp1[1][j-1] + b[j]);
    chmax(dp1[1][j], pb[j] - pb[0]);
    chmax(dp1[1][j], a[1] + c[j] + pb[j - 1] - pb[1]);
  }
  dp1[n][n] = b[n];
  for (ll i = n - 1; i >= 2; i--) {
    chmax(dp1[i][n], dp1[i + 1][n] + b[i]);
    chmax(dp1[i][n], dp1[i][n - 1] + a[n]);
    chmax(dp1[i][n], pb[n] - pb[i -1]);
    chmax(dp1[i][n], c[i] + a[n] + pb[n - 1] - pb[i]);
  }
  dp2[1] = a[1];
  for (ll i = 2; i <= n; i++) {
    for (ll j = 0; j <= i - 2; j++) {
      chmax(dp2[i], dp2[j] + dp1[j+1][i-1] + a[i]);
    }
  }
  ll fans = dp2[n];
  for (ll e = n - 1; e >= 1; e--) {
    chmax(fans, dp2[e] + dp1[e + 1][n]);
  }
  cout << fans << "\n";
}
