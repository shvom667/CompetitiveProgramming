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
  ll b, p, f, h, c;
  cin >> b >> p >> f >> h >> c;
  ll fans = 0;
  for (ll hb = 0; hb <= 100; hb++) {
    for (ll cb = 0; cb <= 100; cb++) {
      if (hb <= p && cb <= f && 2 * (hb + cb) <= b) {
        fans = max(fans, hb * h + cb * c);
      }
    }
  }
  cout << fans  << '\n';
}
