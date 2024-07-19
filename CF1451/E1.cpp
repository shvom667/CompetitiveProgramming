#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  t = 1;
  while (t--)
    solve();
}
#define nl endl
ll ask_xor(ll i, ll j) {
  cout << "XOR " << i << " " << j << nl;
  ll res;
  cin >> res;
  return res;
}
ll ask_and(ll i, ll j) {
  cout << "AND " << i << " " << j << nl;
  ll res;
  cin >> res;
  return res;
}
void give(Vec<ll> a) {
  cout << "! ";
  for (ll i = 1; i < a.size(); i++)
    cout << a[i] << " ";
  cout << nl;
}
void solve() {
  ll n;
  cin >> n;
  Vec<ll> a(n + 1);
  Vec<ll> x(n + 1);
  map<ll, Vec<ll>> mp;
  bool ok = false;
  for (ll i = 2; i <= n; i++) {
    ll res = ask_xor(1, i);
    if (res == 0 && !ok) {
      ok = true;
      a[1] = ask_and(1, i);
    }
    x[i] = res;
    mp[res].pb(i);
  }
  if (ok) {
    for (ll i = 2; i <= n; i++) {
      a[i] = x[i] ^ (a[1]);
    }
    give(a);
    return;
  }
  if (mp.size() == n - 1) {
    ll c = -1;
    for (ll i = 2; i <= n; i++)
      if (x[i] == n - 1) c = i;
    ll t = (c == 2 ? 3 : 2);
    ll a1 = ask_and(1, t);
    ll a2 = ask_and(c, t);
    a[t] = 0;
    for (ll b = 0; b < 20; b++) {
      if ((a1 & (1ll << b)) || (a2 & (1ll << b))) {
        a[t] ^= (1ll<<b);
      }
    }
    a[1] = x[t] ^ a[t];
    for (ll i = 2; i <= n; i++)
      a[i] = x[i] ^ a[1];
    give(a);
    return;
  }
  ll p, q;
  for (auto& [u, v] : mp) {
    if (v.size() > 1) {
      p = v[0], q = v[1];
      ll and_res = ask_and(p, q);
      a[p] = a[q] = and_res;
      break;
    }
  }
  a[1] = x[p] ^ a[p];
  for (ll i = 1; i <= n; i++) {
    if (i != p && i != q) {
      a[i] = x[i] ^ a[1];
    }
  }
  give(a);
}
