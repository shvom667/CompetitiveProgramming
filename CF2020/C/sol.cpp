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
const ll M = 61;
ll B[M], C[M], D[M];
auto solve() {
    ll b, c, d;
    cin >> b >> c >> d;
    ll a = 0;
    bool ok = true;
    for (ll i = 0; i < M; i++) 
    {
        if ((1ll<<i) & b) B[i] = 1;
        else B[i] = 0;
        if ((1ll<<i) & c) C[i] = 0;
        else C[i] = 1;
        if ((1ll<<i) & d) D[i] = 1;
        else D[i] = 0;

        if (D[i] == B[i] || D[i] == C[i]) {
            if (D[i] == B[i]) {
            } else {
                a ^= (1ll<<i);
            }
        } else {
            ok = false;
        }
    }
    
    if (!ok) {
        cout << -1 << '\n';
        return;
    }
    assert( (a|b) - (a&c) - d == 0);
    cout << a << "\n";
}

int main() {
    int T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
    }
}