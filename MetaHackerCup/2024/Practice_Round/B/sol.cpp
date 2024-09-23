#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using f80 = long double;
auto solve(ll N, ll P) {
    f80 fans = 0;
    f80 n = N;
    f80 p = P;
    f80 H = 100;
    f80 a, b;
    a = (n-1)/n;
    b = (1/n);

    fans = pow(p, a) * pow(H, b) - p;
    
    return fans;
}

int main() {
    int t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        ll n, p;
        cin >> n >> p;
        auto res = solve(n, p);
        cout << fixed << setprecision(30) << "Case #" << tc << ": " << res << "\n";
    }
}
