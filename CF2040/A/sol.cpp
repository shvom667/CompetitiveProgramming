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
    ll n;cin>>n;ll k;cin>>k;

    map<ll,ll>mp;
    ll a[n];for(ll i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]%k]++;
    }
    for(ll i=0;i<n;i++){
        if(mp[a[i]%k]==1){
            cout<<"YES\n";
            cout<<i+1<<'\n';
            return;
        }
    }
    cout<<"NO\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
	    // auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
