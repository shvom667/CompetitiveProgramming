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
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    map<ll,ll>mp;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    vector<ll> v;
    for(auto&[u,f]:mp){
        v.pb(f);
    }
    sort(begin(v),end(v),greater<ll>());
    ll fans=1;
    while(!v.empty() && v.back()<=k){
        k-=v.back();
        v.pop_back();
    }
    fans=max(fans,(ll)v.size());
    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
