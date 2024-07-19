#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
#define SZ(x) (ll)x.size()
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
  ll k1, k2, k3;
  cin >> k1 >> k2 >> k3;
  Vec<ll> a(k1), b(k2), c(k3), bc;
  for (auto& x : a)
    cin >> x;
  for (auto& x : b)
    cin >> x;
  for (auto& x : c)
    cin >> x;
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  sort(begin(c), end(c));
  ll fans = min({SZ(a)+SZ(b), SZ(b) + SZ(c), SZ(c) + SZ(a)});
  for (auto& x : b) {
    bc.pb(x);
  }
  for (auto& x : c) {
    bc.pb(x);
  }
  sort(begin(bc), end(bc));
  Vec<ll> d(SZ(bc), 0);
  for (ll i = SZ(d) -1 ; i >= 0; i--) {
    if (binary_search(begin(b), end(b), bc[i])) {
      d[i] = 1;
    } else {
      d[i] = 0;
    }
  }
  Vec<ll> r1(SZ(d), 0), r0(SZ(d), 0), r(SZ(d),0), t0(SZ(d), 0);
  for (ll i = SZ(d)-1; i >= 0; i--) {
    if (d[i] == 1) {
      r1[i]++;
    } else {
      t0[i]++;
      r0[i]++;
    }
    if (i + 1 < SZ(d)) {
      r1[i] += r1[i + 1];
      r0[i] += r0[i + 1];
      t0[i] += t0[i + 1];
    }
  }
  for (ll i = SZ(d) - 1; i >= 0; i--) {
    r[i] = r1[i] - r0[i];
  }
  dbg(r);
  for (ll i = SZ(d) - 1; i >= 0; i--) {
    if (i + 1 < SZ(d))
      r[i] = min(r[i], r[i + 1]);
  }
  dbg(r);
  for (ll i = 0; i < SZ(d); i++) {
    auto it = upper_bound(begin(a), end(a), bc[i] - 1);
    ll ind = it - begin(a);
    ll v2 = SZ(a) - ind;
    ll v3 = bc[i] -1 - ind;
    dbg(i, bc[i], v2, v3, v2 + v3 + t0[i] + r[i]);
    fans = min(fans, v2 + v3 + t0[i] + r[i]);
  }
  cout << fans << "\n";
}
