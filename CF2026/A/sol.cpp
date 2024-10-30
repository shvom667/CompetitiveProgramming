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
    ll x, y, k;
    cin >> x >> y >> k;
    ll z = min(x,y);
    vector<ll> fans;
    fans.pb(0);
    fans.pb(0);
    fans.pb(z);
    fans.pb(z);

    fans.pb(0);
    fans.pb(z);
    fans.pb(z);
    fans.pb(0);
    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        for (ll i = 0; i < 4; i++) {
            cout << res[i] << " ";
        }cout << "\n";
        for (ll i = 4; i < 8; i++) {
            cout << res[i] << " ";
        }   cout << "\n";
    }
    return 0;
}
