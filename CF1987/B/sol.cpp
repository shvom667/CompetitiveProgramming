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
 
auto solve() {
    ll n;cin>>n; ll a[n];
    ll sq=0;
    ll pmax=0,fans=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>pmax){pmax=a[i];continue;}
        ll cm=pmax-a[i];
        ll csq=max(sq,pmax-a[i]);
        fans += max(0ll,csq-sq);
        fans += pmax-a[i];
        sq=max(csq,sq);
        pmax=max(pmax,a[i]);
    }
    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
