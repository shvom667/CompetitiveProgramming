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
    ll n;string a,b;cin>>n>>a>>b;
    if(a==b)return 0ll;
    ll fi,bi;fi=bi=0;
    for(ll i=0;i<n;i++)if(a[i]!=b[i])fi++;
    for(ll i=0;i<n;i++)if(a[i]!=b[n-i-1])bi++;
    ll a1,a2;
    if(fi&1){
        a1=2*fi-1;
    }else{
        a1=2*fi;
    }
    if(bi&1){
        a2=2*bi;
    }else{
        a2=2*bi-1;
        if(bi==0)a2=2;
    }
    return min(a1,a2);
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
