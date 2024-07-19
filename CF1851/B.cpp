
#include<bits/stdc++.h>
using namespace std;



using ll=long long;

template <typename T>
using V = vector<T>;

#define pb push_back

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)solve();
}

void solve() {
    ll n;
    cin >> n;
    ll a[n];

    V<ll>e,o,p(n, 0),b;
    for (ll i=0; i<n; i++) {cin >> a[i];
        if(a[i]&1)o.pb(a[i]);
        else e.pb(a[i]);
        if (a[i]&1) p[i] = 1;
    }
    sort(begin(e),end(e),greater<ll>());
    sort(begin(o),end(o),greater<ll>());
    for (ll i=0;i<n;i++) {
        if (p[i]) {
            b.pb(o.back());
            o.pop_back();
        }
        else {
            b.pb(e.back());
            e.pop_back();
        }
    }
    V<ll> c=b;
    sort(begin(c), end(c));
    if(c==b) {
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }
}
