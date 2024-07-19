#include <bits/stdc++.h>
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
template <typename A>
void __print(const A &x);
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename... A>
void __print(const tuple<A...> &t);
template <typename T>
void __print(stack<T> s);
template <typename T>
void __print(queue<T> q);
template <typename T, typename... U>
void __print(priority_queue<T, U...> q);
/*
void __print(Mint x) {
	cerr << x;
}
*/
template <typename A>
void __print(const A &x) {
	bool first = true;
	cerr << '{';
	for (const auto &i : x) {
		cerr << (first ? "" : ","), __print(i);
		first = false;
	}
	cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p) {
	cerr << '(';
	__print(p.first);
	cerr << ',';
	__print(p.second);
	cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t) {
	bool first = true;
	cerr << '(';
	apply([&first](const auto & ...args) { ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
	cerr << ')';
}
template <typename T>
void __print(stack<T> s) {
	vector<T> debugVector;
	while (!s.empty()) {
		T t = s.top();
		debugVector.push_back(t);
		s.pop();
	}
	reverse(debugVector.begin(), debugVector.end());
	__print(debugVector);
}
template <typename T>
void __print(queue<T> q) {
	vector<T> debugVector;
	while (!q.empty()) {
		T t = q.front();
		debugVector.push_back(t);
		q.pop();
	}
	__print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q) {
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
#define dbg(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dbg(...)
#endif

// =================
void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  t = 1;
  while (t--)
    solve();
}
Vec<ll> dx = {1, -1, 0, 0};
Vec<ll> dy = {0, 0, 1, -1};
using pl = pair<ll, ll>;
const ll INF = 1e9;
void solve() {
  ll n, m, qq;
  cin >> n >> m >> qq;
  Vec<Vec<ll>> g(n, Vec<ll>(m, 0));
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < m; j++) {
      char c;
      cin >> c;
      g[i][j] = c - '0';
    }

  auto valid = [&](ll x, ll y) { return (x >= 0 && x < n && y >= 0 && y < m); };
  Vec<pl> good;
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < m; j++) {
      bool ok = false;
      for (ll k = 0; k < 4; k++) {
        ll nx, ny;
        nx = i + dx[k];
        ny = j + dy[k];
        if (valid(nx, ny)) {
          if (g[i][j] == g[nx][ny])
            ok = true;
        }
      }
      if (ok)
        good.pb({i,j});
    }
  if (good.size() == 0) {
    while (qq--) {
      ll r, c, x;
      cin >>  r >> c >> x;
      cout << g[r-1][c-1] << "\n";
    }
    return;
  }
  dbg(good);

  Vec<Vec<ll>> f(n, Vec<ll> (m, INF));
  Vec<Vec<bool>> seen(n, Vec<bool> (m, false));
  queue<pl> Q;
  for (auto& [u, v] : good) {
    f[u][v] = 0;
    seen[u][v] = true;
    Q.push({u,v});
  }
  while (!Q.empty()) {
    pl foo = Q.front();
    Q.pop();
    for (ll k = 0; k < 4; k++) {
      ll nx, ny;
      nx = foo.first + dx[k];
      ny = foo.second + dy[k];
      if (valid(nx,ny) && !seen[nx][ny]) {
        seen[nx][ny] = true;
        f[nx][ny] = f[foo.first][foo.second] + 1;
        Q.push({nx, ny});
      }
    }
  }
  //for (ll i = 0; i < n; i++)
  //  for (ll j = 0; j < m; j++)
      //cout << f[i][j] << " \n"[j == m - 1];
  while (qq--) {
    ll r, c, K;
    cin >> r >> c >> K;
    r--; c--;
    if (K <= f[r][c]) {
      cout << g[r][c] << "\n";
      continue;
    }
    if (K > f[r][c]) {
      ll res = g[r][c];
      if ((K-f[r][c]) % 2== 1)
        res ^= 1;
      cout << res << '\n';
      continue;
    }
  }
}

