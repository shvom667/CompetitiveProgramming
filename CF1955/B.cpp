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
  ll n, c, d;
  cin >> n >> c >> d;
  ll b[n * n];
  for (ll i = 0; i < n * n; i++)
    cin >> b[i];
  sort(b, b + n * n);
  ll a = b[0];
  ll sq[n][n];
  sq[0][0] = a;
  for (ll i = 1; i < n; i++) {
    sq[i][0] = sq[i - 1][0] + c;
  }
  for (ll i = 0; i < n; i++)
    for (ll j = 1; j < n; j++)
      sq[i][j] = sq[i][j - 1] + d;
  bool ok = true;
  ll bb[n * n];
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < n; j++)
      bb[i * n + j] = sq[i][j];
  sort(bb, bb + n * n);
  for (ll i = 0; i < n * n; i++)
    if (bb[i] != b[i])
      ok = false;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      if (i) {
        if (sq[i][j] - sq[i - 1][j] == c) {
        } else {
          ok = false;
        }
      }
      if (j) {
        if (sq[i][j] - sq[i][j-1] == d) {
        } else {
          ok = false;
        }
      }
    }
  }
  if (!ok)
    cout << "NO\n";
  else
    cout << "YES\n";
}
