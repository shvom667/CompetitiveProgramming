
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
  string x, y;
  cin >> n >> x >> y;
  Vec<ll> f(26, 0), pb;
  bool ok = false;
  for (ll i = 0; i < n; i++) {
    f[x[i] - 'a']++;
    f[y[i] - 'a']++;
    if ((x[i] == 'b' || y[i] == 'b') && (x[i] != 'b' || y[i] != 'b')) {
      ok = true;
    }
    if (x[i] == 'b') {
      pb.pb(i);
    }
  }
  if (ok) {
    cout << "No" << '\n';
    return;
  }
  for (ll i = 0; i < 26; i++) {
    if (f[i] & 1) {
      cout << "No\n" << '\n';
      return;
    }
  }
  auto is_b = [&] (ll l, ll r) {
    auto it = upper_bound(begin(pb), end(pb), l);
    auto jt = it;
    jt--;
    if (it != end(pb)) {
      if (*it <= r) return true;
    }
    if (it != begin(pb)) {
      if (*jt >= l && *jt <= r) {
        return true;
      }
    }
    return false;
  };
  bool fok = false;
  deque<ll> dq;
  for (ll i = 0; i < n; i++) {
    if (x[i] == 'a' && y[i] == 'c') {
      dq.pb(i);
      continue;
    }
    if (x[i] == y[i]) {
      continue;
    }
    if (x[i] == 'c' && y[i] == 'a') {
      if (dq.empty()) {
        fok = true;
        break;
      }else{
        ll f = dq.front();
        if (is_b(f, i)) {
          dq.pop_front();
        } else {
          fok = true;
          break;
        }
      }
    }
  }
  if (!dq.empty()) {
    fok = true;
  }
  if (fok) {
    cout << "No\n";
    return;
  } else {
    cout << "Yes\n";
  }
}
