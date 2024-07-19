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
ll n, l;
Vec<Vec<ll>> adj;
Vec<ll> dp;
void give(ll x) {
  if (x == -1) {
    cout << "First player loses" << "\n";
  }
  else {
    cout << "First player wins flying to airport " << x << "\n";
  }
}
void dfs(ll i, ll p) {
  bool ch0 = false;
  for (auto& ch : adj[i]) {
    if (ch != p) {
      dfs(ch, i);
      if (dp[ch]==0) {
        ch0 = true;
      }
    }
  }
  if (ch0) {
    dp[i] = 1;
  }
  else {
    dp[i] = 0;
  }
}
void solve() {
  cin >> n >> l;
  dp = Vec<ll> (n+1, 0);
  adj = Vec<Vec<ll>> (n+1);
  for (ll i = 1; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    adj[u].pb(v), adj[v].pb(u);
  }
  dfs(l, 0);
  if (dp[l] == 1) {
    Vec<ll> pos;
    for (auto& ch : adj[l]) {
      if (dp[ch] == 0) {
        pos.pb(ch);
      }
    }
    sort(begin(pos), end(pos));
    give(pos[0]);
  }
  else {
    give(-1);
  }
}
