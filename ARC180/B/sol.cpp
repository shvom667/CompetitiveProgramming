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
const ll INF=1e9+10;
auto bf() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  vector<pair<ll,ll>>F;
  ll fans = 0;
  while(true){
    pair<ll,ll>p={-1,-1};
    ll diff=INF;
    for(ll i=0;i<n;i++){
      for(ll j=i+1;j<n;j++){
        if(j-i>=k && a[i]>a[j]){
          diff=min(diff,a[i]-a[j]);
          if(diff==a[i]-a[j]){
            p={i,j};
          }
        }
      }
    }
    if(p==make_pair(-1,-1)){
      break;
    }
    F.pb(p);
    swap(a[p.first],a[p.second]);
    fans++;
  }
  dbg(a);
  cout<<fans<<"\n";
  for(auto&[u,v]:F){
    cout<<u+1<<" "<<v+1<<'\n';
  }
  return fans;
}

auto geinus() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  vector<pair<ll,ll>>F;
  ll fans = 0;
  while(true){
    pair<ll,ll>p={-1,-1};
    ll diff=INF;
    vector<ll>I(n+1,-1);
    for(ll i=0;i<n;i++){
      I[a[i]]=i;
    }
    set<ll>s;
    for(ll i=n-k-1;i>=0;i--){
      s.insert(a[i+k]);
      auto it=s.upper_bound(a[i]);
      if(it!=begin(s)){
        it--;
        diff=min(diff,a[i]-(*it));
        if (diff == a[i]-(*it)){
          p={i,I[*it]};
        }
      }
    }
    if(p==make_pair(-1,-1)){
      break;
    }
    fans++;
    F.pb(p);
    swap(a[p.first],a[p.second]);
  }
  dbg(a);
  cout<<fans<<"\n";
  for(auto&[u,v]:F){
    cout<<u+1<<" "<<v+1<<'\n';
  }
  return fans;

}


auto euler() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  ll fans = 0;

  return fans;

}

auto solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n + 1);
  for (ll i = 1; i <= n; i++){
    cin >> a[i];
  }
  
  ll sz;cin>>sz;
  for(ll i=0;i<sz;i++){
    ll u,v;cin>>u>>v;swap(a[u],a[v]);
  }
  for(ll i=1;i<=n;i++){
    cout<<a[i]<<" ";
  } cout<<'\n';
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  T=1;
  for (ll tc = 1; tc <= T; tc++) {
    auto res = euler();
    // cout << res << "\n";
  }
  return 0;
}
