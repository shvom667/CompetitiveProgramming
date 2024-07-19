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
ll ub(ll x, ll y) {
  return (x + y - 1) / y;
}
void solve() {
  ll n;
  cin >> n;
  Vec<ll> p(n + 1), a(n + 1);
  Vec<ll> adj[n + 1];
  for (ll i = 2; i <= n; i++) {
    cin >> p[i];
    adj[i].pb(p[i]);
    adj[p[i]].pb(i);
  }
  for (ll i = 1; i <= n; i++)
    cin >> a[i];
  // ===============
  Vec<ll> sz(n + 1, 0);
  Vec<ll> cl(n + 1, 0);
  Vec<ll> va(n + 1, 0);
  vector<bool> seen(n+1, false);
  function<void(ll)> dfs = [&] (ll i) {
    seen[i] = true;
    for (auto& ch : adj[i]) {
      if (!seen[ch]) {
        dfs (ch);
        sz[i] += sz[ch];
        va[i] += va[ch];
        cl[i] += cl[ch];
      }
    }
    sz[i]++;
    va[i] += a[i];
    if(sz[i] == 1) {
      cl[i]++;
    }
  };
  dfs(1);
  // ===============
  ll fans = 0;
  for (ll i = 1; i <= n; i++)
    fans = max(fans, ub(va[i], cl[i]));
  cout << fans << "\n";
}
