#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    ll n, k;
    cin >> n >> k;
    ll cnt = 0;
    if (k == 1) {
        cout << n << "\n";
        return;
    }
    ll m = (log(2e9) / log(k)) + 1;
    for (ll p = m; p  >= 0; p--) {
        ll po = pow(k, p);
        while (n >= po) {
            
            cnt += n / po;
            n %= po;
        }
    }
    cout << cnt << "\n";
}

int main() {
    int T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
    }
}
