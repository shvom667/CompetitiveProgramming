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
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll fans = 1e9;
    for (ll s = 0; s < n; s++) {
        ll cur = s;
        for (ll j = s + 1; j < n; j++) {
            if (a[j] > a[s]) {
                cur++;
            }
        }
        fans = min(fans, cur);
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