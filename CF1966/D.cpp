
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
    ll n, k;
    cin >> n >> k;
    ll hb=-1;
    for (ll i = 0; i < 20; i++) {
        if ((1<<i)&k) {
            hb = i;
        }
    }
    Vec<ll> v;
    ll b=hb;
    for (ll i = 0; i < 20; i++) {
        if (i == b) {
            if(b>=0){
                v.pb(k-(1<<i));
            }
        }else{
            v.pb(1<<i);
        }
    }
    ll j=1;
    sort(begin(v),end(v),greater<ll>());
    while(v.size()!=25) {
        v.pb(k+(j++));
        if (j==3)break;
    }
    if (v.size() < 25) {
        v.pb((1<<(b+1))+1);
    }
                
    sort(begin(v),end(v));
    cout<<v.size()<<'\n';
    for(auto&x:v)
        cout<<x<<" ";
    cout<<"\n";
}
