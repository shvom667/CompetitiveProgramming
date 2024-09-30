#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto sqrt(ll x) {
    ll l = 1, r = 1.5e9;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        bool ok = mid * mid <= x;
        if (ok) {
            l = mid + 1;
        } else {
            r = mid -1 ;
        }
    }
    return r;
}

auto solve() {
    ll n;
    cin >> n;
    ll l = 1, r = 2e18;
    while (l <= r) {
        bool ok = false;
        ll mid = l + (r - l) / 2;
        ok = mid - ((ll)sqrt(mid)) >= n;
        if (ok) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l  << "\n";
}

int main() {
    int T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
    }
}