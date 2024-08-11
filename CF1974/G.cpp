#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--) solve();
}

void solve() {
  ll m, x;
  cin>>m>>x;
  ll c[m+1];
  for(ll i=1;i<=m;i++)
    cin>>c[i];
  ll a = x;
  priority_queue<ll> pq;
  ll cnt=0;
  for(ll i=2;i<=m;i++){
    if(a-c[i]>=0){
      a-=c[i];
      pq.push(c[i]);
      cnt++;
    }else{
      if(!pq.empty() && pq.top()>=c[i]){
        ll t=pq.top();
        pq.pop();
        a+=t;
        a-=c[i];
        pq.push(c[i]);
      }
    }
    a += x;
  }
  cout<<cnt<<'\n';
}
