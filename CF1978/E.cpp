
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
  char s[n], t[n], ns[n], nt[n];
  for (ll i = 0; i < n; i++) {
    cin >> s[i];
    ns[i] = s[i];
  }
  for (ll i = 0; i < n; i++) {
    cin >> t[i];
    nt[i] = t[i];
  }
  for (ll i = 0; i + 2 < n; i++) {
    if (ns[i] == '0' && ns[i+2] == '0') {
      nt[i+1] = '1';
    }
  }

  for (ll i = 0; i + 2 < n; i++) {
    if (nt[i] == '1' && nt[i+2] == '1') {
      ns[i+1] = '1';
    }
  }

  ll ps[n];
  for (ll i = 0; i < n; i++) {
    ps[i] = ns[i] == '1';
    if (i) {
      ps[i] += ps[i-1];
    }
  }

  //for (ll i = 0; i < n; i++) {
  //  cout << nt[i] << " ";
  //} cout << "\n";
  //for (ll i = 0; i < n; i++) {
  //  cout << ns[i] << " ";
  //} cout << "\n";

  ll q;
  cin >> q;

  while (q--) {
    ll l, r;
    cin >> l >> r;
    l--; r--;

    ll fans = 0;

    if (l + 2 <= r - 2) {
      fans += ps[r-2] - ps[l+1];
    }
    if (l + 1 < r) {
      if (s[l + 1] == '1' ||  (l + 2 < r && t[l] == nt[l+2] && t[l] == '1')
          || (l + 2 == r && t[l] == t[l+2] && t[l] == '1')
          ) {
        fans++;
      }
    }
    if (r - 1 > l + 1) {
      if (s[r-1] == '1' || (r-2 > l && t[r] == nt[r-2] && t[r] == '1')
          || (r - 2  == l && t[r-2] == t[r] && t[r] == '1')
          ) {
        fans++;
      }
    }

    fans += s[l] == '1';
    if (r > l)
      fans += s[r] == '1';
    cout << fans  << "\n";
  }
}
