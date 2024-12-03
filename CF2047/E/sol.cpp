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

auto solve(ll n, Vec<pair<ll,ll>> in) {
  return 0;
}
auto bf(ll n, Vec<pair<ll,ll>> x) {
  ll fans=0;
  pair<ll,ll>f;
  
  for(ll i=0;i<n;i++){
    ll a,b,c,d;a=b=c=d=0;
    for(ll j=0;j<n;j++){
      if(x[j].first>=x[i].first&&x[j].second>=x[i].second)a++;
      if(x[j].first<x[i].first&&x[j].second>=x[i].second)b++;
      if(x[j].first>=x[i].first&&x[j].second<x[i].second)c++;
      if(x[j].first<x[i].first&&x[j].second<x[i].second)d++;
    }
    assert(a+b+c+d==n);
    fans=max(fans,min({a,b,c,d}));
    if(fans==min({a,b,c,d})){
      f=x[i];
    }
  }
  dbg(fans);
  dbg(f);
  return fans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  for (ll tc = 1; tc <= T; tc++) {
    ll n;cin>>n;vector<pair<ll,ll>>in(n);for(ll i=0;i<n;i++)cin>>in[i].first>>in[i].second;
    auto res = bf(n,in);
    cout << res << "\n";
  }
  return 0;
}
