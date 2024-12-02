#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif
/*
  1. MAX 0, MIN 1 swap
  2. iterate over the array till zero does not appear min 2, max 1
  3. min 2, max 0, max 1
*/

auto solve(vector<ll> a, ll n) {
  // ll n;
  // cin >> n;
  // vector<ll> a(n);
  cout << n << "\n";
  for (auto&x : a) {
    cout << x << " ";
  } cout <<'\n';
  vector<pair<ll, ll>> op;
  set<ll> s[3];
  for (ll i = 0; i < n; i++) {
    // cin >> a[i];
    s[a[i]].insert(i);
  }
  auto swp = [&] (ll x, ll y) {
    s[a[x]].erase(x);
    s[a[y]].erase(y);
    s[a[x]].insert(y);
    s[a[y]].insert(x);
    op.pb({x, y});
    swap(a[x], a[y]);
  };
  auto get_max = [&] (ll i) {
    assert(i >= 0 && i < 3);
    if (s[i].empty()) return -1ll;
    return *s[i].rbegin();
  };
  auto get_min = [&] (ll i) {
    assert(i >= 0 && i < 3);
    if (s[i].empty()) return -1ll;
    return *s[i].begin();
  };
  while (true) {
    ll max_0, min_1;
    max_0 = get_max(0);
    min_1 = get_min(1);
    if (max_0 == -1 || min_1 == -1) break;
    if (max_0 < min_1) break;
    swp(max_0, min_1);
  }
  dbg(a);
  dbg(op);
  vector<ll> v2;
  for (ll i = n - 1; i >= 0; i--) {
    if (a[i] == 2) {
      v2.pb(i);
    }
    if (a[i] == 0) break;
    if (a[i] == 1) continue;
  }
  dbg(v2);
  while (!v2.empty()) {
    auto b = v2.back();
    v2.pop_back();
    ll max_1 = get_max(1);
    if (max_1 < b) continue;
    swp(b, max_1);
  }
  dbg(a);
  dbg(op);

  while (true) {
    ll min_2, max_0, max_1;
    min_2 = get_min(2);
    max_0 = get_max(0);
    max_1 = get_max(1);
    if (min_2 == -1 || max_0 == -1 || max_1 == -1) break;

    dbg(min_2, max_0, max_1);
    if (min_2 > max_1) {
      break;
    }
    if (min_2 > max_0) {
      vector<ll> v2;
      for (ll i = n - 1; i >= 0; i--) {
        if (a[i] == 2) {
          v2.pb(i);
        }
        if (a[i] == 0) break;
        if (a[i] == 1) continue;
      }
      dbg(v2);
      while (!v2.empty()) {
        auto b = v2.back();
        v2.pop_back();
        ll max_1 = get_max(1);
        if (max_1 < b) continue;
        swp(b, max_1);
      }

      break;
    }
    assert(min_2 < max_0);
    swp(min_2, max_1);
    swp(min_2, max_0);
  }

  // while (true) {
  //   ll min_2, max_0, max_1;
  //   // min_2 = get_max(2);
  //   max_0 = get_max(0);
  //   max_1 = get_max(1);
  //   auto it = s[2].lower_bound(max_0);
  //   if (it == begin(s[2])) break;
  //   --it;
  //   min_2 = *it;
  //   if (min_2 == -1 || max_0 == -1 || max_1 == -1) break;
  //   assert(max_0 < max_1);
  //   dbg(min_2, max_0, max_1);
  //   if (min_2 > max_1) {
  //     break;
  //   }
  //   assert(min_2 < max_0);
  //   swp(min_2, max_1);
  //   swp(min_2, max_0);
  // }



  dbg(a);
  dbg(op);
  cout << op.size() << '\n';
  for (auto& [x, y] : op) {
    cout << x + 1 << " " << y + 1 << '\n';
  }
  return op;
}

auto bf() {
  while (true) {
    ll n = rnd(2, 20);
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
      a[i] = rnd(0,2);
    }
    a[rnd(0,n-1)]=1;
    dbg(a);
    auto res = solve(a, n);
    auto give_test = [&] () {
      cout << n << "\n";
      for (auto&x : a) {
        cout << x << " ";
      } cout << '\n';
    };
    bool bad = false;
    if (res.size() > n) {
      bad = true;
      dbg("size is bad");
      give_test();
      exit(0);
    }
    vector<ll> b = a;
    for (auto& [x,y]: res) {
      // x--; y--;
      swap(a[x], a[y]);
    }
    sort(begin(b),end(b));
    if (b != a) {
      bad = true;
      dbg("final not sorted");
      give_test();
      exit(0);
    }
    cout << "OK\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // bf();

  ll T;
  cin >> T;
  for (ll tc = 1; tc <= T; tc++) {
    ll n; cin >> n; vector<ll> a(n); for (ll i = 0; i < n; i++) cin >> a[i];
    auto res = solve(a, n);
    // cout << res << "\n";
  }
  return 0;
}
