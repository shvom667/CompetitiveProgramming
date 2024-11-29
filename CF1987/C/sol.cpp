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
    vector<ll> v(n), a(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll fans = 0;
    a[n - 1] = v[ n - 1];
    for (ll i = n - 2; i >= 0; i--) {
        if (v[i] > v[i + 1]) {
            a[i] = max(v[i], a[i + 1] + 1);
        } else {
            a[i] = 1 + a[i + 1];
        }
    }
    return a[0];
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
