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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  T = 1;
  // cin >> T;
  for (ll tc = 1; tc <= T; tc++) {
    auto res = solve();
    cout << res << "\n";
  }
  return 0;
}
