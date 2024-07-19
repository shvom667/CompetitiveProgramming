#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
  ll t; 
  t =1;
  while (t--) solve();
}

void solve() {
  ll l, r;
  cin >> l >> r;
  Vec<ll> res;
  while (l != r) {
    res.pb(l);
    ll p2 = 0;
    ll cur = l;
    ll c2=0;
    while (cur%2==0 && cur > 0) {
      cur/=2;
      c2++;
    }
    ll b2 = 0;
    if(l==0){
      c2 = 62;
    }
    for (ll j = 0; j <= c2; j++) {
      if ((1ll<<j) + l <= r) {
        b2 = j;
      }
    }
    ll nl = l + (1ll<<b2);
    l = nl;
  }
  res.pb(r);
  cout << (ll)res.size() - 1 << '\n';
  for (ll i = 0; i < (ll)res.size() - 1; i++) {
    cout << res[i] << " " << res[i+1] << "\n";
  }
}
