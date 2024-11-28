#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

// ============

template <class T, class U>
// T -> node, U->update.
struct Lsegtree {
  vector<T> st;
  vector<U> lazy;
  ll n;
  T identity_element;
  U identity_update;
  Lsegtree(ll n, T identity_element, U identity_update) {
    this->n = n;
    this->identity_element = identity_element;
    this->identity_update = identity_update;
    st.assign(4 * n, identity_element);
    lazy.assign(4 * n, identity_update);
  }
  T combine(T l, T r) {
    // change this function as required.
    T ans = l;
    if (ans.first > r.first) {
      ans = r;
    }
    return ans;
  }
  void buildUtil(ll v, ll tl, ll tr, vector<T> &a) {
    if (tl == tr) {
      st[v] = a[tl];
      return;
    }
    ll tm = (tl + tr) >> 1;
    buildUtil(2 * v + 1, tl, tm, a);
    buildUtil(2 * v + 2, tm + 1, tr, a);
    st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
  }
  // change the following 2 functions, and you're more or less done.
  T apply(T curr, U upd, ll tl, ll tr) {
    T ans = curr;
    ans.first = upd;
    ans.second = tl;
    return ans;
  }
  U combineUpdate(U old_upd, U new_upd, ll tl, ll tr) {
    U ans = old_upd;
    ans = new_upd;
    return ans;
  }
  void push_down(ll v, ll tl, ll tr) {
    if (lazy[v] == identity_update)
      return;
    st[v] = apply(st[v], lazy[v], tl, tr);
    if (2 * v + 2 < 4 * n) {
      ll tm = (tl + tr) >> 1;
      lazy[2 * v + 1] = combineUpdate(lazy[2 * v + 1], lazy[v], tl, tm);
      lazy[2 * v + 2] = combineUpdate(lazy[2 * v + 2], lazy[v], tm + 1, tr);
    }
    lazy[v] = identity_update;
  }
  T queryUtil(ll v, ll tl, ll tr, ll l, ll r) {
    push_down(v, tl, tr);
    if (l > r)
      return identity_element;
    if (tr < l or tl > r) {
      return identity_element;
    }
    if (l <= tl and r >= tr) {
      return st[v];
    }
    ll tm = (tl + tr) >> 1;
    return combine(queryUtil(2 * v + 1, tl, tm, l, r),
                   queryUtil(2 * v + 2, tm + 1, tr, l, r));
  }

