#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
ll gcd(ll x, ll y) {
	if (x == 0 || y == 0) return max(x, y);
	return __gcd(x,y);
}
auto solve(ll n, vector<ll> a) {
	ll fans = 0;
	sort(begin(a), end(a));
	vector<ll> ans;
	ans.pb(a[0]);
	
	fans += a[0];
	dbg(a);
	ll pg = a[0];
	set<ll> s;
	for (ll i = 1; i < n; i++) {
		s.insert(a[i]);
	}
	if (s.find(a[0]) != s.end())
		s.erase(a[0]);
	for (ll i = 1; i < n; i++) {
		ll cg = pg;
		ll mv = -1;
		for (auto&v : s) {
			ll cur_ans = gcd(pg, v);
			cg = min(cg, cur_ans);
			if (cg == cur_ans) {
				mv = v;
			}

		}
		dbg(i, cg);
		if (s.find(mv) != s.end()) {
			s.erase(mv);
		}
		if (cg == pg) {
			fans += (n - i) * pg;
			break;
		} else {
			assert(cg < pg);
			pg = cg;
			fans += pg;
		}
	}
	
	
	return fans;
}

auto bf(ll n, vector<ll> a) {
	sort(begin(a),end(a));
	
	
	ll fgcd = INF;
	do {
		ll sum = 0;
		ll cur_gcd = a[0];
		sum += cur_gcd;
		for (ll i = 1; i < n; i++){
			cur_gcd = gcd(cur_gcd, a[i]);
			sum += cur_gcd;
		}
		fgcd = min(fgcd, sum);
	} while (next_permutation(begin(a),end(a)));
	return fgcd;
}
void stress() {
while(true){
	ll n = rand()%10 + 1;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		a[i] = rand()%100 + 2; 
	}
	sort(begin(a),end(a));
	
	auto sans = solve(n, a);
	auto bans = bf(n, a);
	if (sans == bans) {
		cout << "ok\n";
	} else {
		dbg(a);
		dbg(n);
		exit(0);
	}
}
}
int main() {
	//~ stress();
	//~ return 0;
	
	
	ll T;
	cin >> T;
	while (T--) {
		ll n;
		cin >> n;
		vector<ll> a(n);
		for(ll i = 0; i < n; i++) {
			cin >> a[i];
		}
		auto sans = solve(n, a);
		//~ auto bans = bf(n, a);
		cout << sans << "\n";
		//~ cout << sans << " " << bans << '\n';
	}
}
