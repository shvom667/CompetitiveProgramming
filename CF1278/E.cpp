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
  Vec<ll> adj[n + 1] , res(2 * n + 1);
  Vec<ll> dc(n + 1, -1);
  dc[1] = 0;
  res[1] = 1;
  for (ll i = 1; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    adj[u].pb(v), adj[v].pb(u);
    dc[u]++;
    dc[v]++;
  }
  ll sp = 2;
  vector<bool> seen(n+1, false);
  function<void(ll)> dfs = [&] (ll i) {
    seen[i] = true;
    ll ec = sp + dc[i];
    res[ec] = i;
    sp = ec + 1;
    ll itr = ec - 1;
    for (auto& ch : adj[i]) {
      if (!seen[ch]) {
        res[itr] = ch;
        dfs (ch);
        itr--;
      }
    }
  };
  dfs(1);
  Vec<Vec<ll>> intervals(n + 1);
  for (ll i = 1; i <= 2 * n; i++) {
    intervals[res[i]].pb(i);
  }
  for (ll i = 1; i <= n; i++) {
    cout << intervals[i][0] << " " << intervals[i][1] << "\n";
  }
}
