
#include<bits/stdc++.h>
using namespace std;



using ll=long long;

template <typename T>
using V = vector<T>;

#define pb push_back

void solve();

int main() {
    ll t;
    cin>>t;
    while(t--)solve();
}
const ll N = 2e5+20;
ll n, m;
string s;
ll a[N];
ll fr=-1;
V<ll> fans;
ll ans(ll i, ll l,ll r) {
    if(l == r) return fr = a[l] % m; 
    ll p = -1;
    if (s[i] == 'L') {p = ans(i+1,l+1,r);p*=a[l];}
    if (s[i] == 'R') {p = ans(i+1,l,r-1);p*=a[r];}
    p %= m;
    fans.pb(p);
    return p;
}
void solve() {
    fans.clear();
    cin>>n>>m;
    for (ll i=0;i<n;i++) {
        cin>>a[i];
    }
    cin>>s;
    ll res = ans(0,0,n-1);
    reverse(begin(fans),end(fans));
    for(auto&x : fans) {
        cout<<x<<" ";
    }   cout<<fr<<" ";cout<<"\n";

}
