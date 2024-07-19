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
  ll n;
  cin >> n;
  Vec<ll> a(n);
  ll sum = 0;
  ll o, e;
  o = e = 0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i]&1)
      o++;
    else
      e++;
    sum += a[i];
  }
  if (sum&1) {
    cout << "YES\n";
    return;
  }
  if (o > 0 && e > 0) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
  return;
}
