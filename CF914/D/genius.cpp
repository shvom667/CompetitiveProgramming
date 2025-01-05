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


int gcd(int a, int b) {
    if (a == 0 || b == 0)
        return max(a, b);
    return __gcd(a, b);
}


template<class T>
struct SegTree {
    ll n;
    T identity_element;
    vector<T> A;

    SegTree(ll _n, T _identity_element) {
        n = _n;
        identity_element  = _identity_element;
        A = vector<T> (4 * n, identity_element);
    }

    T combine(T a, T b) { return gcd(a, b); }

    void buildUtil(int l, int r, int v, vector<T>& a) {
      if (r < l)
        return;
      if (l == r) {
        A[v] = a[l];
        return;
      }
      int mid = (l + r) >> 1;
      buildUtil(l, mid, 2 * v, a);
      buildUtil(mid + 1, r, 2 * v + 1, a);
      A[v] = combine(A[2 * v], A[2 * v + 1]);
    }
    void build(vector<T> a) {
        buildUtil(0, n - 1, 1, a);
    }
    
    T queryUtil(int l, int r, int L, int R, int v) {
      if (r < L || l > R)
        return identity_element;
      if (l == L && r == R)
        return A[v];
      if (l >= L && r <= R) {
        int mid = (L + R) >> 1;
        return combine(queryUtil(l, r, L, mid, 2 * v), queryUtil(l, r, mid + 1, R, 2 * v + 1));
      }
      return queryUtil(max(l, L), min(r, R), L, R, v);
    }
    T query(int l, int r) { return queryUtil(l, r, 0, n - 1, 1); }
    
    void updateUtil(int p, int val, int L, int R, int v) {
      if (p < L || p > R)
        return;
      if (R < L)
        return;
      if (p == L && p == R) {
        A[v] = val;
        return;
      } else {
        int mid = (L + R) >> 1;
        updateUtil(p, val, L, mid, 2 * v);
        updateUtil(p, val, mid + 1, R, 2 * v + 1);
        A[v] = combine(A[2 * v], A[2 * v + 1]);
      }
    }
    
    void update(int p, int val) { updateUtil(p, val, 0, n - 1, 1); }
    
    bool cond(int v, int x) { return A[v] % x == 0; }
    
    int findFirstFalseUtil(int l, int r, int L, int R, int v, int x) {
      if (r < L || l > R)
        return inf;
      if (L > R)
        return inf;
    
      if (l == L && r == R) {
        if (cond(v, x)) {
          return inf;
        } else {
          if (l == r) {
            return l;
          }
          int mid = (L + R) >> 1;
          int a1 = findFirstFalseUtil(l, r, L, mid, 2 * v, x);
          if (a1 != inf) return a1;
          int a2 = findFirstFalseUtil(l, r, mid + 1, R, 2 * v + 1, x);
          return min(a1, a2);
        }
      }
      if (l >= L && r <= R) {
        int mid = (L + R) >> 1;
        int a1 = findFirstFalseUtil(l, r, L, mid, 2 * v, x);
        if (a1 != inf) return a1;
        int a2 = findFirstFalseUtil(l, r, mid + 1, R, 2 * v + 1, x);
        return min(a1, a2);
      }
    
      return findFirstFalseUtil(max(l, L), min(r, R), L, R, v, x);
    }
    int findFirstFalse(int l, int r, int x) { return findFirstFalseUtil(l, r, 0, n - 1, 1, x); }

};


auto solve() {
  int n, m;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }


  int id = 0;
  SegTree<ll> S(n, id);
  S.build(a);

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
          if(S.query(l, r) % x == 0) {
              cout << "YES\n";
              continue;
          }
          int F = S.findFirstFalse(l, r, x);
          F = min(F, r + 1);
          F--;
          if (F + 2 > r) {
              cout << "YES\n";
              continue;
          }
          if (S.query(F + 2, r) % x == 0) {
              cout << "YES\n";
          } else {
              cout << "NO\n";
          }
      }else {
          int i, y;
          cin >> i >> y;
          i--;
          S.update(i, y);
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

