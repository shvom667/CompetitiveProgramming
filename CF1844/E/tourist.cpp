/**
 *    author:  tourist
 *    created: 11.07.2023 10:55:49       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    dsu d(2 * (n + m));
    while (k--) {
      int i1, j1, i2, j2;
      cin >> i1 >> j1 >> i2 >> j2;
      --i1; --j1; --i2; --j2;
      int i = max(i1, i2);
      int j = n + max(j1, j2);
      if (j1 < j2) {
        d.unite(i, n + m + j);
        d.unite(n + m + i, j);
      } else {
        d.unite(i, j);
        d.unite(n + m + i, n + m + j);
      }
    }
    bool ok = true;
    for (int i = 0; i < n + m; i++) {
      if (d.get(i) == d.get(n + m + i)) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}

