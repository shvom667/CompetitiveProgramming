
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;
  while (t--)
    solve();
}

void solve() {
  ll n, m;
  cin >> n >> m;
  char g[n][m];
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < m; j++)
      cin >> g[i][j];
  bool ok = true;
  ll x, y;
  x = y = 0;
  for (ll j = 0; j < m; j++) {
    if (g[0][j] == 'W') {
      x++;
    }
    if (g[n - 1][j] == 'B') {
      y++;
    }
  }
  if (x == m && y == m)
    ok = false;
  x = y = 0;
  for (ll j = 0; j < m; j++) {
    if (g[0][j] == 'B') {
        1
      x++;
    }
    if (g[n - 1][j] == 'W') {
      y++;
    }
  }
  if (x == m && y == m)
    ok = false;
  x = y = 0;
  for (ll i = 0; i < n; i++) {
    if (g[i][0] == 'B') {
      x++;
    }
    if (g[i][m - 1] == 'W') {
      y++;
    }
  }
  if (x == n && y == n)
    ok = false;
  x = y = 0;
  for (ll i = 0; i < n; i++) {
    if (g[i][0] == 'W') {
      x++;
    }
    if (g[i][m - 1] == 'B') {
      y++;
    }
  }
  if (x == n && y == n)
    ok = false;
  if (!ok) {
    cout << "NO\n";
    return;
  } else {
    cout << "YES\n";
    return;
  }
}
