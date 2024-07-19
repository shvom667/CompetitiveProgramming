
#include <bits/stdc++.h>
using namespace std;
using ll = int;
#define pb push_back
template <typename T> using Vec = vector<T>;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set                                                            \
  tree<int, null_type, less<int>, rb_tree_tag,                                 \
       tree_order_statistics_node_update>
#define fbo(x) find_by_order(x)
#define ook(x) order_of_key(x)
/*
 * find_by_order(x) : return the (x + 1) th smallest element
 * order_of_key(x)  : number of elements strictly less than x
 */
void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  t = 1;
  while (t--)
    solve();
}
#define SZ(x) (ll) x.size()
void solve() {
  ll n, q;
  cin >> n >> q;
  ordered_set s;
  ll p[n];
  multiset<ll> ms;
  auto md = [&]() {
    if (s.empty())
      return 0;
    auto st = *s.fbo(0);
    auto en = *s.fbo(SZ(s) - 1);
    return (ll)en - st;
  };
  auto mms = [&]() {
    if (ms.empty())
      return 0;
    return *ms.rbegin();
  };
  for (ll j = 0; j < n; j++) {
    ll x;
    cin >> x;
    p[j] = x;
  }
  sort(p, p + n);
  for (ll j = 0; j < n; j++)
  {
    if (j)
      ms.insert(p[j] - p[j-1]);
    s.insert(p[j]);
  }
  Vec<ll> fans;
  auto get_ans = [&]() {
    if (s.empty())
      return 0;
    return md() - mms();
  };
  fans.pb(get_ans());
  while (q--) {
    ll t, x;
    cin >> t >> x;
    if (t == 0) {
      if (SZ(s) == 1) {
        s.clear();
        ms.clear();
        fans.pb(0);
        continue;
      }
      auto ri = s.ook(x);
      auto vi = *s.fbo(ri);
      if (ri == 0) {
        auto ni = *s.fbo(ri + 1);
        ms.erase(ms.find(ni - vi));
      } else if (ri == SZ(s)-1) {
        auto pi = *s.fbo(ri - 1);
        ms.erase(ms.find(vi - pi));
      } else {
        auto ni = *s.fbo(ri + 1);
        auto pi = *s.fbo(ri - 1);
        ms.erase(ms.find(ni - vi));
        ms.erase(ms.find(vi - pi));
        ms.insert(ni - pi);
      }
      s.erase(s.find(vi));
    }
    if (t == 1) {
      if (SZ(s) == 0) {
        s.insert(x);
        fans.pb(0);
        continue;
      }
      auto it = s.upper_bound(x);
      if (it == begin(s)) {
        auto ni = *s.fbo(0);
        ms.insert(ni-x);
      } else if (it == end(s)) {
        auto pi = *s.fbo(SZ(s)-1);
        ms.insert(x-pi);
      } else {
        auto nv=*it;
        auto pt = it;
        pt--;
        auto pv=*pt;
        ms.erase(ms.find(nv-pv));
        ms.insert(nv-x);
        ms.insert(x-pv);
      }
      s.insert(x);
    }
    fans.pb(get_ans());
  }

  for (auto &x : fans)
    cout << x << '\n';
}
