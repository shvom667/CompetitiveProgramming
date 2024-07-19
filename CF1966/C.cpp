
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
    ll n;
    cin >> n;
    ll a[n];
    map<ll,ll>mp;
    for (ll i = 0; i  < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    Vec<ll>v;
    for(auto&[x,y]:mp){
        v.pb(x);
    }
    sort(begin(v),end(v));
    bool ok=false;
    if (v[0] >= 2) {
        cout<<"Alice\n";
        return;
    }
    for(ll i = 1; i < (ll)v.size()-1; i++) {
        if (v[i]-v[i-1]>1){
            if(i&1){
                cout<<"Bob\n";
                return;
            }else{
                cout<<"Alice\n";
                return;
            }
        }
    }
    if((ll)v.size()%2==1)
        cout<<"Alice\n";
    else
        cout<<"Bob\n";
}
