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
const ll INF = 1e9;
void solve() {
  ll n, m;
  cin >> n >> m;
  char tab[n][m];
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < m; j++)
      cin >> tab[i][j];
  if (min(n, m) >= 4) {
    cout << -1 << "\n";
    return;
  }
  Vec<Vec<char>> g;
  if (m < n) {
    g = Vec<Vec<char>> (m, Vec<char> (n));
    for (ll i = 0; i < n; i++)
      for (ll j = 0; j < m; j++)
        g[j][i] = tab[i][j];
    swap(n, m);
  } else {
    g = Vec<Vec<char>> (n, Vec<char> (m));
    for (ll i = 0; i < n; i++)
      for (ll j = 0; j < m; j++)
        g[i][j] = tab[i][j];
  }
  if (n == 1) {
    cout << 0 << "\n";
  }
  dbg(n, m);
  dbg(g);
  if (n == 2) {
    Vec<ll> v(m, 0);
    for (ll i = 0; i < m; i++) {
      for (ll j = 0; j < n; j++) {
        v[i] += (1<<j)*(g[j][i] - '0');
      }
    }
    Vec<Vec<ll>> dp(m, Vec<ll> (4, INF));
    for (ll j = 0; j < 4; j++)
      dp[0][j] = __builtin_popcount((j^v[0]));
    for (ll i = 1; i < m; i++) {
      for (ll j = 0; j < 4; j++) {
        if (__builtin_popcount(j)%2==1) {
          dp[i][j] = min(dp[i][j], dp[i-1][0] + __builtin_popcount(j^v[i]));
          dp[i][j] = min(dp[i][j], dp[i-1][3] + __builtin_popcount(j^v[i]));
        } else {
          dp[i][j] = min(dp[i][j], dp[i-1][2] + __builtin_popcount(j^v[i]));
          dp[i][j] = min(dp[i][j], dp[i-1][1] + __builtin_popcount(j^v[i]));
        }
      }
    }
    ll fans = INF;
    for (ll j = 0; j < 4; j++)
      fans = min(fans, dp[m-1][j]);
    //for (ll j = 0; j < 4; j++) {
    //  for (ll i = 0; i < m; i++) {
    //    cout << dp[i][j] << " ";
    //  } cout << '\n';
    //}
    cout << fans << "\n";
    dbg(v);
  }
  if (n == 3) {
    Vec<ll> v(m, 0);
    for (ll i = 0; i < m; i++) {
      for (ll j = 0; j < n; j++) {
        v[i] += (1<<j)*(g[j][i] - '0');
      }
    }
    Vec<Vec<ll>> dp(m, Vec<ll> (8, INF));
    for (ll j = 0; j < 8; j++)
      dp[0][j] = __builtin_popcount((j^v[0]));
    for (ll i = 1; i < m; i++) {
      for (ll j = 0; j < 8; j++) {
        if (j == 0) {
          dp[i][j] = min(dp[i][j], dp[i-1][5] + __builtin_popcount(j^v[i]));
          dp[i][j] = min(dp[i][j], dp[i-1][2] + __builtin_popcount(j^v[i]));
        }
        if (j == 1) {
          dp[i][j] = min(dp[i][j], dp[i-1][4] + __builtin_popcount(j^v[i]));
          dp[i][j] = min(dp[i][j], dp[i-1][3] + __builtin_popcount(j^v[i]));
        }
        if (j == 2) {
          dp[i][j] = min(dp[i][j], dp[i-1][7] + __builtin_popcount(j^v[i]));
          dp[i][j] = min(dp[i][j], dp[i-1][0] + __builtin_popcount(j^v[i]));
        }
        if (j == 3) {
          dp[i][j] = min(dp[i][j], dp[i-1][6] + __builtin_popcount(j^v[i]));
          dp[i][j] = min(dp[i][j], dp[i-1][1] + __builtin_popcount(j^v[i]));
        }
        if (j == 4) {
          dp[i][j] = min(dp[i][j], dp[i-1][6] + __builtin_popcount(j^v[i]));
          dp[i][j] = min(dp[i][j], dp[i-1][1] + __builtin_popcount(j^v[i]));
        }
        if (j == 5) {
          dp[i][j] = min(dp[i][j], dp[i-1][7] + __builtin_popcount(j^v[i]));
          dp[i][j] = min(dp[i][j], dp[i-1][0] + __builtin_popcount(j^v[i]));
        }
        if (j == 6) {
          dp[i][j] = min(dp[i][j], dp[i-1][4] + __builtin_popcount(j^v[i]));
          dp[i][j] = min(dp[i][j], dp[i-1][3] + __builtin_popcount(j^v[i]));
        }
        if (j == 7) {
          dp[i][j] = min(dp[i][j], dp[i-1][5] + __builtin_popcount(j^v[i]));
          dp[i][j] = min(dp[i][j], dp[i-1][2] + __builtin_popcount(j^v[i]));
        }
      }
    }
    ll fans = INF;
    for (ll j = 0; j < 8; j++)
      fans = min(fans, dp[m-1][j]);
    //for (ll j = 0; j < 4; j++) {
    //  for (ll i = 0; i < m; i++) {
    //    cout << dp[i][j] << " ";
    //  } cout << '\n';
    //}
    cout << fans << "\n";
    dbg(v);
  }
}
