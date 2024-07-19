#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

struct robot {
  ll x; char dir;
};
void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--) solve();
}
ll n, m;
ll res1(ll x, ll y) {
  if (x > y) swap(x, y);
  return (y - x ) / 2;
}
ll res2 (ll x, ll y, ll boundary) {
  if (x > y) swap(x, y);
  ll a, b;
  if (boundary == 0) {
    a = x; 
    b = y;
  }
  if (boundary == 1) {
    a = m - y;
    b = m - x;
  }
  return a + (b - a) / 2;
}
ll res3 (ll x, ll y) {
  if (x > y) swap(x, y);
  ll a, b;
  a = x;
  b = m - y;
  return (m + a + b) / 2;
}
robot r;
void solve() {
  cin >> n >> m;
  map<ll, ll> ind;
  Vec<ll> res(n + 1, -1);
  Vec<robot> R(n + 1), E, O;
  for (ll i = 1; i <= n; i++) {
    cin >> R[i].x;
    ind[R[i].x] = i;
  }
  for (ll i = 1; i <= n; i++) {
    cin >> R[i].dir;
  }
  sort(begin(R), end(R), [&] (auto a, auto b) {
      return a.x < b.x;
      });
  for (ll i = 1; i <= n; i++)
    if (R[i].x % 2 == 1)
      O.pb(R[i]);
    else 
      E.pb(R[i]);
  auto get_ans = [&] (robot a, robot b) {
    assert( (a.x + b.x) % 2 == 0);
    if (a.x > b.x) swap(a, b);
    ll ans;
    if (a.dir == b.dir) {
      if (a.dir == 'R')
        ans = res2(a.x, b.x, 1);
      else 
        ans = res2(a.x, b.x, 0);
    }
    else {
      if (a.dir == 'R')
        ans = res1(a.x, b.x);
      else
        ans = res3(a.x, b.x);
    }
    res[ind[a.x]] = res[ind[b.x]] = ans;
  };
  if (true) {
    deque<robot> prev;
    deque<robot> lft, rht;
    for (ll i = 0; i < (ll)E.size(); i++)  {
      if (E[i].dir == 'R') {
        prev.pb(E[i]);
      }
      if (E[i].dir == 'L') {
        if (prev.size() == 0) {
          lft.pb(E[i]);
        } else {
          get_ans(prev.back(), E[i]);
          prev.pop_back();
        }
      }
    }
    while (!prev.empty()) {
      rht.pb(prev.front());
      prev.pop_front();
    }
    while (lft.size() >= 2) {
      robot a = lft.front();
      lft.pop_front();
      robot b = lft.front();
      lft.pop_front();
      get_ans(a, b);
    }
    while (rht.size() >= 2) {
      robot a = rht.back();
      rht.pop_back();
      robot b = rht.back();
      rht.pop_back();
      get_ans(a, b);
    }
    if (lft.size() > 0 && rht.size() > 0) {
      get_ans(lft.front(), rht.front());
    }
  }
  if (true) {
    deque<robot> prev;
    deque<robot> lft, rht;
    for (ll i = 0; i < (ll)O.size(); i++)  {
      if (O[i].dir == 'R') {
        prev.pb(O[i]);
      }
      if (O[i].dir == 'L') {
        if (prev.size() == 0) {
          lft.pb(O[i]);
        } else {
          get_ans(prev.back(), O[i]);
          prev.pop_back();
        }
      }
    }
    while (!prev.empty()) {
      rht.pb(prev.front());
      prev.pop_front();
    }
    while (lft.size() >= 2) {
      robot a = lft.front();
      lft.pop_front();
      robot b = lft.front();
      lft.pop_front();
      get_ans(a, b);
    }
    while (rht.size() >= 2) {
      robot a = rht.back();
      rht.pop_back();
      robot b = rht.back();
      rht.pop_back();
      get_ans(a, b);
    }
    if (lft.size() > 0 && rht.size() > 0) {
      get_ans(lft.front(), rht.front());
    }
  }

  for (ll i = 1; i <= n; i++) {
    cout << res[i] << " \n"[i == n];
  }
}
