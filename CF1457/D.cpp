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
  ll x[n];
  for (ll i=0;i<n;i++)
    cin>>a[i];
  x[0] = a[0];
  for (ll i=1;i<n;i++) {
    x[i] = a[i];
    x[i] ^= x[i-1];
  }
  for (ll i=0;i<n;i++){
    if(i+2<n){
      if((a[i+1]^a[i+2]) < a[i]) {
        cout << 1 << "\n";
        return;
      }
    }
  }
  auto rx = [&] (ll l, ll r) {
    if (l == 0) return x[r];
    return x[r]^x[l-1];
  };
  ll fans = 1e18;
  for (ll i = 0; i < n; i++)
    for (ll j = i + 2; j < n; j++)
      for (ll k = i; k < j; k++)
      {
        if(rx(i,k) > rx(k+1,j))
          fans = min(fans, j-i+1);
      }
  cout << (fans >= 1e6 ? -1 : fans-2) << '\n';
}
