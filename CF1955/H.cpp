#define ONLINE_JUDGE
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
ll p3[14];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  p3[0] = 1;
  for (ll i = 1; i <= 13; i++) {
    p3[i] = p3[i-1] * 3;
  }
  p3[0]=0;
  while (t--) solve();
}
const ll M=13;
const ll N = (1ll<<13) + 1;
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  char g[n][m];
  for (ll i = 0; i < n; i++) for (ll j = 0; j < m; j++) cin >> g[i][j];

  Vec<ll> tx(k), ty(k), d(k);
  for (ll i = 0; i < k; i++) {
    cin >> tx[i] >> ty[i] >> d[i];
    tx[i]--;
    ty[i]--;
  }

  ll cc[k][M+1];

  for (ll i = 0; i < k; i++)
    cc[i][0] = 0;

  for (ll i = 0; i < k; i++) {
    for (ll r = 0; r <= M; r++) {
      ll cnt=0;
      for (ll x = 0; x < n; x++){
        for (ll y = 0; y < m; y++) {
        if (
            (x-tx[i])*(x-tx[i]) + (y-ty[i])*(y-ty[i]) <= r * r
            &&
            g[x][y]=='#'
            ) cnt++;
        }
      }
      cc[i][r] =cnt;
    }
  }
  ll cd[k][M+1];

  for (ll i = 0; i < k; i++) for (ll r = 0; r <= M; r++) {
    cd[i][r] = p3[r] - cc[i][r] * d[i];
  }

  ll dp[k][N];
  for (ll i = 0; i < k; i++) {
    for (ll j = 0; j < N; j++) {
      dp[i][j] = 1e18;
    }
  }

  for (ll j = 0; j < N; j++) {
    if (__builtin_popcount(j) == 1) {
      for (ll b = 0; b <= 13; b++) {
        if (j & (1ll<<b)) {
          dp[0][j] = cd[0][b];
        }
      }
    }
  }

  for (ll i = 1; i < k; i++) {
    for (ll j = 1; j < N; j++) {
      dp[i][j] = min(dp[i][j], dp[i-1][j]);
      for (ll b = 1; b <= M; b++) {
        if (j & (1ll<<b)) {
          dp[i][j] = min(dp[i][j], dp[i-1][(j^(1ll<<b))] + cd[i][b]);
        }
      }
    }
  }
  
  ll fans=1e18;
  for (ll i = 0; i < k; i++) for (ll j = 0; j < N; j++)
    fans=min(fans,dp[i][j]);

  cout << max(0ll, -fans) << "\n"; 
}

