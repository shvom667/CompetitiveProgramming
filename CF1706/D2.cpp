
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

Vec<ll> get(ll N, ll K) {
  Vec<ll> res;
  for (ll i = K; i <= K; i++) {
    for (ll k = 1; (k <= i + 1 && k * i <= N); k++) {
      for (ll mod = 0; (mod < k && k * i + mod <= N); mod++) {
        res.push_back(i * k + mod);
      }
    }
    if ( (i + 2) * i< N)
    while (res.back() < N)
      res.pb(res.back() + 1);
  }
  return res;
}

void solve() {
  ll n, k;
  cin >> n >> k;
  ll a[n+1];
  for (ll i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);

  ll p = 0;
  Vec<ll> cnt(n + 1, 0);
  ll s = 1;
  ll e = 0;
  while (p != n) {
    e++;
    auto res = get(n, e);
    for (auto& v : res) {
      cnt[v]++;
      if (cnt[v]==1)
        p++;
    }
  }
  while (e < n) {
    auto res = get(n, s);
  }
}
