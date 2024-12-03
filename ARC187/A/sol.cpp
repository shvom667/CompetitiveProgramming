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

auto give(vector<ll> fans) {
  cout<<"Yes\n";
  cout<<(ll)fans.size()<<'\n';
  for(auto&x:fans){
    cout<<x+1<<" "; 
  } cout<<'\n';
}

auto solve(ll n, ll k, vector<ll> a) {
  Vec<ll>b=a;
  if (n == 2) {
    if(a[1]>=a[0]){
      Vec<ll>fans;
      give(fans);return;
    }else{
      swap(a[0],a[1]);
      a[0]+=k;
      vector<ll>fans;
      if(a[1]>=a[0]){
        fans.pb(0);
        give(fans);return;
      }else{
        cout<<"No\n";return;
      }
    }
  }
  vector<ll>fans;
  for(ll i=1;i<=n-3;i++){
    while(a[i]<a[i-1]){
      fans.pb(i);
      fans.pb(i);
      a[i]+=k;
      a[i+1]+=k;
    }
  }
  dbg(fans);
  dbg(a);
  while(a[n - 2] < a[n - 1]+2*k) {
    fans.pb(n - 3);
    fans.pb(n - 3);
    a[n - 3] += k;
    a[n - 2] += k;
  }
  dbg(fans);
  dbg(a);
  fans.pb(n-2);
  swap(a[n-1],a[n-2]);
  a[n-2]+=k;
  assert(a[n-2]<=a[n-1]);
  while(a[n-2]<a[n-3]){
    fans.pb(n-2);fans.pb(n-2);
    a[n-2]+=k;
    a[n-1]+=k;
  }
  for(ll i=1;i<n;i++){
    assert(a[i]>=a[i-1]);
  }
  dbg(fans);
  for(auto x:fans){
    // x--;
    swap(b[x],b[x+1]);
    b[x]+=k;
  }
  dbg(b);
  assert(a==b);
  dbg(a);
  dbg(fans);
  give(fans);
}

void bf() {
  while(true) {
    dbg("$$$$$$$$$$$$$$$$$$$$$$");
    ll n = rnd(2, 20), k = rnd(1, 20);
    vector<ll>a;
    for(ll i=0;i<n;i++){
      a.pb(rnd(1,50));
    }
    cout<<n<<' '<<k<<'\n';
    for(auto x:a){
      cout<<x<<" ";
    } cout<<'\n';
    solve(n, k, a);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // bf();

  ll T;
  T = 1;
  for (ll tc = 1; tc <= T; tc++) {
    ll n,k;cin>>n>>k;Vec<ll>a(n);for(ll i=0;i<n;i++)cin>>a[i];
    solve(n, k, a);
    // cout << res << "\n";
  }
  return 0;
}
/*
##case
n = 2 k = 5
2 1
not possible

##case
n = 3 k = 5
3 2 1
- 8 11 12

##case
n = 3 k = 5
2 3 1
- possible

##case


*/
