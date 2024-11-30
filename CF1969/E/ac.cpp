#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
#define dbg(...) 42
#endif

auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll fans=0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  // vector<vector<ll>> ind(n + 1);
  // for (ll i = 0; i < n; i++) {
  //   ind[a[i]].pb(i);
  // }
  // vector<ll> pi(n, -1), ni(n, n);
  // map<ll, ll> mp1,mp2;
  // for (ll i = 0; i < n; i++) {
  //   if(mp1.find(a[i])==mp1.end()) {
  //     pi[i] = -1;
  //   } else {
  //     pi[i] = mp1[a[i]];
  //   }
  //   mp1[a[i]] = i;
  // }
  // for(ll i=n-1;i>=0;i--){
  //   if(mp2.find(a[i])==mp2.end()){
  //     ni[i]=n;
  //   }else{
  //     ni[i]=mp2[a[i]];
  //   }
  //   mp2[a[i]]=i;
  // }
  // vector<pair<ll,ll>> uq;
  // for(ll i=0;i<n;i++){
  //   uq.push_back({pi[i]+1,ni[i]-1});
  // }
  // sort(begin(uq),end(uq),[&](auto x,auto y){
  //   return x.first>y.first;
  // });
  // dbg(uq);
  // vector<ll>w(n,-1);
  // ll ct=-1;
  // for(ll i=0;i<n;i++){
  //   while(!uq.empty()&&uq.back().first<=i){
  //     auto p=uq.back();
  //     uq.pop_back();
  //     ct=max(ct,p.second);
  //     // w[i]=max(ct+1,i);
  //   }
  //   w[i]=max(ct+1,i);
  // }
  // dbg(w);

  // set<ll> S;
  // for (ll i = 1; i <= n; i++) {
  //   S.insert(i);
  // }
  // for (ll i = 0; i < n; i++) {
  //   if (S.count(a[i])) {
  //     S.erase(a[i]);
  //   }
  // }
  // for (ll i = 1; i < n; i++) {
  //   if (a[i] == a[i - 1]) {
  //     a[i]=*S.begin();
  //     S.erase(*S.begin());
  //     fans++;
  //   }
  // }
 
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
  for (ll i = 0; i < n; i++) {
    map<ll,ll>mp;
    ll cnt=0;
    for (ll j = i; j < n; j++) {
      mp[a[j]]++;
      if(mp[a[j]]==1){
        cnt++;
      }else if(mp[a[j]]==2){
        cnt--;
      }
      if(cnt==0){
        pq.push({j-i+1,i});
        break;
      }
    }
  }
  dbg(pq);
  // for (ll i = 1; i <= n; i++) {
  //   for (ll j = 1; j < (ll)ind[i].size(); j++) {
  //     pq.push({ind[i][j]});
  //   }
  // }
  // for (ll i = 0; i < n; i++) {
  //   for (ll j = i; j < n; j++) {
  //     map<ll, ll> mp;
  //     for (ll k = i; k <= j; k++) {
  //       mp[a[k]]++;
  //     }
  //     bool ok = false;
  //     for (ll k = i; k <= j; k++) {
  //       if (mp[a[k]] == 1) ok = true;
  //     }
  //     if (!ok) {
  //       pq.push({j - i + 1, i});
  //     }
  //   }
  // }
  // for(ll i=0;i<n;i++){
  //   if(w[i]<n){
  //     pq.push({w[i]-i+1,i});
  //   }
  // }
  dbg(pq);
  vector<pair<ll,ll>>found;
  while (!pq.empty()) {
    auto t = pq.top();
    pq.pop();
    bool seen=false;
    for(auto&[u,v]:found) {
        if (t.second<=u&&t.second+t.first-1>=v) {
        seen=true;
      }
    }
    if (!seen) {
      found.push_back({t.second,t.first+t.second-1});
    }
  }
  dbg(found);
  ll lc=-1;
  sort(begin(found),end(found),[&](auto x,auto y){
    return x.first < y.first;
  });
  for(auto&[u,v]:found) {
    if(lc>=u)continue;
    lc=v;
    dbg(u,v,lc);
    fans++;
  }
  return fans;
}

int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);

  ll T;
  T = 1;
  // cin >> T;
  for (ll tc = 1; tc <= T; tc++) {
    auto res = solve();
    cout << res << "\n";
  }
  return 0;
}
