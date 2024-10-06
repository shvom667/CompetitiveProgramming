#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;


#define dbg(...) 42



auto solve() {
  ll n, fans;
  cin >> n;
  vector<vector<ll>> adj(n+1);
  for (ll i = 1; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    adj[u].pb(v), adj[v].pb(u);
  }
  
  vector<ll> d(n + 1, 0), s(n + 1, 0);
  function<void(ll , ll)> dfs = [&] (ll i, ll p) {
    for (auto& ch : adj[i]) {
      if (ch != p) {
        d[ch] = d[i] + 1;
        dfs(ch, i);
      }
    }
  };

  function<void(ll , ll)> dfs2 = [&] (ll i, ll p) {
    for (auto& ch : adj[i]) {
      if (ch != p) {
        dfs2(ch, i);
        s[i] = max(s[i], s[ch]);
      }
    }
    s[i] = max(s[i], d[i]);
  };


  dfs(1, -1);
  

  dfs2(1, -1);


  dbg(d);
  dbg(s);
  sort(begin(d) + 1, end(d));
  sort(begin(s) + 1, end(s));
  fans=n;
  dbg(d);
  dbg(s);
  for (ll i = 0; i <= n; i++) {
    ll it = end(d) - upper_bound(begin(d),end(d),i);
    ll jt = lower_bound(begin(s),end(s),i)-begin(s)-1;
    dbg(i, it , jt);
    fans = min(fans, it + jt);
  }

  return fans;
}


int main() {

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
