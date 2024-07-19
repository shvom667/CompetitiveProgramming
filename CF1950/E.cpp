
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
  string s,t;
  cin >> s;
  t = s;
  reverse(begin(t), end(t));
  Vec<ll> fac;
  for (ll i = 1; i <= sqrtl(n); i++) {
    if (n % i == 0) {
      fac.pb(i);
      if (n / i != i) {
        fac.pb(n / i);
      }
    }
  }
  sort(begin(fac), end(fac));
  for (auto& x : fac) {
//    cout << x << '\n';
    ll c = 0;
    for (ll i = 0; i < n; i++) {
      if (s[i] == s[i%x]) {
      } else {
        c++;
      }
    }
    ll b = 0;
    for (ll i = 0; i < n; i++) {
      if (t[i] == t[i%x]) {
      } else {
        b++;
      }
    }
    if (c <= 1 || b <= 1) {
      cout << x << '\n';
      return;
    }
  }
}
