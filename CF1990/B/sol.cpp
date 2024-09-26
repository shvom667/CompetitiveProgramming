#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, x, y;
auto solve() {
    vector<ll> fans(n);
    x--;y--;
    for (ll i = y; i <= x; i++) {
        fans[i] = 1;
    }
    for (ll i = y - 1; i >= 0; i--) {
        if ( (y - i) & 1) {
            fans[i] = -1;
        } else {
            fans[i] = 1;
        }
    }
    for (ll i = x + 1; i < n; i++)  {
        if ( (i - x) & 1) {
            fans[i] = -1;
        } else {
            fans[i] = 1;
        }
    }


    return fans;
}

int main() {
    int t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        cin >> n >> x >> y;
        auto res = solve();
        for (auto& v : res)
            cout << v << " ";
        cout << '\n';
    }
}
