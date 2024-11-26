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
    ll n;cin>>n;
    if(n<=4){
        cout<<-1<<'\n';return;
    }
    ll a[n+1];
    for(ll i=1;i<=(n+1)/2;i++){
        a[i] = 2*i-1;
    }
    for(ll j=(n+1)/2+1,k=1;j<=n;j++,k++){
        a[j]=2*k;
    }
    swap(a[(n+1)/2+1],a[(n+1)/2+2]);
    swap(a[(n+1)/2],a[3]);
    for(ll i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }   cout<<'\n';
    // return 0;
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
