#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;


auto solve() {
    ll n;
    cin >> n;
    ll a[n];
    ll m = 1e9;
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n - 1; i++) {
        m = min(m, max(a[i], a[i+1]));
    }
    return m - 1;
}

int main() {
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
