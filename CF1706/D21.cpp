
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

// =================

// Debugging template
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename A> void __print(const A &x);
template <typename A, typename B> void __print(const pair<A, B> &p);
template <typename... A> void __print(const tuple<A...> &t);
template <typename T> void __print(stack<T> s);
template <typename T> void __print(queue<T> q);
template <typename T, typename... U> void __print(priority_queue<T, U...> q);
/*
void __print(Mint x) {
        cout << x;
}
*/
template <typename A> void __print(const A &x) {
  bool first = true;
  cout << '{';
  for (const auto &i : x) {
    cout << (first ? "" : ","), __print(i);
    first = false;
  }
  cout << '}';
}
template <typename A, typename B> void __print(const pair<A, B> &p) {
  cout << '(';
  __print(p.first);
  cout << ',';
  __print(p.second);
  cout << ')';
}
template <typename... A> void __print(const tuple<A...> &t) {
  bool first = true;
  cout << '(';
  apply(
      [&first](const auto &...args) {
        ((cout << (first ? "" : ","), __print(args), first = false), ...);
      },
      t);
  cout << ')';
}
template <typename T> void __print(stack<T> s) {
  vector<T> debugVector;
  while (!s.empty()) {
    T t = s.top();
    debugVector.push_back(t);
    s.pop();
  }
  reverse(debugVector.begin(), debugVector.end());
  __print(debugVector);
}
template <typename T> void __print(queue<T> q) {
  vector<T> debugVector;
  while (!q.empty()) {
    T t = q.front();
    debugVector.push_back(t);
    q.pop();
  }
  __print(debugVector);
}
template <typename T, typename... U> void __print(priority_queue<T, U...> q) {
  vector<T> debugVector;
  while (!q.empty()) {
    T t = q.top();
    debugVector.push_back(t);
    q.pop();
  }
  __print(debugVector);
}
void _print() { cout << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
  __print(H);
  if (sizeof...(T))
    cout << ", ";
  _print(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
  cout << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = [";              \
  _print(__VA_ARGS__)
#else
#define dbg(...)
#endif

// =================
void solve();
int main() {
  ll t;
  t = 1;
  while (t--)
    solve();
}

std::random_device rd;
std::mt19937 gen(rd());
int rng_int(int l, int r) {
  std::uniform_int_distribution<int> distrib(l, r);
  return distrib(gen);
}
void get(ll x) {
  for (ll i = 1; i <= x; i++) {
    dbg(i, x / i);
  }
}
ll N = 500;
void solve() {
  get(10);
  return;
  Vec<ll> big;
  for (ll k = 1; k <= 1000; k++) {
    ll l,r;
    l = 1e4, r = 1e5;
    big.pb(rng_int(l,r));
  }
  dbg(big);
  for (ll ii = 0; ii <= (ll)big.size(); ii++) {
    ll n = big[ii];
    set<ll> s;
    for (ll i = 1; i <= n; i++) {
      s.insert(n / i);
    }
    ll limit = sqrtl(n);
    bool ok = true;
    for (ll j = 1; j <= limit; j++) {
      if (s.count(j) == 0) {
        ok = false;
      }
    }
    dbg(n, ok);
    if (ok == false) {
      assert(false);
    }
  }
}
