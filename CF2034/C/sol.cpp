#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

auto solve() {
  ll n, m;
  cin >> n >> m;
  char g[n][m];
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  vector<Vec<bool>> out(n, vector<bool>(m, false));
  vector<Vec<bool>> seen(n, vector<bool>(m, false));
  queue<pair<ll, ll>> Q;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      if (g[i][j] != '?') {
        ll nx,ny;nx=i,ny=j;
        if(g[i][j] == 'L') ny--;
        if (g[i][j] == 'R') ny++;
        if (g[i][j] == 'U') nx--;
        if (g[i][j] == 'D') nx++;
        if (nx < 0 || nx >= n) {
          out[i][j] = true;
        }
        if (ny < 0 || ny >= m) {
          out[i][j] = true;
        }
        if (out[i][j]) {
          Q.push({i,j});
          seen[i][j] = true;
        }
      }
    }
  }
  vector<pair<ll, ll>> adj[n][m];
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      if (g[i][j] != '?') {
        ll nx,ny;nx=i,ny=j;
        if(g[i][j] == 'L') ny--;
        if (g[i][j] == 'R') ny++;
        if (g[i][j] == 'U') nx--;
        if (g[i][j] == 'D') nx++;
        // if (nx < 0 || nx >= n) {
        //   out[i][j] = true;
        // }
        // if (ny < 0 || ny >= m) {
        //   out[i][j] = true;
        // }
        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
          adj[nx][ny].pb({i,j});
        }
      }

    }
  }

  vector<ll> dx,dy;
  dx = {1, -1, 0, 0};
  dy = {0, 0, -1, 1};
  while (!Q.empty()) {
    auto t = Q.front();
    Q.pop();
    for (auto&p:adj[t.first][t.second]) {
      if (!seen[p.first][p.second]) {
        Q.push(p);
        seen[p.first][p.second] = true;
      }
    }
  }
  ll mo=0;
  for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)mo+=(seen[i][j] == true);
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      if (g[i][j] == '?') {
        bool ok = true;
        if (i - 1 >= 0) {
          if (!seen[i - 1][j] /*|| g[i - 1][j] == 'R'*/ || g[i - 1][j] == '?') ok = false;
        }
        if (i + 1 < n) {
          if (!seen[i + 1][j] /*|| g[i + 1][j] == 'L'*/ || g[i + 1][j] == '?') ok = false;
        }
        if (j - 1 >= 0) {
          if (!seen[i][j - 1] /*|| g[i][j - 1] == 'D'*/ || g[i][j - 1] == '?') ok = false;
        }
        if (j + 1 < m) {
          if (!seen[i][j + 1] /*|| g[i][j + 1] == 'U'*/ || g[i][j + 1] == '?') ok = false;
        }
        if (ok) {
          dbg(i, j);
          mo++;
        }
      }
    }
  }

  return n*m-mo;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  for (ll tc = 1; tc <= T; tc++) {
    auto res = solve();
    cout << res << "\n";
  }
  return 0;
}