
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
  ll a, b, c;
  cin >> a >> b >> c;
  if (a < b && b < c) {
    cout << "STAIR\n";
    return;
  }
  if (a < b && b > c) {
    cout << "PEAK\n";
    return;
  }
  cout << "NONE\n";
}
