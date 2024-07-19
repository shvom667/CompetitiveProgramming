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
  ll a[n];
  for (ll i = 0; i < n; i++)
    cin >> a[i];
  ll M = *max_element(a, a + n);
  ll sum = 0;
  ll g = 0;
  for (ll i = 0; i < n; i++) {
    g = gcd(g, M - a[i]);
    sum += M - a[i];
  }
  cout << sum / g << " " << g << "\n";
}
