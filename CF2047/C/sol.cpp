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
  ll n;cin>>n;ll g[2][n];for(ll i=0;i<2;i++)for(ll j=0;j<n;j++)cin>>g[i][j];
  ll fans=-1e18;
  for(ll j=0;j<n;j++){
    ll cur=0;cur+=g[0][j]+g[1][j];
    for(ll k=0;k<n;k++){
      if(k!=j){
        cur+=max(g[0][k],g[1][k]);
      }
    }
    fans=max(fans,cur);
  }
  return fans;
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
