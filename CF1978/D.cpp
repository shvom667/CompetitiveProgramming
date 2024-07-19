
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
  ll n, c;
  cin >> n >> c;
  ll a[n], f[n];
  ll pm[n];
  ll m  = 0, mi = 0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    m = max(m, a[i]);
  }
  for (ll i  = n - 1; i >= 0; i--) {
    if (a[i] == m) mi = i;
    pm[i] = a[i];
    if (i < n - 1) {
      pm[i] = max(pm[i], pm[i+1]);
    }
  }

  ll psum=0;

  if (a[0] + c >= m) {
    f[0] = 0;
  } else {
    f[0] = 1;
  }
  psum += a[0];


  for (ll i = 1; i < n; i++) {
    ll res = 0;
    if (i == mi && (c + a[0] < a[i])) {
      f[i] = 0;
    } else {
      res += i;
      if (i == n - 1 || c + psum + a[i] >= pm[i+1]) {
      } else {
        res++;
      }
      f[i] = res;
    }

    psum += a[i];
  }

  for (ll i = 0; i < n; i++)
    cout << f[i] << " \n"[i==n-1];
}
