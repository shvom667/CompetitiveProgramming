
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
using pl = pair<ll, ll>;
ll ch(ll n) {
  return (n * (n - 1) ) / 2;
}
ll find_pairs(Vec<ll>& x, Vec<ll> & y) {
  ll res = 0;
  map<ll, ll> mp;
  for (auto & val : x) {
    ll it = upper_bound(begin(y), end(y), val) - begin(y);
    mp[it]++;
  }
  for (auto& [u, v] : mp) {
    res += ch(v);
  }
  return res;
}
void solve() {
  ll n, m, k, fans;
  cin >> n >> m >> k;
  fans = 0;
  Vec<pl> hp, vp;
  Vec<ll> vl(n), hl(m);
  for (ll i = 0; i < n; i++)
    cin >> vl[i];
  for (ll i = 0; i < m; i++)
    cin >> hl[i];
  for (ll i = 0; i < k; i++) {
    ll x, y;
    cin >> x >> y;
    bool a, b;
    a = binary_search(begin(vl), end(vl), x);
    b = binary_search(begin(hl), end(hl), y);
    if (a && b)
      continue;
    if (a) {
      vp.pb({x,y});
    }
    if (b) {
      hp.pb({x,y});
    }
  }
  if (true) {
    map<ll, Vec<ll>> mp;
    Vec<ll> g;
    for (auto& [x, y] : hp) {
      mp[y].pb(x);
      g.pb(x);
    }
    Vec<Vec<ll>> I;
    for (auto& [u, v] : mp) {
      sort(begin(v), end(v));
      I.pb(v);
    }
    sort(begin(g), end(g));
    fans += find_pairs(g, vl);
    for (auto& vec : I)
      fans -= find_pairs(vec, vl);
  }
  if (true) {
    map<ll, Vec<ll>> mp;
    Vec<ll> g;
    for (auto& [x, y] : vp) {
      mp[x].pb(y);
      g.pb(y);
    }
    Vec<Vec<ll>> I;
    for (auto& [u, v] : mp) {
      sort(begin(v), end(v));
      I.pb(v);
    }
    sort(begin(g), end(g));
    fans += find_pairs(g, hl);
    for (auto& vec : I)
      fans -= find_pairs(vec, hl);
  }
  cout << fans << "\n";
}
