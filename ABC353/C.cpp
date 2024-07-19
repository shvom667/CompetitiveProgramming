
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
const ll M = 1e8;
void solve() {
  ll n;
  cin >> n;
  Vec<ll> a(n);
  ll sum = 0, fans = 0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  fans = sum * (n-1);
  sort(begin(a), end(a));
  ll rem = 0;
  for (ll i = 0; i < n; i++) {
    ll j = i + 1;
    ll k = lower_bound(begin(a),end(a), M-a[i])-begin(a);
    j = max(j, k);
    rem += n  - j;
  }
  cout << fans - rem * M << '\n';
}
