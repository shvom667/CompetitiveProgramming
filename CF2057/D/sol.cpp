#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif
const ll inf = 1e18;
struct Node
{
    ll maxVal, minVal, ans;
};

    Node id;

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
        T res;
        res.ans = max(a.ans, b.ans);
        res.ans = max(res.ans, b.maxVal - a.minVal);
        res.maxVal = max(a.maxVal, b.maxVal);
        res.minVal = min(a.minVal,b.minVal);
        return res;
    }

    T apply(T curr, ll upd) {
		T ans = id;
        ans.ans = 0;
        ans.maxVal = upd;
        ans.minVal = upd;
		return ans;
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
        A[v] = apply(A[v], val);
        return;
      } else {
        int mid = (L + R) >> 1;
        updateUtil(p, val, L, mid, 2 * v);
        updateUtil(p, val, mid + 1, R, 2 * v + 1);
        A[v] = combine(A[2 * v], A[2 * v + 1]);
      }
    }
    
    void update(int p, int val) { updateUtil(p, val, 0, n - 1, 1); }
};

template<class T>
struct SegTree1 {
    ll n;
    T identity_element;
    vector<T> A;

    SegTree1(ll _n, T _identity_element) {
        n = _n;
        identity_element  = _identity_element;
        A = vector<T> (4 * n, identity_element);
    }

    T combine(T a, T b) {
        T res;
        res.ans = max(a.ans, b.ans);
        res.ans = max(res.ans, a.maxVal - b.minVal);
        res.maxVal = max(a.maxVal, b.maxVal);
        res.minVal = min(a.minVal,b.minVal);
        return res;
    }

    T apply(T curr, ll upd) {
		T ans = id;
        ans.ans = 0;
        ans.maxVal = upd;
        ans.minVal = upd;
		return ans;
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
        A[v] = apply(A[v], val);
        return;
      } else {
        int mid = (L + R) >> 1;
        updateUtil(p, val, L, mid, 2 * v);
        updateUtil(p, val, mid + 1, R, 2 * v + 1);
        A[v] = combine(A[2 * v], A[2 * v + 1]);
      }
    }
    
    void update(int p, int val) { updateUtil(p, val, 0, n - 1, 1); }
};

void __print(Node x) {
    cerr << "{ ans = " << x.ans << " | maxVal = " << x.maxVal << " | minVal = " << x.minVal << " }"; 
}



auto solve() {
    id.maxVal = -inf;
    id.minVal = inf;
    id.ans = 0;

    ll n,q;cin>>n>>q;
    vector<ll>a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    SegTree<Node> S(n, id);
    vector<Node> dummy(n);
    for (ll i = 0; i < n; i++) {
        dummy[i].maxVal = a[i] - i;
        dummy[i].minVal = a[i] - i;
        dummy[i].ans = 0;
    }
    S.build(dummy);

    SegTree1<Node> R(n, id);
    vector<Node> dummy2(n);
    
    for (ll i = 0; i < n; i++) {
        dummy2[i].maxVal = a[i] + i;
        dummy2[i].minVal = a[i] + i;
        dummy2[i].ans = 0;
    }
    R.build(dummy2);


    for (ll i = 0; i < n; i++) {
        dbg(S.query(i, i));
    }

    dbg(S.query(0, 1));


    for (ll i = 0; i < n; i++) {
        dbg(R.query(i, i));
    }

    dbg(R.query(0, 1));

    cout << max(S.query(0, n - 1).ans, R.query(0, n - 1).ans) << " ";

    while (q--) {
        ll p, x;
        cin >> p >> x;
        p--;
        a[p] = x;
        S.update(p, x - p);
        R.update(p, p + x);

        cout << max(S.query(0, n - 1).ans, R.query(0, n - 1).ans) << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
    }
    return 0;
}
