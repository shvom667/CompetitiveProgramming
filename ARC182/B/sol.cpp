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
  ll n, k;
  cin >> n >> k;
  deque<string>d;
  
  for(ll i=1;i<=min(n,(1ll<<k)-1);i++){
    string res="";
    for(ll bit=0;bit<k-1;bit++){
      if(i&(1ll<<bit)){
        res+='1';
      }else{
        res+='0';
      }
    }
    d.pb(res);
  }
  dbg(d);
  for(auto&s:d){
    s='1'+s;
    reverse(begin(s),end(s));
  }
  dbg(d);
  vector<ll>fans;
  for(auto&s:d){
    ll cur=0;
    for(ll i=0;i<(ll)s.size();i++){
      if(s[i]=='1')cur+=(1ll<<i);
    }
    fans.pb(cur);
  }
  while(fans.size()!=n){
    fans.pb(fans.back());
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
    // cout << res << "\n";
    for(auto&x:res){
      cout<<x<<" ";
    }cout<<'\n';
  }
  return 0;
}
