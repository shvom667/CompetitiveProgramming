#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

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
  while (t--) solve();
}
const ll N = 100;
void solve() {
  ll n, m;
  cin >> n >> m;
  Vec<Vec<ll>> id(n, Vec<ll> (m, 0));
  Vec<Vec<ll>> g[N];
  for (ll i = 0; i < N; i++)
    g[i] = id;
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < m; j++) {
      char c;
      cin >> c;
      g[0][i][j] = c - '0';
    }

  auto valid = [&] (ll x, ll y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
  };
  set<Vec<Vec<ll>>> s;
  s.insert(g[0]);
  Vec<ll> dx = {1, -1, 0, 0};
  Vec<ll> dy = {0, 0, 1, -1};
  for (ll i = 1; i < N; i++) {
    for (ll r_itr = 0; r_itr < n; r_itr++)
      for (ll c_itr = 0; c_itr < m; c_itr++) {
        bool ok = false;
        for (ll k = 0; k < 4; k++) {
          ll nx, ny;
          nx = r_itr + dx[k];
          ny = c_itr + dy[k];
          if (valid(nx, ny)) {
            if (g[i-1][nx][ny] == g[i-1][r_itr][c_itr])
              ok = true;
          }
        }
        g[i][r_itr][c_itr] = g[i-1][r_itr][c_itr];
        if (ok)
          g[i][r_itr][c_itr] ^= 1;
      }
    if (s.find(g[i]) != s.end()) {
      dbg(i);
    }
    s.insert(g[i]);
  }

  for (ll gn = 0; gn < N; gn++) {
    cout << "Printing the grid : " << gn << "\n";
    for (ll i = 0; i < n; i++)
      for (ll j = 0; j < m; j++)
        cout << g[gn][i][j] << " \n"[j == m-1];
    cout << "\n";
  }

}
