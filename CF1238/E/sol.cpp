#include <bits/stdc++.h>
using namespace std;
using ll = int;
#define pb push_back
template <typename T> using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif
const ll INF=1e9+20;
auto solve(ll n, ll m, string s) {
  vector<vector<ll>> g(m, vector<ll>(m,0));
  for(ll i=1;i<n;i++){
    ll x,y;x=s[i]-'a';y=s[i-1]-'a';
    g[min(x,y)][max(x,y)]+=1;
  }
  vector<ll> dp((1ll<<m),INF);
  dp[0]=0;
  for(ll sb=1;sb<=m;sb++){
    for(ll mask=1;mask<(1ll<<m);mask++){
      if(__builtin_popcount(mask)==sb){
        for(ll bit=0;bit<m;bit++){
          if(mask&(1ll<<bit)){
            ll contri=0;
            for(ll y=0;y<m;y++){
              if(y==bit)continue;
              if(mask&(1ll<<y)){
                contri+=g[min(y,bit)][max(y,bit)];
              }else{
                contri-=g[min(y,bit)][max(y,bit)];
              }
            }
            contri*=sb;
            dp[mask]=min(dp[mask],dp[(mask^(1ll<<bit))]+contri);
          }
        }
      }
    }
  }

  return dp[(1ll<<m)-1];
}


auto bf(ll n, ll m, string s) {
  auto calc = [&] (vector<char> kb){
    map<char,ll>ind;
    for(ll i=0;i<(ll)kb.size();i++){
      ind[kb[i]]=i;
    }
    ll fans=0;
    for(ll i=1;i<n;i++){
      fans+=abs(ind[s[i]]-ind[s[i-1]]);
    }
    return fans;
  };
  vector<char> a(m);
  for(ll i=0;i<m;i++)a[i]='a'+i;
  ll fans=1e9;
  do{
    fans=min(fans,calc(a));
  }while(next_permutation(begin(a),end(a)));

  for(ll i=0;i<m;i++)a[i]='a'+i;
  // ll fans=1e9;
  do{
    ll res=calc(a);
    if(res==fans){
      dbg(a);
    }
  }while(next_permutation(begin(a),end(a)));
  map<string,ll>mp;
  for(ll i=0;i<n;i++){
    string cur="";cur+=s[i];cur+=s[(i+1)%n];
    mp[cur]++;
  }
  for(auto&[u,v]:mp){
    dbg(u,v);
  }
  return fans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  T=1;
  for (ll tc = 1; tc <= T; tc++) {  
    ll n,m;string s;cin>>n>>m>>s;
    auto res = solve(n,m,s);
    cout << res << "\n";
  }
  return 0;
}
