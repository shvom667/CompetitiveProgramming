
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
const ll N = 150;
ll tab[N][N];
void solve() {
  ll n, m;
  cin >> n >> m;
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++)
      cin >> tab[i][j];

  for (ll d = 1; d <= n + m - 1; d++) {
    ll x, y;
    if (d <= m) {
      x = 1;
      y = d;
    } else {
      x = 1 + d - m;
      y = m;
    }
    while (x >= 1 && x <= n && y >= 1 && y <= m) {
      if (tab[x][y] % 2 != d % 2) {
        tab[x][y]++;
      }
      x++;
      y--;
    }
  }
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++)
      cout << tab[i][j] << " \n"[j == m];
}
