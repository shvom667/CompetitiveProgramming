#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using f80 = long double;
const f80 eps = 1e-12;

auto solve() {
    ll n;
    cin >> n;
    f80 L = -1, R = 1e18;
    for (ll i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        f80 cl, cr;
        cl = (i + 1);
        cl /= r;
        L = max(L, cl);
        cr = (i + 1);
        cr /= (l == 0 ? eps : l);
        R = min(R, cr);
    }
    if (L <= R) {
        return L;
    } 
    return (f80)-1;
}

int main() {
    int t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        auto res = solve();
        if (res < 0) {
            cout << "Case #" << tc << ": " << -1 << "\n";
            continue;
        }
        cout << fixed << setprecision(8) << "Case #" << tc << ": " << res << "\n";
    }
}
