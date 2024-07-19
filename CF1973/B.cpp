
/*
  And all I am is a man
  I want the world in my hands
  I hate the beach
  But I stand in California with my toes in the sand
  Use the sleeves of my sweater
  Let's have an adventure
  Head in the clouds but my gravity centered
  Touch my neck and I'll touch yours
  You in those little high waisted shorts, oh
*/

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
  ll a[n];
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll l = 1, r = n;
  while (l <= r) {
    ll mid = l + (r - l) / 2;
    bool ok=true;
    map<ll, ll> mp;
    Vec<ll> id(21, 0);
    for (ll i = 0; i < mid; i++) {
      for (ll b = 0; b < 20; b++) {
        if (a[i] & (1ll<<b)) {
          mp[b]++;
        }
      }
    }
    for (ll i = 0; i < 21; i++) {
      id[i] = (mp[i]>0);
    }
    for (ll i=mid;i<n;i++){
      for (ll b = 0; b < 20; b++) {
        if (a[i-mid] & (1ll<<b))
          mp[b]--;
      }
      for (ll b = 0; b < 20; b++) {
        if (a[i] & (1ll<<b))
          mp[b]++;
      }
      Vec<ll> nid(21, 0);
      for (ll j = 0; j < 21; j++) {
        nid[j] = mp[j] > 0;
      }
      if (nid != id) ok=false;
    }
    if (ok) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << l << '\n';
}
