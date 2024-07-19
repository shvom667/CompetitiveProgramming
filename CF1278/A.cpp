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

void solve() {
  string p, h;
  cin >> p >> h;
  Vec<ll> v(26, 0);
  for (ll i = 0; i < p.size(); i++) {
    v[p[i] - 'a']++;
  }
  if (p.size() > h.size()) {
    cout << "NO\n";
    return;
  }
  Vec<ll> q(26, 0);
  ll n = p.size();
  for (ll i = 0; i < n; i++) {
    q[h[i] - 'a']++;
  }
  bool ok = false;
  ok = (v == q);
  for (ll j = n; j < h.size(); j++) {
    q[h[j]-'a']++;
    q[h[j-n] - 'a']--;
    if (q == v) {
      ok = true;
    }
  }
  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
