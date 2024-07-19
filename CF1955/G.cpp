#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct splitmix64 {
    size_t operator()(size_t x) const {
        static const size_t fixed = chrono::steady_clock::now().time_since_epoch().count();
        x += 0x9e3779b97f4a7c15 + fixed;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
};

const ll N = 1e5;
//gp_hash_table<int, int, splitmix64> mp[N];

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--) solve();
}
ll a[110][110];

void solve() {
  ll n, m;
  cin >> n >> m;
  for (ll i = 1; i <= n; i++)
    for (ll  j = 1; j <= m; j++)
      cin >> a[i][j];
  Vec<ll> fac;
  for (ll i = 1; i <= sqrtl(a[1][1]); i++) {
    if (a[1][1]%i==0) {
      fac.pb(i);
      if (a[1][1] / i != i) {
        fac.pb(a[1][1]/i);
      }
    }
  }
  map<int, int> mp;
  sort(begin(fac), end(fac));
  ll fz = fac.size();
  for (ll i = 0; i < (ll)fac.size(); i++)
    mp[fac[i]] = i;
  Vec<bool> pos_id((ll)fac.size(), false);
  Vec<Vec<bool>> dp(m+1);
  for (ll j = 1; j <= m; j++) {
    dp[j] = pos_id;
  }
  dp[1][mp[a[1][1]]] = 1;
  for (ll j = 2; j <= m; j++) {
    for (ll i = 0; i < fz; i++) {
      if (dp[j-1][i]) {
        dp[j][mp[gcd(fac[i], a[1][j])]]=true;
      }
    }
  }
  for (ll i = 2; i <= n; i++)  {
    Vec<Vec<bool>> ndp(m+1);
    for (ll j = 1; j <= m; j++) {
      ndp[j] = pos_id;
    }
    for (ll j = 1; j <= m; j++) {
      for (ll k = 0; k < fz; k++) {
        if (dp[j][k]) {
          ndp[j][mp[gcd(a[i][j], fac[k])]] = 1;
        }
      }
    }
    for (ll j = 2; j <= m; j++) {
      for (ll k = 0; k < fz; k++) {
        if (ndp[j-1][k]) {
          ndp[j][mp[gcd(a[i][j], fac[k])]] = 1;
        }
      }
    }
    dp = ndp;
  }

  ll fans = -1;
  for (ll k = 0; k < fz; k++) {
    if (dp[m][k])
      fans = max(fans, fac[k]);
  }
  cout << fans << '\n';
}
