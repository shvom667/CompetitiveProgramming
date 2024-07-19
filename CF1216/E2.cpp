/*
  And all I am is a man
  I want the world in my hands
  I hate the beach
  But I stand in California with my toes in the sand
  Use the sleeves of my sweater
  Let's have an adventure
  Head in the clouds but my gravity centered
  Touch my neck and I'll touch yours
  You in those little high waisted shorts, oh
*/

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
void pre();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  t = 1;
  cin >> t;
  pre();
  while (t--) solve();
}
ll P[19];
ll C[11];
ll H[11];
ll PH[11];
string to_string(int k) {
  string res = "";
  while (k) {
    ll x = k % 10;
    k /= 10;
    res += (char)(k + '0');
  }
  reverse(begin(res),end(res));
  return res;
};
void pre() {
  for (ll i = 0; i <= 10; i++) {
    H[i] = PH[i] = 0;
  }
  P[0] = 1;
  for (ll i = 1; i <= 18; i++) {
    P[i] = P[i-1] * 10;
  }
  C[0] = 0;
  C[1] = -1;
  for (ll k = 2; k <= 10; k++) {
    C[k] = 0;
    C[k] -= P[k] * k;
    for (ll j = 1; j <= k; j++) {
      C[k] += 9ll * P[j-1] * j;
    }
  }
  for (ll k = 1; k <= 10; k++) {
    H[k] = (C[k] + k ) * (P[k] - P[k-1]);
    H[k] += k * ( P[k] * (P[k] - 1) ) / 2;
    H[k] -= k * ( (P[k-1] - 1) * P[k-1]) / 2;
    PH[k] = H[k];
    PH[k] += PH[k-1];
  }
  PH[10] = 2e18;
  H[10] = 2e18;
}
ll d(ll x) {
  ll r = 0;
  while (x) {
    x /= 10;
    r++;
  }
  return r;
}
ll g(ll M) {
  if (M == 0) 
    return 0;
  ll K = 0;
  ll MM = M;
  while (MM) {
    MM /= 10;
    K++;
  }
  ll res =  C[K] + K * (M + 1);
  return res;
}
ll h(ll x) {
  ll k = d(x);
  ll res = 0;
  res = (C[k] + k) * (x - P[k-1] + 1);
  res += k * (x * (x + 1)) / 2;
  res -= k * ( ( P[k-1] ) * (P[k-1] - 1) ) / 2;
  return res;
}
const ll INF = 1e18;
const ll M = 2e9 + 20;
void solve() {
  ll in;
  cin >> in;
  ll md;
  for (ll d = 10; d >= 0; d--) {
    if (PH[d] >= in) {
      md = d;
    }
  }
  dbg(md);
  in -= PH[md-1];
  dbg(in);
  ll L, R;
  L = P[md-1], R = min(M, P[md] - 1);
  while (L <= R) {
    ll mid = L + (R - L) / 2;
    bool ok=false;
    ok = h(mid) >= in;
    if (ok) {
      R = mid - 1;
    } else {
      L = mid + 1;
    }
  }
  dbg("L1 : ", L);
  if (d(L-1) == d(L))
    in -= h(L-1);
  L = 1, R = 2e17;
  while (L <= R) {
    ll mid = L + (R - L) / 2;
    bool ok = false;
    ok = g(mid) >= in;
    if (ok) {
      R = mid - 1;
    }else{
      L = mid + 1;
    }
  }
  in -= g(L-1);
  string s = to_string(L);
  cout << s[in-1] << '\n';
}
