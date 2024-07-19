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
ll number_of_digits(ll x) {
  ll c = 0;
  while (x) {
    c++;
    x /= 10;
  }
  return c;
}
Vec<ll> digit_vector(ll x) {
  Vec<ll> res;
  while (x) {
    res.pb(x % 10);
    x /= 10;
  }
  reverse(begin(res), end(res));
  return res;
}
ll vector_to_digit(Vec<ll> d) {
  ll fans = 0;
  reverse(begin(d), end(d));
  ll n = d.size();
  ll p = 1;
  for (ll i = 0; i < n; i++) {
    fans += p * d[i];
    p *= 10;
  }
  return fans;
}

void solve() {
  ll l, r;
  cin >> l >> r;
  if (number_of_digits(l) < number_of_digits(r)) {

    for (ll i = 0; i < number_of_digits(l); i++)
      cout << 9;
    cout << '\n';
    return;
  }
  ll fans = 20;
  Vec<ll> dl, dr;
  dl = digit_vector(l);
  dr = digit_vector(r);
  ll n = dl.size();
  fans = *max_element(begin(dl), end(dl)) - *min_element(begin(dl), end(dl));
  ll best = l;
  dbg(dl);
  dbg(dr);
  for (ll lo = 0; lo <= 9; lo++)
    for (ll hi = lo; hi <= 9; hi++) {
      bool ok = true;
      Vec<ll> cur_ans(n, lo);
      Vec<ll> poss(n, lo);
      dbg(poss);
      for (ll i = 0; i < n; i++) {
        poss[i] = max(lo, dl[i] + 1);
        if (poss[i] <= hi) {
          ll res = vector_to_digit(poss);
          if (res <= r && res >= l) {
            fans = min(fans, hi - lo);
            if (hi - lo == 1) {
              dbg(poss);
            }
            if (fans == hi - lo) {
              best = res;
            }
          }
        }
        poss[i] = dl[i];
        if (poss[i] > hi || poss[i] < lo) break;
      }
    }
  cout << best << "\n";
}
