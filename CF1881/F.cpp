
#include<bits/stdc++.h>
using namespace std;



using ll=long long;

template <typename T>
using Vec = vector<T>;

#define pb push_back

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)solve();
}
const ll INF64 = 1e15;
void solve() {
  ll n, k;
  cin >> n >> k;
  Vec<ll> col(n + 1, 0);
  for (ll j=0; j<k; j++) {
    ll x;
    cin >> x;
    col[x] = 1;
  }
  Vec<ll> adj[n+1];
  for (ll i = 0; i < n - 1; i++)  {
    ll u, v;
    cin >> u >> v;
    adj[u].pb(v), adj[v].pb(u);
  }

// ===============

  vector<bool> seen(n+1, false);
  Vec<ll> f(n+1, 0);
  Vec<ll> h(n+1, 0);
  Vec<ll> bc(n+1, 0);
  function<void(ll)> dfs = [&] (ll i) {
  	seen[i] = true;
    ll cc[2];
    cc[0] = cc[1] = 0;
  	for (auto& ch : adj[i]) {
  		if (!seen[ch]) {
  			dfs (ch);
        ll c=-INF64;
        c = max(c, f[ch] > 0 ? f[ch] + 1 : 0ll);
        if (col[ch] == 1) {
          c = max(c, 1ll);
        }
        f[i] = max(f[i], c);
        if (f[i] == c) {
          bc[i] = ch;
        }
        if (cc[1] < c) {
          cc[1] = c;
        }
        if (cc[1] > cc[0]) swap(cc[1], cc[0]);
  		}
  	}
    h[i] = cc[1];
  };
  dfs(1);
// ===============
  Vec<ll> g(n+1, 0);

// ===============

  function<void(ll, ll)> df = [&] (ll i, ll p) {
  	for (auto& ch : adj[i]) {
  		if (ch != p) {
        g[ch] = max( (g[i] > 0 ? g[i] + 1 : 0ll), g[ch]);
        if (col[i] == 1) {
          g[ch] = max(g[ch], 1ll);
        }
        g[ch] = max(g[ch], (h[i]>0?h[i]+1:0ll));
        if (bc[i] != ch) {
          g[ch] = max(g[ch], (f[i] > 0 ? f[i] + 1 : 0ll));
        }
  			df (ch, i);
  		}
  	}
  };
  df(1,0);
// ===============

  Vec<ll> res(n+1, 0);
  for (ll i = 1; i <= n; i++) {
    res[i] = max(f[i], g[i]);
  }
  ll fans = INF64;
  for (ll i = 1; i <= n; i++) {
    fans=min(fans, res[i]);
  }
  cout<<fans<<'\n';
}
