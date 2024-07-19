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
  Vec<ll> adj[n + 1];
  for (ll i = 1; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    adj[u].pb(v), adj[v].pb(u);
  }

  // ===============
  Vec<ll> ans(n + 1, 0);
  Vec<ll> sz(n + 1, 0);
  vector<bool> seen(n+1, false);
  function<void(ll)> dfs = [&] (ll i) {
    seen[i] = true;
    for (auto& ch : adj[i]) {
      if (!seen[ch]) {
        dfs (ch);
        sz[i] += sz[ch];
        ans[i] += ans[ch];
      }
    }
    sz[i]++;
    ans[i] += sz[i];
  };
  
  // ===============
  dfs(1);


  // ===============
  ll fans = ans[1];
  vector<bool> seen2(n+1, false);
  function<void(ll)> dfs2 = [&] (ll i) {
    seen2[i] = true;
    fans = max(fans, ans[i]);
    for (auto& ch : adj[i]) {
      if (!seen2[ch]) {
        ll ansi = ans[i];
        ll szi = sz[i];
        ll ansch = ans[ch];
        ll szch = sz[ch];
        sz[i] = n - szch;
        sz[ch] = n;
        ans[i] = ans[i] - n + sz[i] - ansch;
        ans[ch] = ansch - szch + n + ans[i];
        dfs2 (ch);
        ans[i] = ansi;
        sz[i] = szi;
        sz[ch] = szch;
        ans[ch] = ansch;
      }
    }

  };

  // ===============
  dfs2(1);
  cout << fans << "\n";
}
