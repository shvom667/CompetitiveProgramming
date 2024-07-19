#include<bits/stdc++.h>
using namespace std;
using ll = long long;
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


ll generateRandomNumber(ll upper_limit) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<ll> dis(0, upper_limit);
    return dis(gen);
}
using pl = pair<ll, ll>;
void solve() {
  ll n, m;
  cin >> n >> m;
  char g[n][m];
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < m; j++)
      cin >> g[i][j];

  Vec<ll> rv_1(n, 0);
  Vec<ll> rv_2(n, 0);
  for (ll i = 0; i < n; i++) {
    rv_1[i] = generateRandomNumber(1e18);
    rv_2[i] = generateRandomNumber(1e18);
  }

  map<pl, ll> mp;

  for (ll j = 0; j < m; j++) {
    Vec<ll> i0, i1;
    for (ll i = 0; i < n; i++) {
      if (g[i][j] == '0') {
        i0.pb(i);
      } else {
        i1.pb(i);
      }
    }
    ll tz_1=0, tz_2=0;
    for (auto&x:i0) {
      tz_1 ^= rv_1[x];
      tz_2 ^= rv_2[x];
    }
    for (auto&x:i0) {
      mp[make_pair((tz_1^rv_1[x]), (tz_2^rv_2[x]))]++;
    }
    for(auto&x:i1) {
      mp[make_pair((tz_1^rv_1[x]), (tz_2^rv_2[x]))]++;
    }
  }
  ll fans=0;
  pl bu = {-1,-1};
  for(auto&[u,v]:mp){
    fans=max(fans,v);
    if (fans==v) {
      bu=u;
    }
  }
  Vec<char> res(n, '0');
  for (ll j = 0; j < m; j++) {
    Vec<ll> i0, i1;
    for (ll i = 0; i < n; i++) {
      if (g[i][j] == '0') {
        i0.pb(i);
      } else {
        i1.pb(i);
      }
    }
    ll tz_1=0, tz_2=0;
    for (auto&x:i0) {
      tz_1 ^= rv_1[x];
      tz_2 ^= rv_2[x];
    }
    for (auto&x:i0) {
      if (make_pair((tz_1^rv_1[x]), (tz_2^rv_2[x]))== bu) {
        for(auto&y:i1){
          res[y]='1';
        }
        for(auto&y:i0){
          res[y]='0';
        }
        res[x]='1';
        goto jump;
      }
    }
    for(auto&x:i1) {
      if (make_pair((tz_1^rv_1[x]), (tz_2^rv_2[x]))== bu) {
        for(auto&y:i1){
          res[y]='1';
        }
        for(auto&y:i0){
          res[y]='0';
        }
        res[x]='0';
        goto jump;
      }
    }
  }
  jump:
  cout<<fans<<'\n';
  for(ll i=0;i<n;i++)
    cout<<res[i];
  cout<<'\n';
}
