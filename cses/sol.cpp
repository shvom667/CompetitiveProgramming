#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

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
        T res = a + b;
        return res;
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
    
};




auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    SegTree<ll> S(n, 0);
    S.build(a);
    while(m--){
        ll t,x,y;
        cin>>t>>x>>y;
        if(t==1){
            x--;
            S.update(x,y);
        }else{
            x--;y--;
            cout<<S.query(x,y)<<'\n';
        }
    }


}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  T = 1;
  for (ll tc = 1; tc <= T; tc++) {
      solve();
  }
  return 0;
}
