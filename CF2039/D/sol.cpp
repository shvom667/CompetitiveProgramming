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
  ll n,m;
  cin>>n>>m;
  vector<ll> a(m);
  for (ll i = 0; i < m; i++) {
    cin >> a[i];
  }
  sort(begin(a),end(a),greater<ll>());
  dbg(log2(n)+1);
  if(m<(ll)log2(n)+1){
    cout<<-1<<'\n';
    return 0;
  }
  vector<ll> res(n+1);

  ll ca = 0;
  res[1] = a[ca++];
  res[2] = a[ca++];
  for (ll i = 3; i <= n; i++) {
    set<ll> cant;
    for(ll j = 1; j <= sqrtl(i); j++) {
      if (i % j == 0) {
        cant.insert(res[j]);
        if (i / j != i) {
          cant.insert(res[i/j]);
        }
      }
    }
    dbg(cant);
    for(ll j = 0; j < m; j++) {
      if (cant.count(a[j])==0){
        res[i]=a[j];
        break;
      }
    }
  }

  for(ll i=1;i<=n;i++){
    cout<<res[i]<< " ";
  }cout<<'\n';
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  for (ll tc = 1; tc <= T; tc++) {
    auto res = solve();
    // cout << res << "\n";
  }
  return 0;
}
