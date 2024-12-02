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
  ll n;
  cin >> n;
  vector<pair<ll,ll>> in(n);
  map<pair<ll, ll>, ll> id;
  vector<ll> fans(n);
  for (ll i = 0; i < n; i++) {
    cin >> in[i].first >> in[i].second;
    id[in[i]] = i;
  }

  vector<pair<ll, ll>> uin;
  for (auto&[u,v]:id) {
    uin.pb({u});
  }

  vector<pair<ll,ll>> a=uin;

  sort(begin(a),end(a),[&](auto x, auto y){
    if(x.second>y.second){
      return true;
    }
    if(x.second==y.second){
      return x.second-x.first>y.second-y.first;
    }
    return false;
  });

  multiset<ll> minl;
  priority_queue<pair<ll,ll>> pql;
  vector<ll> lval(n,-1);
  for(auto&x:a){
    while (!pql.empty() && pql.top().first>x.second)
    {
      auto p=pql.top();
      minl.erase(minl.find(p.first));
      pql.pop();
    }
    if(minl.empty()) {

    }else{
      // max value which is less than or equal to x.first
      auto it=minl.upper_bound(x.first);
      if (it != begin(minl)){
        --it;
        if(*it<=x.first){
          lval[id[x]] = *it;
        }
      }
    }
    pql.push(x);
    minl.insert(x.first);
  }
  dbg(lval);

  // rval

  vector<pair<ll,ll>> b=uin;

  sort(begin(b),end(b),[&](auto x, auto y){
    if(x.first<y.first){
      return true;
    }
    if(x.first==y.first){
      return x.second-x.first>y.second-y.first;
    }
    return false;
  });

  multiset<ll> maxr;
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pqr;
  vector<ll> rval(n,-1);

  for(auto&x:b){
    dbg(x);
    while (!pqr.empty() && pqr.top().first<x.first)
    {
      auto p=pqr.top();
      maxr.erase(maxr.find(p.first));
      pqr.pop();
    }
    if(maxr.empty()) {

    }else{
      // max value which is less than or equal to x.first
      auto it=maxr.upper_bound(x.second-1);
      if (it != end(maxr)){
        // --it;
        if(*it>=x.second){
          rval[id[x]] = *it;
        }
      }
    }
    // pql.push(x);
    pqr.push({x.second,x.first});
    maxr.insert(x.second);
  }
  dbg(rval);

  for(ll i = 0; i < n; i++) {
    if (lval[i] == -1 || rval[i] == -1) {
      fans[i] = 0;
      continue;
    }
    fans[i] = in[i].first-lval[i]+rval[i]-in[i].second;
  }

  // set the answer of multiple values to zero
  map<pair<ll,ll>, ll> freq;
  for(ll i=0;i<n;i++){
    freq[in[i]]++;
  }
  for(ll i=0;i<n;i++){
    if(freq[in[i]]>1){
      fans[i]=0;
    }
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
      cout<<x<<'\n';
    }
  }
  return 0;
}
