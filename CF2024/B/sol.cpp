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
    ll n; ll k;
    cin >> n >> k;
    vector<ll> p(n), a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(begin(a),end(a));
    for (ll i = 0; i < n; i++) {
        p[i] = a[i];
        if (i) p[i] += p[i-1];
    }
    ll fans = 1e18;
    for (ll i = n - 1; i >= 0; i--) {
        if (p[i] + (n-1-i)*a[i] >= k) {
            fans = min(fans, k + i);
        }
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
