#include <bits/stdc++.h>
using namespace std;
using ll = int;
#define pb push_back
template <typename T> using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif
const ll inf = 2e9;
const int maxn = (int)2e6 + 10;
int a[maxn/4];
int A[maxn];

int n, m;

int id = 0;
int gcd(int a, int b) {
    if (a == 0 || b == 0)
        return max(a, b);
    return __gcd(a, b);
}
int combine(int a, int b) { return gcd(a, b); }

void build(int l, int r, int v) {
  if (r < l)
    return;
  dbg(l, r, v);
  if (l == r) {
    A[v] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, 2 * v);
  build(mid + 1, r, 2 * v + 1);
  A[v] = combine(A[2 * v], A[2 * v + 1]);
}

int Qh(int l, int r, int L, int R, int v) {
  if (r < L || l > R)
    return id;
  if (l == L && r == R)
    return A[v];
  if (l >= L && r <= R) {
    int mid = (L + R) / 2;
    return combine(Qh(l, r, L, mid, 2 * v), Qh(l, r, mid + 1, R, 2 * v + 1));
  }
  return Qh(max(l, L), min(r, R), L, R, v);
}
int Q(int l, int r) { return Qh(l, r, 0, n - 1, 1); }

void Ul(int p, int val, int L, int R, int v) {
  if (p < L || p > R)
    return;
  if (R < L)
    return;
  if (p == L && p == R) {
    A[v] = val;
    return;
  } else {
    int mid = (L + R) >> 1;
    Ul(p, val, L, mid, 2 * v);
    Ul(p, val, mid + 1, R, 2 * v + 1);
    A[v] = combine(A[2 * v], A[2 * v + 1]);
  }
}

void U(int p, int val) { Ul(p, val, 0, n - 1, 1); }

bool T(int v, int x) { return A[v] % x == 0; }

int fffu(int l, int r, int L, int R, int v, int x) 
  if (r < L || l > R)
    return inf;
  if (L > R)
    return inf;

  if (l == L && r == R) {
    if (T(v, x)) {
      return inf;
    } else {
      if (l == r) {
        return l;
      }
      int mid = (L + R) >> 1;
      int a1 = fffu(l, r, L, mid, 2 * v, x);
      if (a1 != inf) return a1;
      int a2 = fffu(l, r, mid + 1, R, 2 * v + 1, x);
      return min(a1, a2);
    }
  }
  if (l >= L && r <= R) {
    int mid = (L + R) >> 1;
    int a1 = fffu(l, r, L, mid, 2 * v, x);
    if (a1 != inf) return a1;
    int a2 = fffu(l, r, mid + 1, R, 2 * v + 1, x);
    return min(a1, a2);
  }

  return fffu(max(l, L), min(r, R), L, R, v, x);
}
int fff(int l, int r, int x) { return fffu(l, r, 0, n - 1, 1, x); }

auto solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(0, n - 1, 1);


  cin >> m;

  while (m--) {
      int type;
      cin >> type;
      if (type == 1) {
          int l, r, x;
          cin >> l >> r >> x;
          l--, r--;
          if (r - l + 1 == 1) {
              cout << "YES\n";
              continue;
          }
          if(Q(l, r) % x == 0) {
              cout << "YES\n";
              continue;
          }
          int F = fff(l, r, x);
          F = min(F, r + 1);
          F--;
          if (F + 2 > r) {
              cout << "YES\n";
              continue;
          }
          if (Q(F + 2, r) % x == 0) {
              cout << "YES\n";
          } else {
              cout << "NO\n";
          }
      }else {
          int i, y;
          cin >> i >> y;
          i--;
          U(i, y);
      }
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  T = 1;
  for (ll tc = 1; tc <= T; tc++) {
    auto res = solve();
  }
  return 0;
}
