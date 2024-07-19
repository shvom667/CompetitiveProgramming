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
  ll n, a, b;
  cin >> n >> a >> b;
  cout << min(n * a, (n/2)*b + (n&1)*a) << '\n';
}
