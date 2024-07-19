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
  ll n;
  cin >> n;
  string s, r;
  cin >> s;
  ll f = 0;
  r = s;
  for (ll i = 0; i < n; i+=2) {
    if (s[i] == s[i+1]) {
      f++;
      if (s[i] == 'a') s[i] = 'b';
      else s[i] = 'a';
    }
  }
  cout << f << '\n';
  cout << s << "\n";

}
