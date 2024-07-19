
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
const ll N = 1e3+10;
char tab[N][N];
void solve() {
  ll n, m;
  cin >> n >> m;
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= n; j++)
      cin >> tab[i][j];
  bool b = false;
  Vec<ll> B;
  B.pb(-11), B.pb(-1);
  for (ll i = 1; i <= n; i++)
    for (ll j = i + 1; j <= n; j++)
      if (tab[i][j] == tab[j][i])
        B[0] = i, B[1] = j, b = true;

  if (b) {
    cout << "YES\n";
    for (ll i = 1; i <= m + 1; i++) {
      cout << B[i&1]  << " ";
    }
    cout << '\n';
    return;
  }

  if (n == 2) {
    if (m&1) {
      cout << "YES\n";
      for (ll i = 1; i <= m + 1; i++) {
        if (i&1) {
          cout << 1 << " ";
        } else {
          cout << 2 << " ";
        }
      }
      cout << "\n";
    } else {
      cout << "NO\n";
      return;
    }
  }
  if (n >= 3) {
    cout << "YES\n";
    if (m&1) {
      for (ll i = 1; i <= m + 1; i++) {
        if (i&1) {
          cout << 1 << " ";
        } else {
          cout << 2 << " ";
        }
      }
      cout << "\n";
    } else {
      Vec<ll> v(3, 0);
      for (ll j = 1; j <= 3; j++) {
        if (j == 1) {
          if (tab[2][1] == tab[1][3]) {
            dbg("Hi : " ,j);
            v[1] = 1;
            v[0] = 2;
            v[2] = 3;
          }
        }
        if (j == 2) {
          if (tab[1][2] == tab[2][3]) {
            dbg("Hi : " ,j);
            v[1] = 2;
            v[0] = 1;
            v[2] = 3;
          }
        }
        if (j == 3) {
          if (tab[1][3] == tab[3][2]) {
            dbg("Hi : " ,j);
            v[1] = 3;
            v[0] = 2;
            v[2] = 1;
          }
        }
      }
      dbg(v);
      if (m % 4 == 0) {
        Vec<ll> res;
        res.pb(v[1]);
        for (ll j = 0; j < m / 4; j++) {
          res.pb(v[2]);
          res.pb(v[1]);
          res.pb(v[0]);
          res.pb(v[1]);
        }
        for (auto& x : res) {
          cout << x << " ";
        } cout << "\n";
      }
      if (m % 4 == 2) {
        Vec<ll> res;
        res.pb(v[2]);
        res.pb(v[1]);
        res.pb(v[0]);
        for (ll  j = 0; j < (m - 2) / 4; j++) {
          res.pb(v[1]);
          res.pb(v[2]);
          res.pb(v[1]);
          res.pb(v[0]);
        }
        for (auto& x : res) {
          cout << x << " ";
        } cout << "\n";
      }
    }
  }
}
