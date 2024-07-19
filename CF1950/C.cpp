
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
  string s;
  cin >> s;
  string a, b;
  a = "";
  b = "";
  ll x;
  a = s[0] + s[1];
  x = (s[0] - '0') * 10 + (s[1] - '0');
  b = s[3] + s[4];
  string res;
  res = "";
  if (x >= 12) {
    res += "MP ";
  } else {
    res += "MA ";
  }
  res += s[4];
  res += s[3];
  res += ':';
  if (x == 0) {
    x = 12;
  }
  else if (x > 12) {
    x -= 12;
  }
  if (x <= 9) {
    cout << 0;
  }
  reverse(begin(res), end(res));
  cout << x << res << '\n';
}
