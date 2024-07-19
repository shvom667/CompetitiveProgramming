
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
  Vec<ll> f(n + 1, 0);
  Vec<ll> I[n+1];
  bool ok = true;
  for (ll i = 1; i <= n; i++) {
    ll u, v;
    cin >> u >> v;
    f[u]++;
    f[v]++;
    I[u].pb(i);
    I[v].pb(i);
    if (u==v)
      ok = false;
  }
  if (!ok) {
    cout << "NO\n";
    return;
  }
  for (ll i = 1; i <= n; i++) {
    if (f[i]!=2) {
      cout << "NO\n";
      return;
    }
  }
  Vec<ll> adj[n+1];
  for (ll i = 1; i <= n; i++) {
    adj[I[i][0]].pb(I[i][1]);
    adj[I[i][1]].pb(I[i][0]);
  }

  // ===============
  ll sz = 0;
  Vec<ll> color(n+1, 0);
  vector<bool> seen(n+1, false);
  function<void(ll)> dfs = [&] (ll i) {
    sz++;
    seen[i] = true;
    for (auto& ch : adj[i]) {
      if (!seen[ch]) {
        color[ch] = (color[i]^1);
        dfs (ch);
      }
    }
  };
  
  // ===============
  for (ll j = 1; j <= n; j++) {
    if (!seen[j]) {
      sz = 0;
      dfs(j);
      if (sz&1){
        cout<<"NO\n";
        return;
      }
    }
  }
  dbg(color);
  cout << "YES\n";
}
