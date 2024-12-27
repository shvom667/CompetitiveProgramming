#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define ld long double
#define endl "\n"
typedef vector<ll> vll;
#define pb              push_back 
#define fori(n)         for (ll i=0; i<n; i++) 
#define forj(n)         for (ll j=0; j<n; j++) 
#define fork(n)         for (ll k=0; k<n; k++) 
#define forn(n)         for (ll i=1; i<=n; i++) 
#define forn2(n)        for (ll j=1; j<=n; j++) 
#define forn3(n)        for (ll k=1; k<=n; k++) 
#define Sort(a)         sort(a.begin(),a.end())


void solve(){

    ll n,m;
    cin>>n>>m;
    vll a(n+1,-1),b(m+1,-1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    vector<ll> v = a;
    Sort(v);
    Sort(b);
    ll ind = 0;
    for(int i=1;i<=m;i++){
        if(b[i]<=a[1]){
            ind = i;
        }
    }
    vll ans(m+1,0);
    for(int k=1;k<=m;k++){
        ll p = m/k;
        ans[k] = p;
        for(ll j = ind+1+m%k;j<=m;j+=k){
            ll x = lower_bound(v.begin(),v.end(),b[j]) - v.begin();
            x = n+1-x;
            ans[k] += x;
        }
    }
    forn(m){
        cout<<ans[i]<<" ";
    }
    cout<<endl;





}

int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Redeem yourself King.
    ll n;
    cin>>n;
    while(n--)solve();
    
   
    return 0;
}
