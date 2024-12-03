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
  set<ll>s;
  for(ll j=0;j<=1000;j++){
    s.insert((2*j+1) * (2*j+1));
  }
  ll fans=0;
  ll n;cin>>n;ll a[n];for(ll i=0;i<n;i++){
    cin>>a[i];
    if(i){
      a[i]+=a[i-1];
      if(s.count(a[i])){
        fans++;
      }
    }
  }
  return fans+1;
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
