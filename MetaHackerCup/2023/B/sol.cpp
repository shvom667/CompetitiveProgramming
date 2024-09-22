#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

ll solve(ll l, ll r, ll a, ll b) {
    if (l > r) {
        return 1ll;
    }
    return 0ll;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        ll l, r, a, b;
        cin >> l >> r >> a >> b;
        string ans = solve(l, r, a, b) > 0 ? "YES" : "NO";
        cout << "Case #" << tc << ": " << ans << "\n";
    }
}
