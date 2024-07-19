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
  t = 1 ;
  while (t--) solve();
}

void solve() {
  ll n;
  cin >> n;
  ll a[n];
  ll sum = 0;
  for (ll i = 0; i < n - 1; i++) {
    cin >> a[i];
    sum += a[i];
  }
  cout << -sum << '\n';
}
