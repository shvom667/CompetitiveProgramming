
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
  ll n, x, y;
  cin >> n >> x >> y;
  Vec<ll> v(x);
  for (auto& p : v) cin >> p;
  sort(begin(v), end(v));
  Vec<ll> in;
  ll fans = 0;
  fans += x + y - 2;
  ll c1 = 0;
  ll c2 = 0;
  for (ll i = 1; i < x; i++)  {
    in.pb(v[i] - v[i - 1]);
  }
  in.pb(v[0] + n - v[x - 1]);
  priority_queue<ll, Vec<ll>, greater<ll>> ein, oin;
  for(auto& p : in) {
    if (p == 2) c2++;
    if (p == 1) c1++;
    if (p > 2) {
      if (p%2==0) {
        ein.push(p);
      } else {
        oin.push(p);
      }
    }
  }
  ll tp = y;
  dbg(in);
  while (!ein.empty() && tp > 0) {
    ll f = ein.top();
    ein.pop();
    if (f == 2) {
      c2++;
      continue;
    } else {
      ll min_sub = tp;
      min_sub = min(min_sub, f / 2 - 1);
      tp -= min_sub;
      if (min_sub == f / 2 -1) {
        c2 += f / 2;
      } else {
        c2 += min_sub;
        ein.push(f - 2 * min_sub);
      }
    }
  }
  dbg(ein);
  dbg(c2);
  dbg(tp);
  while (!oin.empty() && tp) {
    ll f = oin.top();
    oin.pop();
    if (f == 1)  {
      c1++;
      continue;
    } else {
      ll min_sub = tp;
      min_sub = min(tp, f/2);
      tp -= min_sub;
      c2 += min_sub;
      f -= min_sub * 2;
      oin.push(f);
    }
  }
  dbg(fans);
  dbg(oin);
  dbg(c2);
  dbg(tp);
  cout << fans + c2 - tp << '\n';
}
