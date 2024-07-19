#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;
// =================

// Debugging template
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A> void __print(const A &x);
template <typename A, typename B> void __print(const pair<A, B> &p);
template <typename... A> void __print(const tuple<A...> &t);
template <typename T> void __print(stack<T> s);
template <typename T> void __print(queue<T> q);
template <typename T, typename... U> void __print(priority_queue<T, U...> q);
/*
void __print(Mint x) {
        cerr << x;
}
*/
template <typename A> void __print(const A &x) {
  bool first = true;
  cerr << '{';
  for (const auto &i : x) {
    cerr << (first ? "" : ","), __print(i);
    first = false;
  }
  cerr << '}';
}
template <typename A, typename B> void __print(const pair<A, B> &p) {
  cerr << '(';
  __print(p.first);
  cerr << ',';
  __print(p.second);
  cerr << ')';
}
template <typename... A> void __print(const tuple<A...> &t) {
  bool first = true;
  cerr << '(';
  apply(
      [&first](const auto &...args) {
        ((cerr << (first ? "" : ","), __print(args), first = false), ...);
      },
      t);
  cerr << ')';
}
template <typename T> void __print(stack<T> s) {
  vector<T> debugVector;
  while (!s.empty()) {
    T t = s.top();
    debugVector.push_back(t);
    s.pop();
  }
  reverse(debugVector.begin(), debugVector.end());
  __print(debugVector);
}
template <typename T> void __print(queue<T> q) {
  vector<T> debugVector;
  while (!q.empty()) {
    T t = q.front();
    debugVector.push_back(t);
    q.pop();
  }
  __print(debugVector);
}
template <typename T, typename... U> void __print(priority_queue<T, U...> q) {
  vector<T> debugVector;
  while (!q.empty()) {
    T t = q.top();
    debugVector.push_back(t);
    q.pop();
  }
  __print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
  __print(H);
  if (sizeof...(T))
    cerr << ", ";
  _print(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
  cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = [";              \
  _print(__VA_ARGS__)
#else
#define dbg(...)
#endif

// =================
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
Vec<bool> final;
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
  for (auto &ch : adj[u]) {
    if (ch != p) {
      dfs2(ch, u);
      final[u] = (final[u] || final[ch]);
    }
  }
  final[u] = (final[u] || (subtree_xor[u] == total_xor));
}

set<ll> total_seen;
set<ll> awtx;
void dfs3(ll u, ll p) {
  seen[u] = true;
  if (awtx.size() < total_seen.size()) {
    ok = true;
  }
  if (subtree_xor[u] == total_xor) {
    awtx.insert(u);
  }
  for (auto &ch : adj[u]) {
    if (ch != p) {
      dfs3(ch, u);
    }
  }
  if (awtx.find(u) != awtx.end()) {
    awtx.erase(u);
  }
  if (subtree_xor[u] == total_xor) {
    total_seen.insert(u);
  }
}

void solve() {

  cin >> n >> k;

  adj = Vec<Vec<ll>>(n + 1);
  a = Vec<ll>(n + 1);
  seen = Vec<bool>(n + 1, false);
  subtree_xor = Vec<ll>(n + 1, 0);
  subtree_size = Vec<ll>(n + 1, 0);
  final = Vec<bool>(n + 1, false);
  total_seen.clear();
  awtx.clear();
  total_xor = 0;
  ok = false;

  for (ll i = 1; i <= n; i++)
    cin >> a[i];

  for (ll i = 1; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    adj[u].pb(v), adj[v].pb(u);
  }

  dfs1(1, -1);
  total_xor = subtree_xor[1];
  dbg(total_xor);
  if (total_xor == 0) {
    cout << "YES\n";
    return;
  }
  if (k <= 2) {
    cout << "NO\n";
    return;
  }
  seen = Vec<bool>(n + 1, false);
  dfs2(1, -1);
  for (ll i = 1; i <= n; i++) {
    if (final[i] && subtree_xor[i] == 0)
      ok = true;
  }
  seen = Vec<bool>(n + 1, false);
  dfs3(1, -1);
  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
