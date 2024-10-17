#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif
 
auto solve() {
    ll fans = 0;
    string s;
    cin >> s;
    map<char,ll> mp;
    for (ll i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }
    ll gmax=0;
    for(auto&[u,v]:mp)gmax=max(gmax,v);
    return (ll)s.size() - gmax;
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
