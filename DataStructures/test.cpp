
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; t = 1; while (t--) solve();
}

void solve() {
  ll n = 1e5;
  string s = "";
  for (ll i = 0; i < n; i++) {
    s += 'j';
    s += 'k';
  }
  cout << s  <<"\n";
}
