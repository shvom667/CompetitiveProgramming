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

ll get(ll x, ll y) {
  ll z = x / (y+1);
  ll l, r;
  l = 0, r = z;
  while (l <= r) {
    ll m = l + (r - l) / 2;
    bool ok = true;
    if (l * (y + 1) + y <= x) {
      ok = true;
    } else {
      ok = false;
    }
    if (ok) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return l;
}
Vec<ll> fo (ll u) {
  ll s = 0;
  Vec<ll> a(11, 0);
  ll k = 1;
  while (s*10 + 9 <= u) {
    s = s*10 + 9;
    ll ans = get(u, s);
    a[k] = ans;
    k++;
  }
  return a;
}
void solve() {
  ll a, b;
  cin >> a >> b;
  ll res = b - a;

  auto v1 = fo(a-1);
  auto v2 = fo(b-1);
  auto c = v1;
  for (ll i = 0; i < (c.size()); i++) {
    c[i] = v2[i] - v1[i];
  }

  ll ad = 0;
  for (ll i = 1; i < c.size() - 1; i++) {
    ad += (c[i] - c[i+1])*i;
  }

  cout << res + ad << "\n";
}

