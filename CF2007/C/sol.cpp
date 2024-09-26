#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e5+20;
ll n, a, b;
ll x[N];

auto solve() {
    ll d = __gcd(a,b);
    if (d > 0)
        for (ll i = 1; i <= n; i++) x[i] %= d;
    else d = a;
    sort(x+1, x+n+1);
    ll fans = x[n]-x[1];
    for(ll i = 1; i < n; i++) fans = min(fans, d + x[i] - x[i + 1]);
    return fans;
}

int main() {
    ll t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        cin >> n >> a >> b;
        for (ll i = 1; i <= n; i++) {
            cin >> x[i];
        }
        auto res = solve();
        cout << res << '\n';
    }
    return 0;
}
