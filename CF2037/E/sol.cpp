#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
ll ask(ll l, ll r) {
    cout << "? " << l << " " << r << endl;
    ll x;cin>>x;return x;
}
auto solve() {
    ll n;cin>>n;
    ll tot=ask(1,n);
    if(tot==0){
        cout<<"! IMPOSSIBLE"<<endl;
        return;
    }
    ll k,fz;
    vector<ll>a(n+1);
    for(ll j=2;j<=n;j++){
        ll aj=-1;
        if(j<n)
            aj=ask(j,n);
        if(!(j==n) && aj==tot){
            a[j-1]=1;
        }else{
            a[j-1]=0;
            fz = j-1;
            k = j;
            break;
        }
    }
    ll pre=0;
    for(ll v=k;v<=n-1;v++){
        ll res=ask(fz,v);
        if(res>pre){
            a[v]=1;
        }else{
            a[v]=0;
        }
        pre=res;
    }
    if(pre==tot){
        a[n]=0;
    }else{
        a[n]=1;
    }
    cout <<"! ";
    for(ll i=1;i<=n;i++){
        cout<<a[i];
    }cout<<endl;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        // auto res = solve();
        // cout << res << "\n";
        solve();
    }
    return 0;
}
