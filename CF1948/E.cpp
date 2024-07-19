
#include<bits/stdc++.h>
using namespace std;



using ll=long long;

template <typename T>
using Vec = vector<T>;

#define pb push_back

void solve();

int main() {
    ll t;
    cin>>t;
    while(t--)solve();
}

ll ub(ll x, ll y) {
    return (x + y - 1) / y;
}

void solve() {
    ll n,k;
    cin>>n>>k;


    Vec<ll>res;
    for (ll i=(k+1)/2; i<=k; i++) res.pb(i);
    for (ll i=1;i<=(k-1)/2;i++) res.pb(i);
    ll p=1;
    for (ll j=2;j<=n/k;j++) {
        for (ll i=0;i<k;i++) {
            res.pb(p*k+res[i]);
        }
        p++;
    }
    ll lft=n-(n/k)*k;
    if(lft) {
        Vec<ll> q;
        for (ll i=1; i<=lft; i++) q.pb(i);
        Vec<ll> ord(k+1);
        for (ll i=0; i<k;i++) ord[res[i]] = i;
        if (n/k==0) {res.clear();p=0;}
        sort(begin(q),end(q),[&](ll x, ll y) {
                return ord[x] < ord[y];
                });
        for(auto&x:q){
            res.pb(p*k+x);
        }
    }
    for(auto&x:res){
        cout<<x<<" ";
    }   cout<<"\n";
    cout << ub(n,k) << "\n";
    for (ll i=1; i<=n; i++) {
        cout << ub(i, k) << " ";
    }   cout<<"\n";
}
