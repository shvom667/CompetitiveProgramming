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
/*
 * Idea : 
 * Mex p0...pi is the min element that apperas in suffix p_i+1, p_i+2 ... p_n-1
 */
void solve() {
  ll n;
  cin >> n;
  Vec<ll> a(n), p(n), m(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  m[n-1] = n;
  p[n-1] = -a[n-1] + m[n-1];
  ll pmin = p[n-1];
  for (ll i = n - 2; i >= 0; i--) {
    p[i] = pmin - a[i];
    pmin = min(pmin, p[i]);
  }
  for (ll i = 0; i < n; i++) {
    cout << p[i] << " ";
  } cout << "\n";
}
