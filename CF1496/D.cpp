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

void solve() {
  ll n;
  cin >> n;
  Vec<ll> a(n);
  for (ll i = 0; i < n; i++)
    cin >> a[i];
  Vec<ll> ps(n, 0);
  Vec<ll> ns(n, 0);
  for (ll i = 1; i < n; i++)
    if (a[i] > a[i-1]) {
      ps[i] = 1 + ps[i-1];
    } else {
      ps[i] = 0;
    }
  for (ll i = n - 2; i >= 0; i--)
    if (a[i + 1] < a[i]) {
      ns[i] = 1 + ns[i + 1];
    } else {
      ns[i] = 0;
    }

  Vec<ll> eq;
  for (ll i = 0; i < n; i++)
    if (ps[i] == ns[i] && ps[i] > 0)
      eq.pb(ps[i]);
  Vec<ll> th;
  for (ll i = 0; i < n; i++) {
    th.pb(ns[i]);
    th.pb(ps[i]);
  }

  dbg(ps);
  dbg(ns);
  dbg(eq);
  if (eq.size() == 0) {
    cout << 0 << '\n';
    return;
  }
  ll M = *max_element(begin(eq), end(eq));
  if (M&1) {
    cout << 0 << '\n';
    return;
  }
  if (count(begin(eq), end(eq), M) >= 2) {
    cout << 0 << '\n';
    return;
  }
  ll MM = *max_element(begin(th), end(th));
  if (MM > M) {
    cout << 0 << "\n";
    return;
  }
  if (count(begin(th), end(th), M) >= 3) {
    cout << 0 << '\n';
    return;
  }
  cout << 1 << "\n";
}
