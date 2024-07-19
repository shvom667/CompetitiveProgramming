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
ll x, y, c1, c2, c3, c4, c5, c6;
ll go(ll p, ll q, ll r, ll s) {
  ll fans = 0;
  r -= p;
  s -= q;
  if (r == s && r == 0) return fans;
  if (r == s) {
    if (r > 0) return r*c1;
    if (r < 0) return -1ll*r*c4;
  }
  if (s == 0) {
    if (r > 0) return r * c6;
    if (r < 0) return (-r)*c3;
  }
  if (r == 0) {
    if (s > 0) return s* c2;
    if (s < 0) return -1ll * s * c5;
  }
  assert(false);
  return fans;
}
using pl = pair<ll, ll>;
void solve() {
  cin >> x >> y >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
  Vec<pl> v;
  v.pb({y,y});
  v.pb({x,x});
  v.pb({x,0});
  v.pb({0,y});
  v.pb({0,y-x});
  v.pb({x-y,0});
  ll fans = 2e18;
  for (auto& [l, r] : v) {
    fans = min(fans, go(0,0,l,r) + go(l,r,x,y));
  }
  cout << fans << "\n";
}
