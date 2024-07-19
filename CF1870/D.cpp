
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
  cin >> t; 
  while (t--) solve();
}
using pl = pair<ll, ll>;
void solve() {
  ll n, k;
  cin >> n;
  Vec<ll> c(n + 1), a(n + 1, 0);
  Vec<pl> C;
  for (ll i = 1; i <= n; i++) {
    cin >> c[i];
  }
  cin >> k;
  pl b;
  b.first = c[n];
  b.second = n;
  C.pb(b);
  for (ll i = n - 1; i >= 1; i--) {
    if (c[i] < C.back().first) {
      C.pb({c[i], i});
    }
  }
  reverse(begin(C), end(C));
  ll N = C.size();
  Vec<ll> res(N);
  dbg(C);
  res[0] = k / C[0].first;
  ll left = k % C[0].first;
  dbg(res[0], left);
  for (ll i = 1; i < N; i++)  {
    ll l, r;
    l = 0, r = res[i-1];
    while (l <=r ) {
      ll mid = l + (r - l) / 2;
      bool ok = false;
      ok =( mid * C[i].first <= left + (mid * C[i-1].first));
      if (ok) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    res[i] = r;
    res[i-1] -= r;
    ll ch = r * (C[i-1].first) + left;
    left = ch - C[i].first * r;
  }
  dbg(res);
  for (ll i = 0; i < N; i++) {
    a[C[i].second] += res[i];
  }
  for (ll i = n; i >= 1; i--) {
    if (i < n)
      a[i] += a[i+1];
  }
  for (ll i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
}
