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

auto solve() { return 0; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll x,m ;cin>>x>>m;
  ll fans=0;
  set<ll>S;
  for(ll y=1;y<=m;y++){
      if(((x^y)%x==0) || ((x^y)%y==0)){
          fans++;
          S.insert(y);
      }
  }
  //dbg(S);
  cout<<fans<<'\n';
  return 0;
}
