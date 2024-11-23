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
    ll a[4];
    for (ll i = 0; i < 4; i++) cin >> a[i];
    sort(a, a + 4);
    ll fans = 0;
    for (ll j = 0; j < 3; j++) {
        vector<ll> x;
        for (ll k = 0; k < 3; k++) {
            if (k != j)
                x.pb(a[k]);
        }
        fans = a[j] * (min(x[0], x[1]));
    }

    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
