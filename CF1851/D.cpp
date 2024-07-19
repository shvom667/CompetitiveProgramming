
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
    cin>>n;
    ll a[n];
    V<ll> d;
    for (ll i=0; i<n-1; i++) {
        cin >> a[i];
        if (i) d.pb(a[i]-a[i-1]);
    }
    d.pb(a[0]);
    sort(begin(d),end(d));
    set<ll> p;
    for (ll i=1; i<=n; i++) p.insert(i);
    V<ll> nf;
    for (auto&x:d) {
        if(p.find(x) != p.end()) {
            p.erase((x));
        } else {
            nf.pb(x);
        }
    }
    if(nf.size()>1) {
        cout<<"NO\n";
            return;
    }
    ll sum=0;
    if(p.size()==1) {
        cout<<"YES\n";
        return;
    }
    for(auto&x:p) sum+=x;
    //cout<<sum<<"\n";
    if(p.size()==2) {
        if(binary_search(begin(nf),end(nf),sum)) {
            cout<<"YES\n";
        } else{
            cout<<"NO\n";
        }
        return;
    }
    cout<<"NO\n";
}
