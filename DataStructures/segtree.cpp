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

    T combine(T a, T b) {
        // put code here
    }

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
    
    /*
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

    */

};




