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
    ll x[n+1];
    ll a[n+1];
    for (ll i = 2; i <= n; i++)
        cin >> x[i];
    a[1] = 1000;
    for (ll i = 2; i <= n; i++) {
        a[i] = a[i-1] + x[i];
    }
    for (ll i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";
}
