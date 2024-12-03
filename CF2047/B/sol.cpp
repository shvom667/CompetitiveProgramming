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
  ll n;cin>>n;string s;cin>>s;ll f[26];for(ll i=0;i<26;i++)f[i]=0;
  for(ll i=0;i<n;i++){
    f[s[i]-'a']+=1;
  }
  ll mi=max_element(f,f+26)-f;
  ll m1,m2;m1=m2=-1;
  // if(mi>0){
  //   m1=min_element(f,f+mi)-f;
  // }
  // if(mi<25){
  //   m2=min_element(f+mi+1,f+26)-f;
  // }
  // if(m1==-1&&m2==-1)
  // {
  //   return s;
  // }
  // dbg(mi,m1,m2);
  // if(m1==-1){
  //   m1 = m2;
  //   char p,q;p='a'+m1;q='a'+mi;
  //   for(ll i=0;i<n;i++){
  //     if(s[i]-'a'==m1){
  //       s[i]=q;
  //       break;
  //     }else{

  //     }
  //   }
  //   return s;
  // }
  // if(m2==-1){
  //   char p,q;p='a'+m1;q='a'+mi;
  //   for(ll i=0;i<n;i++){
  //     if(s[i]-'a'==m1){
  //       s[i]=q;
  //       break;
  //     }else{

  //     }
  //   }
  //   return s;
  // }
  // m1 = (f[m2]>f[m1]?m1:m2);
  ll gr = 1e9, gi = -1;
  for (ll i = 0; i < 26; i++) {
    if (i == mi) continue;
    if (f[i] == 0) continue;
    if (f[i] < gr) {
      gr = f[i];
      gi = i;
    }
  }
  m1 = gi;
  if (m1 == -1) {
    return s;
  }
  char p,q;p='a'+m1;q='a'+mi;
  for(ll i=0;i<n;i++){
    if(s[i]-'a'==m1){
      s[i]=q;
      break;
    }else{

    }
  }
  return s;
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