  void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd) {
    push_down(v, tl, tr);
    if (tr < l or tl > r)
      return;
    if (tl >= l and tr <= r) {
      lazy[v] = combineUpdate(lazy[v], upd, tl, tr);
      push_down(v, tl, tr);
    } else {
      ll tm = (tl + tr) >> 1;
      updateUtil(2 * v + 1, tl, tm, l, r, upd);
      updateUtil(2 * v + 2, tm + 1, tr, l, r, upd);
      st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
    }
  }

  void build(vector<T> a) {
    assert((i64)a.size() == n);
    buildUtil(0, 0, n - 1, a);
  }
  T query(ll l, ll r) { return queryUtil(0, 0, n - 1, l, r); }
  void update(ll l, ll r, U upd) { updateUtil(0, 0, n - 1, l, r, upd); }
};
const ll MAX = 2e15+2;
using pl = pair<ll, ll>;
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n + 1, 0);
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  Vec<vector<ll>> g(11, vector<ll>(n + 1, 0));
  for (ll digit = 0, p10 = 10; digit <= 10; digit++,p10 *= 10) {
    for (ll i = 1; i <= n; i++) {
      if (a[i] % p10 && ((a[i]%p10)*10)/p10 > 0) {
        g[digit][i] = a[i];
      } else {
        g[digit][i] = MAX;
      }
    }
  }

  // Lsegtree<pl, ll> seg(n + 1, {0ll,0ll}, -MAX);// [11];
  // Lsegtree<pl, ll> seg[11] = {
  //   Lsegtree<pl, ll>(n + 1, {MAX, 0}, -MAX), 
  //   Lsegtree<pl, ll>(n + 1, {MAX, 0}, -MAX),
  //   Lsegtree<pl, ll>(n + 1, {MAX, 0}, -MAX),
  //   Lsegtree<pl, ll>(n + 1, {MAX, 0}, -MAX),
  //   Lsegtree<pl, ll>(n + 1, {MAX, 0}, -MAX),
  //   Lsegtree<pl, ll>(n + 1, {MAX, 0}, -MAX),
  //   Lsegtree<pl, ll>(n + 1, {MAX, 0}, -MAX),
  //   Lsegtree<pl, ll>(n + 1, {MAX, 0}, -MAX),
  //   Lsegtree<pl, ll>(n + 1, {MAX, 0}, -MAX),
  //   Lsegtree<pl, ll>(n + 1, {MAX, 0}, -MAX),
  //   Lsegtree<pl, ll>(n + 1, {MAX, 0}, -MAX)
  // };
  
  Lsegtree<pl, ll> seg(12*n + 2, {MAX, 0}, -MAX);

  vector<pl> dummy(12*n + 2, {0ll,0ll});
  for (ll digit = 0; digit <= 10; digit++) {
    for (ll i = 1; i <= n; i++) {
      // dummy[i] = {g[digit][i], i};
      dummy[digit*n+i] = {g[digit][i], i};
    }
    // seg[digit].build(dummy);
  }
  seg.build(dummy);

  // for (ll digit = 0; digit < 11; digit++) {
  //   for (ll i = 1; i <= n; i++) {
  //     cout << seg[digit].query(i,i).first << " ";
  //   } cout << '\n';
  // }

  while (m--) {
    ll type, aa, bb;
    cin >> type >> aa >> bb;
    if (type == 1) {
      a[aa] = bb;
      for (ll digit = 0, p10 = 10; digit <= 10; digit++, p10 *= 10) {
        if (a[aa] % p10 && ((a[aa]%p10)*10)/p10 > 0) {
          g[digit][aa] = a[aa];          
          // seg[digit].update(aa,aa,g[digit][aa]);
          seg.update(digit * n + aa, digit * n + aa, g[digit][aa]);
        } else {
          g[digit][aa] = MAX;
          // seg[digit].update(aa,aa,g[digit][aa]);
          seg.update(digit * n + aa, digit * n + aa, g[digit][aa]);
        }
      }
    } else {
      if (bb - aa + 1 == 1) {
        cout << -1 << '\n';
        continue;
      }
      ll fans = MAX;
      for (ll digit = 0, p10 = 10; digit <= 10; digit++, p10 *= 10) {
        // vector<ll> vec;
        // for (ll i = aa; i <= bb; i++) {
        //   vec.pb(g[digit][i]);
        // }
        // sort(begin(vec),end(vec));
        // assert((ll)vec.size() >= 2);
        // fans = min(fans, vec[0]+vec[1]);
        pl a1, a2, a3;
        a1 = a2 = a3 = {MAX, 0};
        // a1 = seg[digit].query(aa, bb);
        a1 = seg.query(digit * n + aa, digit * n + bb);
        if (a1.second - 1 >= aa) {
          // a2 = seg[digit].query(aa, a1.second - 1);
          a2 = seg.query(digit * n + aa, digit * n + a1.second - 1);
        }
        if (a1.second + 1 <= bb) {
          // a3 = seg[digit].query(a1.second + 1, bb);
          a3 = seg.query(digit * n + a1.second + 1, digit * n + bb);
        }
        if (a3.first < a2.first) a2 = a3;
        fans = min(fans, a1.first + a2.first);
      }
      cout << (fans > 2e9 ? -1 : fans) << '\n';
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
    // cout <<  << "\n";
    // dbg(tc, res);
  }
  return 0;
}
