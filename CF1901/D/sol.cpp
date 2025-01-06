#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

auto solve() {
    ll n;cin>>n;vector<ll>a(n+1);for(ll i=1;i<=n;i++)cin>>a[i];
    vector<ll>b(n+1),c(n+1);
    for(ll i=1;i<=n;i++){
        b[i]=n-i+a[i];
        c[i]=a[i]+i-1;
    }
    for(ll i=n-1;i>=1;i--){
        c[i]=max(c[i],c[i+1]);
    }
    for(ll i=2;i<=n;i++){
        b[i]=max(b[i],b[i-1]);
    }
    dbg(b);
    dbg(c);
    ll fans=min(max(c[2],a[1]),max(b[n-1],a[n]));
    for(ll i=2;i<=n-1;i++){
        fans=min(fans,max(max(b[i-1],c[i+1]),a[i]));
    }
    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T=1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
