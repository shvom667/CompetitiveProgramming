#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;
  while (t--)
    solve();
}

ll n, k, total_xor;
Vec<bool> seen;
Vec<ll> a;
Vec<Vec<ll>> adj;
Vec<ll> subtree_xor;
Vec<ll> subtree_size;
bool ok; // to check 2nd case

void dfs1(ll u, ll p) {
  seen[u] = true;
  for (auto &ch : adj[u]) {
    if (ch != p) {
      dfs1(ch, u);
      subtree_xor[u] ^= subtree_xor[ch];
      subtree_size[u] += subtree_size[ch];
    }
  }
  subtree_xor[u] ^= a[u];
  subtree_size[u]++;
}

void dfs2(ll u, ll p) {
  seen[u] = true;
  ll subtree_xor_u = subtree_xor[u];
  ll out_of_subtree_xor_u = total_xor ^ subtree_xor_u;
  if (subtree_xor_u == 0 && subtree_size[u] > 1) {
    ok = true;
  }
  if (out_of_subtree_xor_u == 0 && n - subtree_size[u] > 1) {
    ok = true;
  }
  for (auto &ch : adj[u]) {
    if (ch != p) {
      dfs2(ch, u);
    }
  }
}

void solve() {

  cin >> n >> k;

  adj = Vec<Vec<ll>>(n + 1);
  a = Vec<ll>(n + 1);
  seen = Vec<bool>(n + 1, false);
  subtree_xor = Vec<ll>(n + 1, 0);
  subtree_size = Vec<ll>(n + 1, 0);

  for (ll i = 1; i <= n; i++)
    cin >> a[i];

  for (ll i = 1; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    adj[u].pb(v), adj[v].pb(u);
  }

  dfs1(1, -1);

  total_xor = subtree_xor[1];

  if (total_xor == 0) {
    cout << "YES\n";
    return;
  }

  if (k <= 2) {
    cout << "NO\n";
    return;
  }
  seen = Vec<bool>(n + 1, false);
  ok = false;
  dfs2(1, -1);
  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
