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

map<ll, ll> F;
const ll M = 998244353;

ll f(ll n) {
	if (F.count(n)) return F[n];
	ll k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}
void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
	F[0]=F[1]=1;
  ll t; 
  t = 1;
  cin >> t;
  while (t--) solve();
}

void solve() {
  ll n, m, q;
  cin >> n >> m >> q;

  bool ok[8];

  for (ll i = 0; i < 8; i++) ok[i] = true;

  cout << 8 << "\n";
  while (q--) {
    ll x, y;
    string s;
    char c;
    cin >> x >> y >> s;
    c = s[0];
    if ((x + (y+1)/2)%2==0) {
      ok[0] &= (c == 's');
      ok[1] &= (c == 'c');
    } else {
      ok[0] &= (c == 'c');
      ok[1] &= (c == 's');

    }
    if ((x + (y)/2)%2==0) {
      ok[2] &= (c == 's');
      ok[3] &= (c == 'c');

    } else {
      ok[2] &= (c == 'c');
      ok[3] &= (c == 's');

    }
    if ((y + (x+1)/2)%2==0) {
      ok[4] &= (c == 's');
      ok[5] &= (c == 'c');

    } else {
      ok[4] &= (c == 'c');
      ok[5] &= (c == 's');
    }
    if ((y + (x)/2)%2==0) {
      ok[6] &= (c == 's');
      ok[7] &= (c == 'c');

    } else {
      ok[6] &= (c == 'c');
      ok[7] &= (c == 's');
    }
    ll cnt=0;
    for (ll i = 0; i < 8; i++) cnt += ok[i]==true;
    cout << cnt << "\n";
  }
}

