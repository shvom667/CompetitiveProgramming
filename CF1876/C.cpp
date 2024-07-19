#include<bits/stdc++.h>
using namespace std;
using ll=int;
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
  ll a[n + 1];
  Vec<ll> adj[n + 1], indeg(n + 1, 0);
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    adj[i].pb(a[i]);
    indeg[a[i]]++;
  }
  Vec<ll> color(n + 1, -1);
  Vec<bool> seen(n + 1, false);
  queue<ll> Q;
  for (ll i = 1; i <= n; i++) {
    if (indeg[i] == 0) {
      seen[i] = true;
      color[i] = 0;
      Q.push(i);
    }
  }
  while (!Q.empty()) {
    ll f = Q.front();
    Q.pop();
    if (color[f] == 0) {
      for (auto& u : adj[f]) {
        if (!seen[u]) {
          seen[u] = true;
          color[u] = 1;
          Q.push(u);
        }
      }
    }
    else {
      for (auto& u : adj[f]) {
        if (!seen[u]) {
          indeg[u]--;
          if (indeg[u] == 0) {
            seen[u] = true;
            color[u] = 0;
            Q.push(u);
          }
        }
      }
    }
  }

  // ===============
  
  Vec<ll> ord;
  function<void(ll)> dfs = [&] (ll i) {
    seen[i] = true;
    ord.pb(i);
    for (auto& ch : adj[i]) {
      if (!seen[ch]) {
        dfs (ch);
      }
    }
  };
  
  // ===============
  bool ok = true;
  for (ll i = 1; i <= n; i++) {
    if (!seen[i]) {
      ord.clear();
      dfs(i);
      if (((ll)ord.size())&1)
        ok = false;
      for (ll j = 0; j < (ll)ord.size(); j+=2) {
        color[ord[j]] = 1;
        if (j + 1 < (ll)ord.size())
          color[ord[j+1]] = 0;
      }
    }
  }
  if (!ok) {
    cout << "-1\n";
    return;
  }
  Vec<ll> res;
  for (ll i = 1; i <= n; i++) {
    if (color[i] == 0)
      res.pb(a[i]);
  }
  cout << res.size() << '\n';
  for (auto& x : res)
    cout << x << " ";
  cout << "\n";
}
