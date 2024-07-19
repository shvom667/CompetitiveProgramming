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
using pl = pair<ll, ll>;
const ll N = 210;
const ll M = 27;
bool dp[N][M][M];
pl back[N][M][M];
ll ic (char i) {
  return i - 'a' + 1;
}
void solve() {
  for (ll i = 0; i < N; i++)
    for (ll j = 0; j < M; j++)
      for (ll k = 0; k < M; k++)
        dp[i][j][k] = 0;
  ll n;
  cin >> n;
  string s;
  cin >> s;
  s = "$" + s;
  dp[0][0][0] = 1;
  for (ll i = 1; i <= n; i++)
    for (ll j = 0; j < M; j++)
      for (ll k = 0; k < M; k++)
        for (ll l = 0; l < M; l++)
          for (ll m = 0; m < M; m++) {
            if (dp[i-1][l][m] && l <= j && m <= k) {
              if (j == ic(s[i])) {
                if (k == m) {
                  dp[i][j][k] = true;
                  back[i][j][k] = {l, m};
                }
              }
              if (k == ic(s[i])) {
                if (j == l) {
                  dp[i][j][k] = true;
                  back[i][j][k] = {l, m};
                }
              }
            }
          }
  ll si , sj;
  bool ok = false;
  for (ll i = 0; i < M; i++)
    for (ll j = 0; j < M; j++) {
      if (dp[n][i][j] == 1) {
        ok = true;
        si = i;
        sj = j;
      }
    }
  if (!ok)
    cout << "NO\n";
  else {
    dbg(si, sj);
    cout << "YES\n";
    Vec<ll> res(n + 1, 0);
    for (ll i = n; i >= 1; i--) {
      auto [pi, pj] = back[i][si][sj];
      if (si == ic(s[i])) {
        res[i] = 1;
      }
      si = pi, sj = pj;
      dbg(i, pi, pj);
    }
    for (ll i = 1; i <= n; i++)
      cout << res[i];
    cout << "\n";
    string a = "", b =  "";
    for (ll i = 1; i <= n; i++) {
      if (res[i] == 1)
        a += s[i];
      else 
        b += s[i];
    }
  }
}
