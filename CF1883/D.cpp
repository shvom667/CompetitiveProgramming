#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define i32 int
#define pb push_back
#define ALL(x) begin(x), end(x)
#define SZ(x) (ll)(x.size())
#define OVERRIDE(a, b, c, d, ...) d
#define REP2(i, n) for (i32 i = 0; i < (i32)(n); ++i)
#define REP3(i, m, n) for (i32 i = (i32)(m); i < (i32)(n); ++i)
#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
#define PER(i, n) for (i32 i = (i32)(n)-1; i >= 0; --i)

template <typename T> using Vec = vector<T>;
template <typename T> vector<T> PrefixSum(vector<T> X) {
  ll n = X.size();
  vector<T> ret(n, 0);
  REP(i, n) {
    ret[i] = X[i];
    if (i > 0)
      ret[i] += ret[i - 1];
  }
  return ret;
}
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
template <typename T> void chmin(T &a, T b) { a = min(a, b); }

void solve() {
    char c;
    ll l, r;
  ll n;
  cin >> n;
  multiset<ll> s, e;
  for (ll j = 0; j < n ; j++) {
    cin >> c >> l >> r;
    if (c == '+') {
      s.insert(l);
      e.insert(r);
    } else {
      s.erase(s.find(l));
      e.erase(e.find(r));
    }
    if (s.empty()) {
      cout << "NO\n";
    } else {
      ll M = *s.rbegin();
      ll m = *e.begin();
      if (M > m) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}

int main() {

  ll t;
  t = 1;
  while (t--) {
    solve();
  }
}
