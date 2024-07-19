
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
  t = 1;
  while (t--) solve();
}

void solve() {
  ll n, k;
  cin >> n >> k;
  Vec<ll> a(n + 1, 0), s(n + 2, 0);
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (ll i = n; i >= 1; i--) {
    s[i] = a[i];
    s[i] += s[i + 1];
  }
  ll res = s[1];
  Vec<ll> v;
  for (ll i = 2; i <= n; i++) {
    v.pb(s[i]);
  }
  sort(begin(v), end(v), greater<ll>());
  for (ll i = 0; i < k - 1; i++) {
    res += v[i];
  }
  cout << res << '\n';
}
