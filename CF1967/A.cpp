
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
    cin>> n;
    ll a[n],b[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    for(ll i=0;i<n;i++)
        cin>>b[i];
    for (ll r=0;r<=n;r++)
    {
        if (r==n){
            cout<<r<<'\n';
            return;
        }
        bool ok=true;
        for (ll v=n-1;v-r>=0;v--){
            if(b[v]<a[v-r])
                ok=false;
        }
        if(ok){
            cout<<r<<'\n';
            return;
        }
    }
}
