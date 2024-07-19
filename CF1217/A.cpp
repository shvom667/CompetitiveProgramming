
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
void chmax(ll& a, ll b) {
    a = max(a, b);
}
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
  for (ll i = 0; i < n; i++)
    cin >>
  ll s, i, e;
  cin >> s >> i >> e;
  ll x = (i + e - s) / 2 + 1;
  if (i + e - s < 0) x = 0;
  x = max(0ll, x);
  ll ans = e - x + 1;
  cout << max(0ll, ans) << '\n';
}
