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
const int N = 2e7 + 20;
int S[N],sz;
vector<int> seen;
auto solve() {
  ll x, m;
  cin >> x >> m;
  ll fans = 0;
  // set<ll> S;
  ll X = log2(x)+1;
  
  for (ll  y = 1; y <= min(m, (1ll << X)-1); y++) {
    if ((x^y)%y == 0) {
      // S.insert(y);
      if(S[y] == 0) {
        S[y]=1;
        seen.pb(y);
        sz++;
      }
    }
  }

  for (ll z = 1; z < (1ll << X); z++) {
    ll y = (x ^ (z*x));

    if (y == 0) continue;
    if (y >= 1 && y <= m) {
      // S.insert(y);
      if (y <= min(m, (1ll<<X)-1)) {
        if(S[y] == 0) {
          S[y]=1;
          seen.pb(y);
          sz++;
        }
      }
      else {
        dbg("hello");
        fans++;
      }
    }
  }
  dbg(fans);
  fans += sz;
  dbg(fans);
  if (m / x + 1 >= (1ll << X)) {
    ll s = max(m/x+1-4, (1ll<<X));

    for(ll z=s;z<=m/x+1;z++){
      ll y = (x ^ (z*x));

      if (y == 0) {
        continue;
      }
      if (y >= 1 && y <= m) {
        // S.insert(y);
        fans++;
      }else{
      }
    }
    
    if(s-1>=(1ll<<X))
    fans += s-1 - (1ll << X) + 1;
  }
  for(auto&x:seen){
    S[x]=0;
  }
  seen.clear();
  sz = 0;
  return fans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  T=1;
  //  cin >> T;
  for (ll tc = 1; tc <= T; tc++) {
    auto res = solve();
    cout << res << "\n";
  }
  return 0;
}
