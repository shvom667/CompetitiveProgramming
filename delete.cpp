#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

auto solve() {
  int n;
  cin >> n;
  ll a[n];
  deque<ll> d;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    d.pb(a[i]);
  }
  sort(begin(d),end(d));
  vector<ll> fans;
  for (ll i = 0; i < n; i++) {
    if (i)
    fans.pb(d[i]);
    else
      fans.push_front(d[i]);
  }
  ll fans = 0;
  for (ll i = 1; i < n; i++)
    fans += abs(d[i] - d[i - 1]);
  return fans;
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);       

  ll T;
  cin >> T;
  for (ll tc = 1; tc <= T; tc++) {
    auto res = solve();
    cout << res << "\n";
  }
  return 0;
}
