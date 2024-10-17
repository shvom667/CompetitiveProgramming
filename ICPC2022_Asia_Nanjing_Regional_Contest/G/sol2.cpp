#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
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
      if (gmin > 2 && g[i] >= 3) {
        fsum -= 1;
        fgrp -= 2;
        gmin = min(gmin - 1, g[i] - 1);
        fans = chmax(fans, make_pair(fsum, fgrp));
      } else {
        break;
      }
    }
  }
  // dbg(sum);
  // dbg(g);
  ll gcd = __gcd(fans.first, fans.second);
  fans.first /= gcd;
  fans.second /= gcd;
  return fans;
}

auto bf(ll n, vector<ll> a) {
  pair<ll, ll> fans;

  auto get = [&](vector<ll> b) {
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
  };

  return fans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

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
