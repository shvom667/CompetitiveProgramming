
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
const ll inf = (1ll<<32) - 1;
void solve() {
  ll n;
  cin >> n;
  Vec<ll> v, p, b;
  v.pb(1);
  b.pb(0);
  p = v;
  ll res = 0;
  bool of  = false;
  for (ll i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if (s == "end") {
      v.pop_back(), b.pop_back(), p.pop_back();
    }
    if (s == "for") {
      ll x;
      cin >> x;
      v.pb(x);
      p.pb(x * p.back());
      if (x == 0) {
        b.push_back(0);
      }
      else if (p.back() > inf || (b.back() == 1)) {
        b.push_back(1);
      }
      else {
        b.push_back(0);
      }
    }
    if (s == "add") {
      if (b.back() == 1) of = true;
      if (b.back() == 0) {
        res += p.back();
        if (res > inf) of = true;
      }
    }
  }
  if (of) {
    cout << "OVERFLOW!!!\n";
    return;
  }
  cout << res << '\n';
}
