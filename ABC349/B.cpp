
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
  string s;
  cin >> s;
  map<char, ll> mp;
  Vec<char> F[200];
  for (auto&x:s)
    mp[x]++;
  for (auto& [u, v] : mp)
    F[v].pb(u);
  bool ok = true;
  for (ll i = 1; i < 200; i++) {
    if (F[i].size() == 0 || F[i].size() == 2) {
    } else {
      ok = false;
    }
  }
  if (ok)
    cout << "Yes\n";
  else
    cout << "No\n";
}
