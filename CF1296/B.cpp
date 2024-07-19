
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
  ll f = 0;
  while (n > 0) {
    if (n < 10) {
      f += n;
      break;
    }
    f += n - n % 10;
    ll y = (n - n % 10) / 10;
    n = y + n % 10;
  }
  cout << f << "\n";
}
