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
ll ub(ll x, ll y) { return (x + y - 1) / y; }
auto solve() {
  ll n, m, k;
  cin >> n >>  m >> k;
  string s; cin >> s;
  vector<ll> f(n, 0);
  ll op = 0;
  for (ll i = 0; i < n; ) {
    dbg(f);
    if (s[i] == '1') {
      f[i] = 0;
    }
    else if (s[i] == '0') {
      f[i] = 1;
      if (i)
        f[i] += f[i - 1];
      if (f[i] == m) {
        op++;
        ll en=i;
        for (ll j = i; j <= min(n - 1, i + k - 1); j++) {
          f[j] = 0;
          s[j] = '1';
          en=j;
        }
        i = en;
      }
    }
    i++;
  }
  dbg(s);
  return op;
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
