#include <bits/stdc++.h>


using namespace std;

using ll = int;
// ============

ll ask(ll a, ll b) {
    cout << "? " << a << " " << b << endl;
    ll res;
    cin >> res;
    return res;
}

void give(ll val) {
    cout << "! " << val << endl; 
}
   

void solve() {
    ll qc = 0;
    ll l = 1, r = 1000;
    while (l <= r) {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll res = ask(m1, m2);
        if (res == m1 * m2) {
            l = m2 + 1;
        }
        if (res == (m1 + 1) * (m2 + 1)) {
            r = m1;
        }
        if (res == (m1) * (m2 + 1)) {
            l = m2;
        }
        if (r == l) break;
    }
    cout << l << endl;
}

signed main() {

    ll t;
    t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
