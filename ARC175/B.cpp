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

void solve() {
  ll n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  n *= 2;
  ll c_o = count(begin(s), end(s), '(');
  ll c_c = count(begin(s), end(s), ')');
  ll ca = 0, cb = 0;
  if (c_o > c_c) {
    ll d = (c_o - c_c) / 2;
    cb = d;
    for (ll i = n - 1; i >= 0; i--) {
      if (s[i] == '(' && d) {
        d--;
        s[i] = ')';
      }
    }
  }
  if (c_c > c_o) {
    ll d = (c_c - c_o) / 2;
    cb = d;
    for (ll i = 0; i < n; i++) {
      if (s[i] == ')' && d) {
        d--;
        s[i] = '(';
      }
    }
  }
  Vec<ll> p(n , 0);
  ll m = 0;
  for (ll i = 0; i < n; i++) {
    if (i) p[i] = p[i-1];
    if (s[i] == '(') p[i]++;
    else p[i]--;
    m = min(m, p[i]);
  }
  m = -m;
  m = (m + 1) / 2;
  // cout << s << "\n";
  //cout << c_o << " " << c_c << "\n";
  //cout << cb << " " << m << "\n";
  cout << cb * b  + min(m*a, 2*m*b) << "\n";
}
