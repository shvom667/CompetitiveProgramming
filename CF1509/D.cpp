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
  Vec<string> s(3);
  Vec<ll> f(3, 0);
  for (ll i = 0; i < 3; i++) {
    cin >> s[i];
    for (ll j = 0; j < 2*n; j++)
      f[i] += s[i][j] - '0';
  }
  dbg(f);
  Vec<ll> res;
  for (ll k = 0; k < 3; k++)
    for (ll m = k+1; m < 3; m++)
      if (min(f[k], f[m]) >= n) {
        Vec<ll> p1, p2;
        p1.pb(-1);
        p2.pb(-1);
        for (ll i = 0; i < 2 * n;  i++) {
          if (s[k][i] == '1')
            p1.pb(i);
          if (s[m][i] == '1')
            p2.pb(i);
        }
        dbg(k, m);
        dbg(p1, p2);
        for (ll i = 1; i < min((ll)p1.size(), (ll)p2.size()); i++) {
          for (ll j = p1[i - 1] + 1; j < p1[i]; j++)
            res.pb(s[k][j] - '0');
          for (ll j = p2[i - 1] + 1; j < p2[i]; j++)
            res.pb(s[m][j] - '0');
          res.pb(1);
        }
        for (ll j = p1[min(p1.size(), p2.size())-1] + 1; j < 2*n; j++)
          res.pb(s[k][j] - '0');
        for (ll j = p2[min(p1.size(), p2.size())-1] + 1; j < 2*n; j++)
          res.pb(s[m][j] - '0');
        for (auto& x : res)
          cout << x;
        cout << "\n";
        return;
      }
      else if (max(f[k], f[m]) <= n) {
        Vec<ll> p1, p2;
        p1.pb(-1);
        p2.pb(-1);
        for (ll i = 0; i < 2*n;  i++) {
          if (s[k][i] == '0')
            p1.pb(i);
          if (s[m][i] == '0')
            p2.pb(i);
        }
        dbg(k, m);
        dbg(p1, p2);
        for (ll i = 1; i < min((ll)p1.size(), (ll)p2.size()); i++) {
          for (ll j = p1[i - 1] + 1; j < p1[i]; j++)
            res.pb(s[k][j] - '0');
          for (ll j = p2[i - 1] + 1; j < p2[i]; j++)
            res.pb(s[m][j] - '0');
          res.pb(0);
        }
        for (ll j = p1[min(p1.size(), p2.size())-1] + 1; j < 2*n; j++)
          res.pb(s[k][j] - '0');
        for (ll j = p2[min(p1.size(), p2.size())-1] + 1; j < 2*n; j++)
          res.pb(s[m][j] - '0');
        for (auto& x : res)
          cout << x;
        cout << "\n";
        return;
      }
}
