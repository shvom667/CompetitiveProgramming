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
const ll INF64 = 1e18;
const ll N = 1e4;
void solve() {
  ll n;
  cin >> n;
  ll fans = INF64;
  for (ll f = 3; f <= sqrtl(n); f++) {
    if (n % f == 0) {
      fans = min(fans, f);
      if (n / f != f && n / f >= 3) {
        fans = min(fans, n / f);
      }
    }
  }
  if (n % 2 == 0 && n / 2 >= 3) {
    fans = min(fans, n/2);
  }
  fans = min(fans, n);
  cout << fans - 1 << '\n';
}
