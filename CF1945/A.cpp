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
ll ub (ll x, ll y) {
  return (x + y - 1) / y;
}
void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  bool ok = true;
  if (b%3==1) {
    if (c >= 2) {
      c -= 2;
      b += 2;
    } else {
      ok = false;
    }
  }
  else if (b % 3 == 2) {
    if (c >= 1) {
      c -= 1;
      b += 1;
    } else {
      ok = false;
    }
  }
  if (!ok) {
    cout << -1 << "\n";
    return;
  }
  cout << a + b/3 + ub(c, 3) << "\n";
}

