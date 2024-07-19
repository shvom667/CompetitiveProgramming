
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
  Vec<ll> a(n + 1);
  Vec<ll> ind[n + 1];
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    ind[a[i]].pb(i);
  }
  ll fans = 1e18;
  map<ll, ll> mp;
  ll p = 1;
  mp[a[1]]++;
  for (ll i = 2; i <= n; i++) {
    mp[a[i]]++;
    while (mp.size() < i - p + 1) {
      mp[a[p]]--;
      if (mp[a[p]]==0) {
        mp.erase(mp.find(a[p]));
      }
      p++;
    }
    if (p - 1 >= 1) {
      if (a[p - 1] == a[i])
        fans = min(fans, i - p + 1);
    }
  }


  cout << (fans > n + 10 ? - 1 : fans + 1) << "\n";
}
