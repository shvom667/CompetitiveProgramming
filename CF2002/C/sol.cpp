#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;


#ifndef ONLINE_JUDGE
    #include "../../DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif

auto solve() {
    ll n;
    cin >> n;
    vector<ll> x(n + 2), y(n + 2);

    for (ll i = 0; i < n + 2; i++) {
        cin >> x[i] >> y[i];
    }
    auto get = [&] (ll i , ll j) {
        return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    };
    ll d = 3e18;
    for (ll i = 0; i < n; i++) {
        d = min(d, get(i, n + 1));
    }
    
    if (d > get(n, n + 1)) {
        cout << "Yes\n"; 
    } else {
        cout << "No\n";
    }

}

int main() {
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        // auto res = solve();
        // cout << res << "\n";
        solve();
    }
    return 0;
}
