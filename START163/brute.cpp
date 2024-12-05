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
int ub(int a, int b) {
    if (a % b == 0) return (a / b);
    bool positive = !((a < 0) ^ (b < 0));
    return a / b + positive;
}
int lb(int a, int b) {
    if (a % b == 0) return (a / b);
    bool negative = (a < 0) ^ (b < 0);
    return a / b - negative;
}
auto solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(ll mask = 0; mask < (1ll << n); mask++) {
        ll cur = 0;
        for (ll bit = 0; bit < n; bit++) {
            if (mask & (1ll << bit)) {
                cur += ub(a[bit], k);
            } else {
                cur += lb(a[bit], k);
            }
        }
        if (cur == 0) {
            dbg(mask);
            return "YES";
        }
    }
    return "NO";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    // cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
