
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
  ll n, a, b;
  cin >> n >> a >> b;
  ll l = 0, r = min(n, b);
  while (r - l > 2) {
    ll m1 = l + (r-l)/3;
    ll m2 = r - (r-l)/3;

    ll a1, a2;
    ll k = m1;
    a1 = (n-k)*a + (b+1)*k - (k*(k+1))/2;
    k = m2;
    a2 = (n-k)*a + (b+1)*k - (k*(k+1))/2;

    if (a1 < a2) {
      l = m1;
    } else {
      r = m2;
    }
  }
  ll fans = 0;
  for (ll v = max(0ll,l-5); v <= min(min(n,b), l+5); v++) {
    ll k = v;
    ll cur = (n-k)*a + (b+1)*k - (k*(k+1))/2;;
    fans = max(fans, cur);
  }
  cout << fans << "\n";
}
