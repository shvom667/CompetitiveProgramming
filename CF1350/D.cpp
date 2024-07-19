
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
  ll n, k;
  cin >> n >> k;
  Vec<ll> a(n);
  set<ll> s;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }

  if (s.count(k) == 0) {
    cout << "NO\n";
    return;
  }
  if (n == 1) {
    cout << "YES\n";
    return;
  }
  bool ok = false;
  for (ll i = 0; i < n - 1; i++)
    if (a[i] >= k && a[i + 1] >= k)
      ok = true;
  for (ll i = 0; i < n - 2; i++) {
    Vec<ll> v;
    for (ll j = i; j < i + 3; j++) {
      v.pb(a[j]);
    }
    sort(begin(v), end(v));
    if (v[1] >= k)
      ok = true;
  }
  if (ok)
    cout << "YES\n";
  else 
    cout << "NO\n";
}
