
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
    ll a[n];
    map<ll, ll> mp;
    ll f = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        f = max(f, mp[a[i]]);
    }
    if (f >= k) {
        cout << k-1 << '\n';
    }else {
        cout << n << '\n';
    }
}
