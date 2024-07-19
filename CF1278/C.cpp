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

void solve() {
  ll n;
  cin >> n;
  ll a[n + 1], b[n + 1];
  ll SL, BL, S, B;
  S = B = SL = BL = 0;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    SL += (a[i] == 1);
    BL += (a[i] == 2);
  }
  S += SL;
  B += BL;
  for (ll i = 1; i <= n; i++) {
    cin >> b[i];
    S += b[i] == 1;
    B += b[i] == 2;
  }
  Vec<ll> sj(n+1, 0);
  Vec<ll> bj(n + 1, 0);
  Vec<ll> d(n + 1,0);
  for (ll i = n; i >= 1; i--) {
    sj[i] += b[i] == 1;
    bj[i] += b[i] == 2;
    if (i < n) {
      sj[i] += sj[i + 1];
      bj[i] += bj[i + 1];
    }
  }
  map<ll, ll> mp;
  for (ll i = 1; i <= n; i++) {
    d[i] = bj[i] - sj[i];
  }
  mp[0] = n + 1;
  for (ll i = n; i >= 1; i--) {
    mp[d[i]] = i;
  }
  if (S == B) {
    cout << 0 << "\n";
    return;
  }
  dbg(S, B);
  ll sl, bl;
  sl = SL;
  bl = BL;
  ll fans = 2*n;
  ll diff = sl - bl;
  if (mp.find(diff) != mp.end()) {
    fans = min(fans, mp[diff] - 1);
  }
  if (sl == bl) {
    fans = min(fans, mp[0]  - 1);
  }
  for (ll i = n; i >= 1; i--) {
    if (a[i] == 1) 
      sl--;
    else 
      bl--;
    ll diff = sl - bl;
    if (mp.find(diff) != mp.end()) {
      fans = min(fans, n - i + 1 + mp[diff] - 1);
    }
  }
  cout << fans << "\n";
}
