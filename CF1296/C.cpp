
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
using pl = pair<ll, ll>;
void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  map<pl, ll> mp;
  pl c = {0, 0};
  ll fans = 1e18;
  ll bx, by;
  mp[c] = -1;
  for (ll i = 0; i < n; i++) {
    pl nc = c;
    if (s[i] == 'L') {
      nc.first--;
    }
    if (s[i] == 'R') {
      nc.first++;
    }
    if (s[i] == 'U') {
      nc.second++;
    }
    if (s[i] == 'D') {
      nc.second--;
    }
    c = nc;
    if (mp.find(nc) != mp.end()) {
      fans = min(fans, i - mp[nc] + 1);
      if (i - mp[nc] + 1 == fans) {
        bx = mp[nc] + 1;
        by = i;
      }
    }
    mp[nc] = i;
  }
  if (fans > n + 10) {
    cout << -1 << '\n';
    return;
  }
  cout << bx + 1 << " " << by + 1 << "\n";
}
