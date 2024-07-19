
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
using pl = pair<ll, ll>;
Vec<pl> cord;
void solve() {
  ll n, m;
  cin >> n >> m;
  Vec<Vec<ll>> g(n, Vec<ll> (m));
  for (ll i = 0; i < n; i++) 
    for (ll j = 0; j < m; j++)
      cin >> g[i][j];
  auto valid = [&](ll x, ll y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
  };
  Vec<Vec<pl>> moves;
  auto chk1 = [&] (ll x, ll y) {
    cord.clear();
    cord.pb({x,y});
    cord.pb({x-1,y});
    cord.pb({x-1,y-1});
    cord.pb({x,y-1});
    for (auto & [p, q]: cord) {
      if (!valid(p, q))
        return false;
    }
    bool ok = true;
    for (auto& [p, q] : cord) {
      if (g[p][q] != 1)
        ok = false;
    }
    return ok;
  };
  auto chk2 = [&] (ll x, ll y) {
    cord.clear();
    cord.pb({x,y});
    cord.pb({x,y+1});
    cord.pb({x-1,y});
    cord.pb({x-1,y+1});
    for (auto & [p, q]: cord) {
      if (!valid(p, q))
        return false;
    }
    bool ok = true;
    for (auto& [p, q] : cord) {
      if (g[p][q] != 1)
        ok = false;
    }
    return ok;
  };
  auto chk3 = [&] (ll x, ll y) {
    cord.clear();
    cord.pb({x,y});
    cord.pb({x,y-1});
    cord.pb({x+1,y});
    cord.pb({x+1,y-1});
    for (auto & [p, q]: cord) {
      if (!valid(p, q))
        return false;
    }
    bool ok = true;
    for (auto& [p, q] : cord) {
      if (g[p][q] != 1)
        ok = false;
    }
    return ok;
  };
  auto chk4 = [&] (ll x, ll y) {
    cord.clear();
    cord.pb({x,y});
    cord.pb({x,y+1});
    cord.pb({x+1,y});
    cord.pb({x+1,y+1});
    for (auto & [p, q]: cord) {
      if (!valid(p, q))
        return false;
    }
    bool ok = true;
    for (auto& [p, q] : cord) {
      if (g[p][q] != 1)
        ok = false;
    }
    return ok;
  };

  bool ok = true;
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < m; j++) {
      if (g[i][j] == 1) {
        if (chk1(i, j)) {
          moves.pb(cord);
        }
        else if (chk2(i, j)) {
          moves.pb(cord);
        }
        else if (chk3(i, j)) {
          moves.pb(cord);
        }
        else if (chk4(i, j)) {
          moves.pb(cord);
        }
        else { 
          ok = false;
        }
      }
    }
  if (!ok) {
    cout << -1 << "\n";
    return;
  }
  cout << moves.size() << "\n";
  for (auto& v : moves) {
    ll mx, my;
    mx = my = 1e9;
    for (auto& [x, y] : v) {
      mx = min(mx, x);
      my = min(my, y);
    }
    cout << mx + 1 << " " << my + 1 << '\n';
  }
}
