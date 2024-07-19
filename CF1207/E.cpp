
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
#define nl endl
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

const ll N = 14;
bool all_even(Vec<ll> a) {
  for (auto& x : a) {
    if (x % 2 == 1)
      return false;
  }
  return true;
}
bool all_odd(Vec<ll> a) {
  for (auto& x : a) {
    if (x % 2 == 0)
      return false;
  }
  return true;
}
ll ask(Vec<ll> a) {
  cout << "? ";
  for (auto& x : a)
    cout << x << " ";
  cout << nl;
  ll res;
  cin >> res;
  return res;
}
void solve() {
  Vec<ll> E, O;
  for (ll i = 1; i < (1ll << N); i++) {
    ll x = i;
    Vec<ll> set_bits;
    for (ll b = 0; b <= N; b++) {
      if ((1ll<<b) & x) {
        set_bits.pb(b);
      }
    }
    if (all_even(set_bits)) {
      E.pb(x);
    }
    if (all_odd(set_bits)) {
      O.pb(x);
    }
  }
  while (E.size() > 100)
    E.pop_back();
  while (O.size() > 100)
    O.pop_back();
  dbg(E);
  dbg(O);
  dbg(E.size());
  dbg(O.size());
  ll ans1 = ask(E);
  ll ans2 = ask(O);
  ll xr = (ans1 ^ ans2);
  ll x = 0;
  for (ll b = 0; b <= N; b++) {
    if (xr & (1ll << b)) {
      if (b&1) {
        if ((ans2) & (1ll << b)) {
        } else {
          x ^= (1ll << b);
        }
      }
      else {
        if ((ans1) & (1ll << b)) {
        } else {
          x ^= (1ll << b);
        }
      }
    } else {
      if (b&1) {
        if ((ans2) & (1ll<<b)) {
          x ^= (1ll << b);
        } else {
        }
      } else {
        if ((ans1) & (1ll<<b)) {
          x ^= (1ll << b);
        } else {
        }
      }
    }
  }
  cout << "! " << x << nl;
}
