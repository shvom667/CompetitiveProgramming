
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
  ll n, k;
  cin >> n >> k;
  if (k > (n*n)/2 || (k & 1)) {
    cout << "NO\n";
    return;
  }
  ll l, r;
  ll res[n+1];
  for (ll i = 1; i <= n; i++) {
    res[i] = i;
  }
  l = 1, r = n;


  while (k > 0 /*&& l <= r*/) {
    if (k >= 2*(r-l)) {
      res[l] = r;
      res[r] = l;
      k -= 2 * (r-l);
      l++;
      r--;
    } else {
      l++;
    }
  }


  cout << "YES\n";
  for (ll i = 1; i <= n; i++) {
    cout << res[i] << " ";
  } cout << '\n';
}
