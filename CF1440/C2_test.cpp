
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
const ll N = 150;
ll tab[N][N];
void solve() {
  ll n, m;
  cin >> n >> m;
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++) {
      char c;
      cin >> c;
      tab[i][j] = c - '0';
    }
  ll k;
  cin >> k;
  for (ll i = 1; i <= k; i++) {
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    tab[x1][y1] ^= 1;
    tab[x2][y2] ^= 1;
    tab[x3][y3] ^= 1;
  }
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++)
      cout << tab[i][j] << " \n"[j==m];
}
