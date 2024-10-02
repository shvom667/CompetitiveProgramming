#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve(ll n, vector<ll> x) {
    if (n != 5) {
        long double l = x[0];
        l += x[1];
        l /= 2;
        long double r = x[n-1];
        r += x[n-2];
        r /= 2;
        return r - l;
    } else {
        long double fans = 0;
        if (true) {
            long double l = x[0] + x[2];
            l /= 2;
            long double r = x[3] + x[4];
            r /= 2;
            fans = max(fans, r - l);
        }
        if (true) {
            long double l = x[0] + x[1];
            l /= 2;
            long double r = x[2] + x[4];
            r /= 2;
            fans = max(fans, r - l);
        }
        return fans;
    }
    return (long double) 0;
}

int main() {
    int t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        ll n;
        cin >> n;
        vector<ll> x(n);
        for (auto&y : x) {
            cin >> y;
        }
        sort(begin(x),end(x));
        auto res = solve(n, x);
        cout << fixed << setprecision(20) << "Case #" << tc << ": " << res << "\n";
    }
}
