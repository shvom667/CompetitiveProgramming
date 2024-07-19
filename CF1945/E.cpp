#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
using pl = pair<ll, ll>;
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

void solve() {
  ll n, k;
  cin >> n >> k;
  ll a[n+2];
  ll b[n + 2];
  ll M = (n+2)/2;
  ll pos = -1;
  Vec<ll> gp,sp;
  bool sorted = true;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i] > k;
    if (a[i] == k) pos = i;
    if (a[i] > k) gp.pb(i);
    if (a[i] < k) sp.pb(i);
  }
  for (ll i = 2; i <= n; i++) {
    if (b[i] >= b[i-1]) {

    } else {
      sorted = false;
    }
  }
  Vec<pl> res;
  ll npos;
  if(sorted) {
    cout << 1 << "\n";
    cout << pos << " " << sp.size() + 1 << "\n";
    return;
  }
  npos = pos;
  if (a[M] == k) {
  }
  if (a[M] > k) {
    if (pos < M) {
      res.pb({n,pos});
      swap(a[n], a[pos]);
      npos = n;
    } else {
    }
  }
  dbg(a[M]);
  if (a[M] < k) {
    if (pos > M) {
      res.pb({1,pos});
      swap(a[1], a[pos]);
      npos = 1;
    }
  }
  ll l = 1, r = n + 1;
  bool llast = true;
  while (r-l>1) {
    ll mid = (l + r) / 2;
    if (a[mid] <= k) {
      l = mid;
      llast = true;
    } else {
      r = mid;
      llast = false;
    }
  }
  if (true ) {
    res.pb({npos, l});
  }
  cout << res.size() << "\n";
  for (auto& [u, v] : res) {
    cout << u << " " << v << "\n";
  }
}
