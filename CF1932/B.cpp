
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
ll ub (ll x, ll y) {
    return (x+y-1)/y;
}
void solve() {
    ll n;
    cin>>n;
    ll a[n];
    for (ll i=0;i<n;i++)cin>>a[i];
    ll p = a[0];
    for (ll i=1;i<n;i++) {
        ll t = ub(p +1, a[i]);
        t *= a[i];
        p = t;
    }
    cout<<p<<"\n";
}
