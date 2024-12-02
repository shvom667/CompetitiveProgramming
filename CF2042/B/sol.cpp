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

auto solve() {
  ll n;
  cin >> n;
  map<ll, ll> mp;
  Vec<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  vector<ll> f;
  for (auto&[u,v]: mp){
    f.pb(v);
  }
  sort(begin(f),end(f));
  ll c1 = 0, cx = 0;
  for(auto&x:f){
    c1 += x == 1;
    cx += x > 1;
  }
  
  return ((c1 + 1) / 2) * 2 + cx;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  for (ll tc = 1; tc <= T; tc++) {
    auto res = solve();
    cout << res << "\n";
  }
  return 0;
}
