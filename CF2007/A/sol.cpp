#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e5+20;
ll l, r;

auto solve() {
    if (l % 2 == 0) l++;
    if (r % 2 == 0) r--;
    if (l > r) return 0ll;
    return  ((r - l) / 2 + 1)/2;
}

int main() {
    ll t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        cin >> l >> r;
        auto res = solve();
        cout << res << '\n';
    }
    return 0;
}

