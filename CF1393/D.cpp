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
const ll N = 2020;
ll up[N][N], down[N][N], L[N][N], R[N][N];
Vec<Vec<char>> g(N, Vec<char> (N, '$'));
void solve() {
  ll n, m;
  cin >> n >> m;

  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++)
      cin >> g[i][j];
  for (ll j = 1; j <= m; j++) {
    for (ll i = 1; i <= n; i++) {
      if (g[i-1][j] == g[i][j]) {
        up[i][j] = up[i-1][j]+1;
      }
      else {
        up[i][j] = 0;
      }
    }
  }
  for (ll j = 1; j <= m; j++) {
    for (ll i = n; i >= 1; i--) {
      if (g[i+1][j] == g[i][j])
        down[i][j] = down[i+1][j]+1;
      else
        down[i][j] = 0;
    }
  }
  for (ll i = 1; i <= n; i++) {
    for (ll j = m; j >= 1; j--) {
      R[i][j] = 1;
      if (g[i][j] == g[i][j + 1]) {
        R[i][j] = min(min(up[i][j] + 1, down[i][j] + 1), R[i][j + 1] + 1);
      }
    }
  }
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      L[i][j] = 1;
      if (g[i][j] == g[i][j - 1]) {
        L[i][j] = min(min(up[i][j] + 1, down[i][j] + 1), L[i][j - 1] + 1);
      }
    }
  }
  ll fans = 0;
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++) {
      ll x = min(R[i][j], L[i][j]);
      fans += x;
    }
  cout << fans << "\n";
}
