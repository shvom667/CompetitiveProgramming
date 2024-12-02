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
  string s;cin>>s;ll n=s.size();
  string res="";
  if(n==1){
    cout<<-1<<'\n';
    return 0;
  }
  if(s.size() == 2) {
    if (s[1] == s[1 - 1]) 
      cout << s << '\n';
    else
      cout << -1 << '\n';
    return 0;
  }
  for(ll i=1;i<n;i++){
    if(s[i]==s[i-1]){
      res+=s[i-1];
      res+=s[i];
      cout<<res<<'\n';
      return 0;
    }
  }
  for(ll i=2;i<n;i++){
    set<char> S;S.insert(s[i]);S.insert(s[i-1]);S.insert(s[i-2]);
    if((ll)S.size()==3){
      res+=s[i-2];
      res+=s[i-1];
      res+=s[i];
      cout<<res<<'\n';
      return 0;
    }
  }
  bool ok=true;
  for(ll i=2;i<n;i++){
    if(s[i]==s[i-2]){

    }else ok=false;
  }
  if(!ok)
    assert(false);
  cout<<-1<<'\n';
  return 0; 
}

int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);

  ll T;
  cin >> T;
  for (ll tc = 1; tc <= T; tc++) {
    auto res = solve();
    // cout << res << "\n";
  }
  return 0;
}
