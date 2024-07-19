
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
const ll INF=1e9+20;
void solve() {
  ll n;
  cin >> n;
  ll a[n+1];
  Vec<ll> d(n+1, INF);
  for (ll i = 1; i <= n; i++)
    cin >> a[i];
  queue<ll> Q;
  Vec<bool> seen(n+1, false);
  for (ll i = 1; i <= n; i++) {
    ll j1, j2;
    j1 = i - a[i];
    j2 = i + a[i];
    if (j1 >= 1 && j1 <= n) {
      if (a[j1]%2!=a[i]%2) {
        if (!seen[i]) {
          Q.push(i);
          d[i] = 1;
          seen[i] = true;
        }
      }
    }
    if (j2 >= 1 && j2 <= n) {
      if (a[j2]%2!=a[i]%2) {
        if (!seen[i]) {
          Q.push(i);
          d[i] = 1;
          seen[i] = true;
        }
      }
    }
  }
  map<ll, Vec<ll>> mp;
  for (ll i = 1; i <= n; i++) {
    mp[i+a[i]].pb(i);
    mp[i-a[i]].pb(i);
  }
  while (!Q.empty()) {
    ll f = Q.front();
    Q.pop();
    for (auto& j1 : mp[f]) {
      if (j1 >= 1 && j1 <= n) {
        if (!seen[j1]) {
          seen[j1] = true;
          d[j1] = d[f] + 1;
          Q.push(j1);
        }
      }
    }
  }
  for (ll i = 1; i <= n; i++)
    if (d[i] >= INF)
      cout << -1 << " ";
    else
      cout << d[i] << " ";

}
