#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) solve();
}

void solve() {
    ll n, m;
    cin >> m >> n;
    char g[n][m];
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    ll fans = 0;
    for (ll j = 0; j < m; j++) {
        ll c0 = 0, c1 = 0;
        for (ll i = 0; i < n; i++) {
            if (g[i][j] == '1') c1++;
            if (g[i][j] == '0') c0++;
        }
        ll d = n - c0 - c1;
        if (abs(c0 - c1) > d) {
            fans += (min(c0, c1) + d) * max(c0, c1);
        } else {
            fans += (n - n / 2) * (n / 2);
        }
    }
    cout << fans << '\n';
}