#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#endif

auto solve(ll n, vector<ll> a) {
  pair<ll, ll> fans;
  vector<ll> b(n, 0), g(n, 0), sum(n, 0);
  for (ll i = 0; i < n; i++) {
    if (a[i] == 0)
      b[i] = 1;
    else
      b[i] = a[i];
  }
  dbg(b);
  bool ok = true;
  sum[0] = 1;
  g[0] = 1;
  for (ll i = 0; i < n; i++) {
    if (b[i] == 1) {
      if (i)
        sum[i] += sum[i - 1];
      sum[i] += 1;
      if (i)
        g[i] += g[i - 1];
      g[i] += 1;
      dbg(g, i);
    }
    if (b[i] == -1) {
      if (i)
        g[i] = g[i - 1];
      if (i)
        sum[i] += sum[i - 1];
      if (g[i] < 2) {
        ok = false;
        fans.first = -1;
        fans.second = -1;
        return fans;
      }
      g[i] -= 1;
    }
  }
  dbg(sum);
  dbg(g);
  fans.first = sum[n - 1];
  fans.second = g[n - 1];
  auto chmax = [&](pair<ll, ll> a, pair<ll, ll> b) {
    dbg(a);
    dbg(b);
    if (a.first * b.second >= b.first * a.second) {
      return a;
    }
    return b;
  };
  dbg(fans);
  ll fsum = sum[n - 1], fgrp = g[n - 1];
  ll gmin = g[n - 1];
  for (ll i = n - 1; i >= 0; i--) {
    if (a[i] == 1) {
    }
    if (a[i] == -1) {
      gmin = min(g[i], gmin);
    }
    if (a[i] == 0) {
      if (fgrp > 2 && gmin > 2 && g[i] >= 3) {
        fsum -= 1;
        fgrp -= 2;
        gmin = min(gmin - 2, g[i] -2);
        fans = chmax(fans, make_pair(fsum, fgrp));
      } else {
        break;
      }
    }
  }
  ll gcd = __gcd(fans.first, fans.second);
  fans.first /= gcd;
  fans.second /= gcd;
  return fans;
}

auto bf(ll n, vector<ll> a) {

  auto get = [&](vector<ll> b) {
    dbg(b);
    pair<ll, ll> fans;
    vector<ll> sum(n, 0), g(n, 0);
    bool ok = true;
    sum[0] = 1;
    g[0] = 1;
    for (ll i = 0; i < n; i++) {
      if (b[i] == 1) {
        if (i)
          sum[i] += sum[i - 1];
        sum[i] += 1;
        if (i)
          g[i] += g[i - 1];
        g[i] += 1;
      }
      if (b[i] == -1) {
        if (i)
          g[i] = g[i - 1];
        if (i)
          sum[i] += sum[i - 1];
        if (g[i] < 2) {
          ok = false;
          fans.first = -1;
          fans.second = -1;
          return fans;
        }
        g[i] -= 1;
      }
    }
    fans.first = sum[n - 1];
    fans.second = g[n - 1];
    return fans;
  };
  pair<ll, ll> res;
  vector<ll> b(n, 0);
  for (ll i = 0; i < n; i++) {
    if (a[i] == 0) b[i] = 1;
    else b[i] = a[i];
  }
  res = get(b);
  if (res.first == -1) {
    return res;
  }
  auto chmax = [&](pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first * b.second >= b.first * a.second) {
      return a;
    }
    return b;
  };
  for (ll i = n - 1; i >= 0; i--) {
    if (a[i] == 0) {
      b[i] = -1;
      pair<ll, ll> cur = get(b);
      if (cur.first == -1) {
        break;
      } else {
        res = chmax(res, cur);
      }
    }
  }
  ll gcd=__gcd(res.first, res.second);
  res.first /= gcd;
  res.second /= gcd;
  return res;
}

// auto stress() {
//   while (true) {
//     ll n = rnd(5, 20);
//     vector<ll> a(n);
//     for (ll i = 0; i < n; i++) {
//       a[i] = rnd(-1,1);
//     }
//     auto sans = solve(n, a);
//     auto bans = bf(n, a);
//     if (sans == bans) {
//       cout << "OK\n";
//     }else{
//       cout << "NOT OK\n";
//       dbg(n);
//       dbg(a);
//       dbg(sans);
//       dbg(bans);
//       exit(0);
//     }
//   }
// }

int main() {
  // stress();
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);

  ll T;
  cin >> T;
  for (ll tc = 1; tc <= T; tc++) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto res = solve(n, a);
    if (res.first == -1) {
      cout << -1 << '\n';
    } else
      cout << res.first << "  " << res.second << '\n';
  }
  return 0;
}
