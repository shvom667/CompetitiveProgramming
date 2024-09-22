#include<bits/stdc++.h>
using namespace std;
using ll = long long;
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

const ll INF = 1e18;
auto solve() {
	ll n;
	cin >> n;
	ll m = INF;
	vector<ll> a(n + 1);
	ll sum = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		m = min(m, sum/i);
		dbg(sum, i);
	}
	ll l = 0, r = 1e17;
	dbg(m);
	auto cond = [&] (ll mid) {
			vector<ll> b = a;
			for (ll i = 1; i <= n; i++) {
				b[i] -= m;
			}
			ll xtra = 0;
			for (ll i = 1; i <= n; i++) {
				if (xtra + b[i] > mid) {
					xtra = xtra + b[i] - mid;
				} else {
					xtra = 0;
				}
				dbg(xtra, i);
			}
			dbg(b, xtra);
			return xtra <= 0;
	};
	//~ cout << cond(0) << "\n";
	//~ cout << cond(1) << '\n';
	//~ cout << cond(2) << '\n';
	//~ cout << cond(3) << '\n';
	//~ cout << cond(4) << '\n';
	//~ return;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		
		if (cond(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	dbg(l);
	cout << l << "\n";
}

int main() {
	
	ll T;
	cin >> T;
	while (T--) {
		solve();
	}
}
