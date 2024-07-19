#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  t = 1;
  while (t--)
    solve();
}

void solve() {
  ll n;
  cin >> n;
  Vec<ll> adj[n + 1];
  Vec<ll> c(n + 1);
  for (ll i = 1; i <= n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  ll ts = 0;
  for (ll i = 1; i <= n; i++) {
    cin >> c[i];
    ts += c[i];
  }
  // ===============

  vector<ll> sum(n + 1, 0);
  vector<bool> seen(n + 1, false);
  Vec<ll> ans(n + 1, 0);
  Vec<ll> dist(n + 1, 0);
  function<void(ll)> dfs = [&](ll i) {
    seen[i] = true;
    for (auto &ch : adj[i]) {
      if (!seen[ch]) {
        dist[ch] = dist[i] + 1;
        dfs(ch);
        sum[i] += sum[ch];
      }
    }
    ans[1] += dist[i] * c[i];
    sum[i] += c[i];
  };

  // ===============
  dfs(1);
  seen = vector<bool> (n + 1, false);
  function<void(ll)> dfs2 = [&] (ll i) {
    seen[i] = true;
    for (auto& ch : adj[i]) {
      if (!seen[ch]) {
        ans[ch] = ans[i] - sum[ch] + ts - sum[ch];
        dfs2(ch);
      }
    }
  };

  dfs2(1);
  ll fans = *min_element(begin(ans) + 1, end(ans));
  cout << fans << '\n';
}
