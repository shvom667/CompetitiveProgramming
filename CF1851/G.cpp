
#include<bits/stdc++.h>
using namespace std;



using ll=long long;

template <typename T>
using Vec = vector<T>;

#define pb push_back

// ============

struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }
    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool same_set(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

// ============

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)solve();
}
struct p4 {
  ll F, S, T, i;
};
void yesno(bool a) {
  if (a) {
    cout << "YES\n";
  }else{
    cout << "NO\n";
  }
}
void solve() {
  ll n, m;
  cin >> n >> m;
  ll h[n];
  for (ll i = 0; i < n; i++) cin >> h[i];
  Vec<ll> adj[n];
  for (ll i = 0; i < m; i++) {
    ll u , v;
    cin >> u >> v;
    --u; --v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  ll q;
  cin >> q;
  Vec<p4> qr;
  for (ll i = 0; i < q; i++) {
    p4 id;
    cin >> id.F >> id.S >> id.T;
    id.F--; id.S--;
    id.T += h[id.F];
    id.i = i;
    qr.pb(id);
  }
  sort(begin(qr), end(qr), [&] (auto a, auto b) {
      return a.T < b.T;
      });
  DSU d(n);
  Vec<ll> vr(n);
  iota(begin(vr), end(vr), 0ll);
  sort(begin(vr),end(vr), [&](ll a, ll b) {
      return h[a] < h[b];
      });
  ll ptr = 0;
  set<ll> alIn;
  Vec<bool> fans(q);
  for (ll i = 0; i < q; i++)  {
    while (ptr < n && h[vr[ptr]] <= qr[i].T) {
      for (auto& u : adj[vr[ptr]]) {
        if (alIn.find(u) != alIn.end()) {
          d.unite(u, vr[ptr]);
        }
      }
      alIn.insert(vr[ptr]);
      ptr++;
    }
    if (d.same_set(qr[i].F, qr[i].S)) {
      fans[qr[i].i] = 1;
    } else {
      fans[qr[i].i] = 0;
    }
  }
  for (ll i = 0; i < q; i++) {
    yesno(fans[i]);
  }
  cout << "\n";
}
