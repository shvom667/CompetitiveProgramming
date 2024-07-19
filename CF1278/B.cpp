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
  ll a, b;
  cin >> a >> b;
  ll d = abs(a - b);
  if (d == 0) {
    cout << 0 << "\n";
    return;
  }
  for (ll i = 1; i <= 1e6; i++) {
    ll sum = i * (i + 1) / 2;
    if (d % 2 == sum % 2 && sum >= d) {
      cout << i << "\n";
      return;
    }
  }
}
