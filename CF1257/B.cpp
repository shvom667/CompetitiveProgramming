
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
  ll x, y;
  cin >> x >> y;
  if (x == 1) {
    if (y == 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    return;
  }
  if (x <= 3) {
    if (y <= 3) {
      cout << "YES\n";
      return;
    } else {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
