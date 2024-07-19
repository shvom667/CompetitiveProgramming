
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
ll x[7], y[7];
ll A1, A2, A3;
bool i1, i2;
void solve() {
  cin >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3] >> x[4] >> y[4] >> x[5] >> y[5] >> x[6] >> y[6];
  ll A = (x[2] - x[1]) * (y[2] - y[1]);
  A1 = A2 = A3 = 0;
  ll lc, dc, rc, uc;
  if (true) {
    lc = max(x[1], x[3]);
    rc = min(x[4], x[2]);
    dc = max(y[3], y[1]);
    uc = min(y[4], y[2]);
    if (lc >= x[1] && lc <= x[2] && rc >= x[1] && rc <= x[2] && uc >= y[1] && uc <= y[2] && dc >= y[1] && dc <= y[2] && lc <= rc && uc >= dc) {
      A1 = (rc - lc) * (uc - dc);
    }
  }
  if (true) {
    lc = max(x[1], x[5]);
    rc = min(x[6], x[2]);
    dc = max(y[5], y[1]);
    uc = min(y[6], y[2]);
    if (lc >= x[1] && lc <= x[2] && rc >= x[1] && rc <= x[2] && uc >= y[1] && uc <= y[2] && dc >= y[1] && dc <= y[2] && lc <= rc && dc <= uc) {
      A2 = (rc - lc) * (uc - dc);
    }
  }
  if (true) {
    lc = max({x[3], x[5], x[1]});
    rc = min({x[2], x[4], x[6]});
    dc = max({y[1], y[3], y[5]});
    uc = min({y[2], y[4], y[6]});
    if (lc <= rc && dc <= uc) {
      if (lc >= x[3] && lc <= x[4] && rc >= x[3] && rc <= x[4] && 
          dc >= y[3] && dc <= y[4] && uc >= y[3] && uc <= y[4])
      {
        A3 = (rc - lc) * (uc - dc);
      }

    }
  }
  dbg(A, A1, A2, A3);
  if (A - A1 - A2 + A3 > 0) {
    cout << "Yes\n";
  }else{
    cout<<
      "No\n";
  }
}
