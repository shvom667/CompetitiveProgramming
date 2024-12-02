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
ll tc = 0;
const int N = 11;
ll f[N];
auto solve(ll n, ll k) {
  // if (tc == 936) {
  //   cout<<n<<"|"<<k<<'\n';
  //   return;
  // }
  if (n == 1) {
    if (k > 1) {
      cout << "NO\n";return;
    }
    if (k == 1) {
      cout << "YES\n";
      cout << 1 << "\n";
      return;
    }
  }
  ll K = k;
  if (n < N) {
    if (k == f[n] - 1) {
      cout << "NO\n";return;
    }
    if (k > f[n]) {
      cout << "NO\n";return;
    }
  }
  if (k == 1) {
    cout << "NO\n"; return;
  }
  if (n % 2 == 0 && k % 2 == 1) {
    cout << "NO\n"; return;
  }
  map<vector<ll>, ll> mp;
  vector<vector<ll>> fans;
  auto getInv = [&] (vector<ll> a) {
    vector<ll> b(n);
    for (ll i = 0; i < n; i++) {
      b[i] = n + 1 - a[i];
    }
    return b;
  };

  if (k & 1) {
    vector<ll> a, b;
    for (ll i = 1; i <= n; i++) {
      a.pb(i);
    }
    for (ll i = 1; i <= n / 2; i++) {
      b.pb(n / 2 + 1 + i);
    }
    for (ll i = 1; i <= (n + 1) / 2; i++) {
      b.pb(i);
    }
    vector<ll> c(n);
    for (ll i = 0; i < n; i++) {
      c[i] = ( (n + 1) *  3 ) / 2 - a[i] - b[i];
    }
    // dbg(a);
    // dbg(b);
    // dbg(c);
    fans.pb(a);
    fans.pb(b);
    fans.pb(c);
    mp[a] = true;
    mp[getInv(a)] = true;
    mp[b] = true;
    mp[getInv(b)] = true;
    mp[c] = true;
    mp[getInv(c)] = true;
    
    k -= 3;
  }
  for (auto&[u, v] : mp) {
    // dbg(u);
  }
  vector<ll> v; for (ll i = 1; i <= n; i++) v.pb(i);

  do {
    if (k > 0) {
      if (mp.find(v) == mp.end()) {
        mp[v] = true;
        auto vv = getInv(v);
        mp[vv] = true;
        fans.pb(v);
        fans.pb(vv);
        k -= 2;   
      }
    }
  } while(k > 0 && next_permutation(begin(v), end(v)));
  // dbg(fans);

  auto validate = [&] {
    bool ok = true;
    for (ll j = 0; j < n; j++) {    
      ll cur = 0; 
      for (ll i = 0; i < fans.size(); i++) {
        cur += fans[i][j];
      }
      if (true) {
        // dbg(cur);
        dbg(j, cur, (n + 1) * K / 2, K);
        ok = cur == ((n + 1) * K ) / 2;
      } 
    }
    return ok;
  };
  if (!validate()) {
    for (auto&x: fans) {
      dbg(x);
    }
    assert(false);
    exit(0);
  }
  cout << "YES\n";
  for (ll i = 0; i < (ll) fans.size(); i++) {
    for (ll j = 0; j < n; j++) {
      cout << fans[i][j] << " ";
    } cout << '\n';
  }

}

auto bf(ll n, ll k) {
  vector<ll> v(n);
  for (ll i = 0; i < n; i++) {
    v[i] = i + 1;
  } 
  Vec<Vec<ll>> g;
  do {
    g.pb(v);
  } while (next_permutation(begin(v), end(v)));
  // dbg(g);
  ll sz = (ll)g.size();
  for (ll mask = 0; mask < (1ll << sz); mask++) {
    if (__builtin_popcount(mask) == k) {
      vector<vector<ll>> cur;
      for (ll bit = 0; bit < sz; bit++) {
        if (mask & (1ll << bit)) {
          cur.pb(g[bit]);
        }
      }
      ll sum = 0;
      for (ll i = 0; i < cur.size(); i++) {
        sum += cur[i][0];
      }
      bool ok = true;
      for (ll j = 0; j < cur[0].size(); j++) {
        ll val = 0;
        for (ll i = 0; i < (ll)cur.size(); i++) {
          val += cur[i][j];
        }

        if (val != sum) {
          ok = false;
        }
      }
      if (ok) {
        cout << "YES\n";
        for (ll i = 0; i < cur.size(); i++) {
          for (ll j = 0; j < n; j++) {
            cout << cur[i][j] << " ";
          } cout<<'\n';
        }
        return;
      }
    }
  }
  cout << "NO\n";
}

void gen() {
  while (true) {
    ll n, k;
    n = rnd(1, 100);
    k = rnd(1, 200);

    cout << n << " " << k << "\n";
    // exit(0);
    solve(n, k);
  }
}

int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);



  f[0] = 1;
  for (ll i = 1; i < N; i++) {
    f[i] = i * f[i - 1];
  }

  // gen();

  ll T;
  cin >> T;
  for (tc = 1; tc <= T; tc++) {
    ll n , k;
    cin >> n >> k;
    solve(n, k);
    // cout << res << "\n";
  }
  return 0;
}
/*
n! - 1 will never be a solution eg n = 2, k = 1 and n = 3 k = 5


*/
