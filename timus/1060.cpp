
#include<bits/stdc++.h>
using namespace std;
using ll=int;
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
const ll INF=1e9+20;
void solve() {
  Vec<Vec<bool>> g(4, Vec<bool> (4));
  for (ll i = 0; i < 4; i++)
    for (ll j = 0; j < 4; j++) {
      char ch;
      cin >> ch;
      if (ch == 'w')
        g[i][j] = 1;
      else
        g[i][j] = 0;
    }
  auto gi = [&] (Vec<Vec<bool>>& g) {
    ll res = 0;
    for (ll i = 0; i < 4; i++)
      for (ll j = 0; j < 4; j++) {
        ll ind = i * 4 + j;
        if (g[i][j] == 1)
          res += (1ll<<ind);
      }
    return res;
  };
  auto ig = [&] (ll f) {
    Vec<Vec<bool>> res(4, Vec<bool> (4, 0));
    for (ll i = 0; i < 4; i++)
      for (ll j = 0; j < 4; j++) {
        ll ind = i * 4 + j;
        if (f & (1ll<<ind)) {
          res[i][j] = 1;
        }
      }
    return res;
  };
  auto flip = [&] (bool x) {
    if (x == 0)
      return 1;
    return 0;
  };
  auto ng = [&] (Vec<Vec<bool>>& g, ll i, ll j) {
    Vec<Vec<bool>> res(4, Vec<bool> (4, 0));
    res = g;
    res[i][j] = flip(g[i][j]);
    if (i - 1 >= 0) {
      res[i-1][j] = flip(g[i-1][j]);
    }
    if (i + 1 < 4) {
      res[i+1][j] = flip(g[i+1][j]);
    }
    if (j - 1 >= 0) {
      res[i][j-1] = flip(g[i][j-1]);
    }
    if (j + 1 < 4) {
      res[i][j+1] = flip(g[i][j+1]);
    }
    return res;
  };
  Vec<ll> d((1<<16), INF);
  Vec<bool> seen((1<<16), false);
  d[gi(g)] = 0;
  seen[gi(g)] = true;
  queue<ll> Q;
  Q.push(gi(g));
  while (!Q.empty()) {
    ll f = Q.front();
    Q.pop();
    auto gf = ig(f);
    for (ll i = 0; i < 4; i++) {
      for (ll j = 0; j < 4; j++) {
        auto gd = ng(gf, i, j);
        auto ngd = gi(gd);
        if (!seen[ngd]) {
          seen[ngd] = true;
          d[ngd] = min(d[ngd], d[f] + 1);
          Q.push(ngd);
        }
      }
    }
  }
  ll res = min(d[0], d[(1<<16)-1]);
  if (res >= INF)
    cout << "Impossible\n";
  else
    cout << res << "\n";
}
