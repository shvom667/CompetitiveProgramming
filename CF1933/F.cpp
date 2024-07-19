#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
#define F first
#define S second
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--) solve();
}
using pl = pair<ll, ll>;
const ll INF64 = 1e18;

void solve() {
  ll n, m;
  cin >> n >> m;
  Vec<Vec<ll>> g(n, Vec<ll> (m));
  Vec<Vec<ll>> d(n, Vec<ll> (m, INF64));
  Vec<Vec<bool>> seen(n, Vec<bool> (m, false));
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < m; j++)
      cin >> g[i][j];
  queue<pl> Q;
  d[0][0] = 0;
  seen[0][0] = true;
  Q.push({0,0});

  auto chk1 = [&] (ll i, ll j) {
    ll i1, j1, i2, j2;
    i1 = (i+1)%n;
    i2 = (i1+1)%n;
    j1 = j2 = j;
    if (g[i1][j1] == 0 && g[i2][j2] == 0) {
      return true;
    }
    return false;
  };
  auto chk2 = [&] (ll i, ll j) {
    ll i1, j1;
    i1 = i + 1;
    j1 = j + 1;
    i1 %= n, j1 %= m;
    if (g[i1][j1] == 0)
      return true;
    return false;
  };
  while (!Q.empty()) {
    pl f = Q.front();
    Q.pop();
    ll i  = f.F, j = f.S;
    if (chk1(i,j)) {
      ll i1, j1, i2, j2;
      i1 = (i+1)%n;
      i2 = (i1+1)%n;
      j1 = j2 = j;
      if (!seen[i2][j2]) {
        seen[i2][j2] = true;
        Q.push({i2,j2});
        d[i2][j2] = d[f.F][f.S]+1;
      }
    }
    if (chk2(i,j)) {
      ll i1, j1;
      i1 = i + 1;
      j1 = j + 1;
      i1 %= n, j1 %= m;
      if (!seen[i1][j1]) {
        seen[i1][j1] = true;
        Q.push({i1,j1});
        d[i1][j1] = d[f.F][f.S]+1;
      }
    }
  }
  ll fans = INF64;
  for (ll r = 0; r < n; r++) {
    ll k = d[r][m-1];
    ll fp = ((r - k) % n + n) % n;

    fans = min(fans, k + (fp+1)%n);
  }
  cout << (fans >= (ll)1e15 ? -1 : fans) << '\n';
}
