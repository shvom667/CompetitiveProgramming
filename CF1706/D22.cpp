
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
#define SZ(x) (ll)x.size()
// =================

// Debugging template
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
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
	cout << x;
}
*/
template <typename A>
void __print(const A &x) {
	bool first = true;
	cout << '{';
	for (const auto &i : x) {
		cout << (first ? "" : ","), __print(i);
		first = false;
	}
	cout << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p) {
	cout << '(';
	__print(p.first);
	cout << ',';
	__print(p.second);
	cout << ')';
}
template <typename... A>
void __print(const tuple<A...> &t) {
	bool first = true;
	cout << '(';
	apply([&first](const auto & ...args) { ((cout << (first ? "" : ","), __print(args), first = false), ...); }, t);
	cout << ')';
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
void _print() { cout << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
	__print(H);
	if (sizeof...(T))
		cout << ", ";
	_print(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cout << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dbg(...)
#endif

// =================
vector<pair<int, int>> floorrange(int n) {
    int L = 1;
    vector<pair<int, int>> ans;
    while (L <= n) {
        int R = n / (n / L);
        ans.push_back({L, R});
        L = R + 1;
    }
    ans.push_back({n + 1, n + 1});
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  t = 1;
  while (t--) solve();
}
const ll N=1e5;
Vec<ll> g[N];
Vec<ll> gg[N];
void solve() {
  for (ll i = 1; i <= N; i++) {
    auto res = floorrange(i);
    for (auto& [u,v] : res) {
      g[i/u].pb(i);
    }
  }
  set<ll> s;
  //dbg(SZ(g[5]));
  //dbg(g[5]);
  ll fans = 0;
  for (ll i = 1; i <= N; i++) {
    //dbg(g[i].size());
    fans += g[i].size();
  }
  for (ll i = 1; i <= N; i++) {
    for (ll k = 1; (k <= i + 1 && k * i <= N); k++) {
      for (ll mod = 0; (mod < k && k * i + mod <= N); mod++) {
        gg[i].push_back(i * k + mod);
      }
    }
    if ( (i + 2) * i< N)
    while (gg[i].back() < N)
      gg[i].pb(gg[i].back() + 1);
  }
  dbg(gg[10]);
  for (ll i = 1; i <= 100000; i++) {
    if (g[i] != gg[i]) {
      assert(false);
    }
  }
  dbg(g[1]);
}
