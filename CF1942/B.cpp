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
  ll n, pm;
  cin >> n;
  Vec<ll> a(n), p(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  Vec<ll> v;
  if (a[0] > 0) {
    v.pb(0);
    p[0] = 0;
    pm = 1;
  } else {
    v.pb(-a[0]);
    p[0] = -a[0];
    pm = 0;
  }
  for (ll i = 1; i < n; i++) {
    if (a[i] > 0) {
      p[i] = pm;
      pm = a[i] + p[i];
    }
    else {
      p[i] = pm - a[i];
    }
  }
  for (ll i = 0; i < n; i++) {
    cout << p[i] << " \n"[i == n - 1];
  }
}
