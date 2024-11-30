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

// ============

vector<int> MinPrime;
vector<int> PRIME;
void pre_calc_sieve(int N) {
  MinPrime = vector<int>(N + 1, 0);
  for (int i = 2; i <= N; ++i) {
    if (MinPrime[i] == 0) {
      MinPrime[i] = i;
      PRIME.push_back(i);
    }
    for (int j = 0; i * PRIME[j] <= N; ++j) {
      MinPrime[i * PRIME[j]] = PRIME[j];
      if (PRIME[j] == MinPrime[i]) {
        break;
      }
    }
  }
}

// ============
const ll N = 2e6 + 20;

const ll MOD = 998244353;

auto solve() {
  ll n;
  cin >> n;
  vector<ll> ans(N, 0), a(n + 1, 0), f(n + 1, 0);
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  f[1] = 1;

  auto get_rep = [&](ll x) {
    vector<ll> pf;
    while (x > 1) {
      ll mp = MinPrime[x];
      while (x % mp == 0) {
        x /= mp;
      }
      pf.pb(mp);
    }
    ll sz = pf.size();
    vector<vector<ll>> res(sz + 1);
    for (ll j = 1; j < (1 << sz); j++) {
      ll val = 1;
      for (ll k = 0; k < sz; k++) {
        if (j & (1 << k)) {
          val *= pf[k];
        }
      }
      res[__builtin_popcount(j)].pb(val);
    }
    return res;
  };

  auto rep = get_rep(a[1]);

  for (auto &x : rep) {
    for (auto &u : x) {
      ans[u] += 1;
    }
  }

  for (ll i = 2; i <= n; i++) {
    auto rep = get_rep(a[i]);

    dbg(i, rep);

    for (ll k = 0; k < (ll)rep.size(); k++) {
      for (auto &j : rep[k]) {
        if (k & 1) {
          long long x = (long long)f[i] + ans[j];
          if (x >= MOD)
            x %= MOD;
          f[i] = x;
        } else {
          long long x = (long long)f[i] - ans[j];
          if (x < 0) {
            assert(abs(x) <= MOD);
            x += MOD;
            x %= MOD;
          }
          f[i] = x;
        }
      }
    }
    for (auto &x : rep) {
      for (auto &u : x) {
        long long x = (long long)ans[u] + f[i];
        if (x >= MOD) {
          x %= MOD;
        }
        ans[u] = x;
      }
    }
  }

  // for(ll i=1;i<=n;i++){
  //     cout<<f[i]<< " ";
  // }   cout<<'\n';

  return f[n];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pre_calc_sieve(2e6 + 20);
  ll T;
  // cin >> T;
  T = 1;
  for (ll tc = 1; tc <= T; tc++) {
    auto res = solve();
    cout << res << "\n";
  }
  return 0;
}
