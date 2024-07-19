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
bool is_sorted(Vec<ll> x) {
  Vec<ll> y = x;
  sort(begin(y), end(y));
  return x == y;
}
ll ub(ll x, ll y) {
  return (x + y - 1) / y;
}
const ll INF64 = 1e18;
void solve() {
  ll n, m, x, k, y;
  cin >> n >> m >> x >> k >> y;
  Vec<ll> a(n + 2), b(m), ind(n + 2), p;
  a[0] = -INF64;
  a[n+1] = -INF64;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    ind[a[i]] = i;
  }
  p.pb(0);
  for (ll i = 0; i < m; i++) {
    cin >> b[i];
    p.pb(ind[b[i]]);
  }
  p.pb(n+1);
  if (!is_sorted(p)) {
    cout << -1 << "\n";
    return;
  }
  bool ok = true;
  ll fans = 0;
  for (ll i = 1; i < p.size(); i++) {
    Vec<ll> ci, gi;
    ll M;
    M = max(a[p[i-1]], a[p[i]]);
    for (ll j = p[i-1] + 1; j <= p[i] - 1; j++) {
      ci.pb(j);
      if (a[j] > M)
        gi.pb(j);
    }
    if (ci.empty()) continue;
    ll ans = INF64;
    for (ll xu = 0; xu <= ci.size(); xu++) {
      ll cur = 0;
      if (xu == 0) {
        if(gi.size())
          cur = INF64;
        else {
          cur = ci.size() * y;
        }
      }
      else {
        if (ci.size() >= xu * k) {
          cur += x * xu;
          cur += (ci.size() - xu * k) * y;
        } else {
          cur = INF64;
        }
      }
      ans = min(ans, cur);
    }
    if (ans == INF64)
      ok = false;
    fans += ans;
  }

  if (!ok) {
    cout << -1 << '\n';
    return;
  }
  cout << fans << '\n';
}
