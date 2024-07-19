
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
  for (ll i = 0; i < 2*n; i++) {
    for (ll j = 0; j < 2*n; j++) {
      if (((i/2) + (j/2)) % 2 == 0) {
        cout << '#';
      } else {
        cout << '.';
      }
    }
    cout << '\n';
  }
}
