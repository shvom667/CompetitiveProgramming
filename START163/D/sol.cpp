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
    ll n, k;
    cin >> n >> k;
    string s, p; cin>>s>>p;
    if (k > n) {
        return "NO";
    }
    if ((n%2)!=(k%2)){
        return "NO";
    }
    if(p[0]!=s[0]){
        return "NO";
    }
    if(s[n-1]!=p[k-1]){
        return "NO";
    }
    vector<ll>v;
    ll cnt=0;
    for(ll i=0;i<n;i++){
        if(i==0 || s[i]!=s[i-1]){
            if(cnt>0)v.push_back(cnt);
            cnt=1;
        }    else{
            cnt++;
        }
    }
    v.pb(cnt);

    vector<ll>u;
    cnt=0;
    for(ll i=0;i<k;i++){
        if(i==0 || p[i]!=p[i-1]){
            if(cnt>0)u.push_back(cnt);
            cnt=1;
        }    else{
            cnt++;
        }
    }
    u.pb(cnt);

    dbg(u);
    dbg(v);

    if((ll)v.size()!=(ll)u.size()){
        return "NO";
    }
    if ((ll)v.size() == 1) {
        if(v[0]!=u[0]){
            return "NO";
        }else{
            return "YES";
        }
    }
    for(ll i=0;i<(ll)v.size();i++){
        if(((v[i])%2) != (u[i]%2)) {
            return "NO";
        }
        if(v[i] < u[i]) {
            return "NO";
        }    
    }

    return "YES";
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
