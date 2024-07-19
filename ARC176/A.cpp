#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const string nl = "\n";
using pl = pair<ll, ll>;
#define pb push_back 
template <typename T>
using Vec = vector<T>;
ll n, m;
set<ll> ud;
Vec<pl> fans;
ll md(ll x, ll y) {
    return ((y - x) % n + n) % n;
}
void gd(ll x) {
    ll s, e;
    s = 0, e = x;
    for (ll i = 0; i < n; i++)
        fans.pb({(s+i)%n, (e+i)%n});
}

void solve() {
    cin >> n >> m;

    for (ll j = 0; j < m; j++) {
        ll x, y;
        cin >> x >> y;
        ud.insert(md(x, y));
    }
    for (ll i = 0; i < n; i++) {
        if (ud.size() < m)
            ud.insert(i);
    }
    for (auto& v : ud)
        gd(v);
    cout << n*m << '\n';
    for (auto& [x, y] : fans)
        cout << x + 1 << " " << y + 1 << '\n';
}

signed main() {

    ll t;
    t = 1;
    while (t--) {
        solve();
    }
}

