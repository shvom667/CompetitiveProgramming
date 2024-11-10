#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
const ll INF = 1e18;
auto solve() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> T[2];
    for (ll i = 0; i < n; i++) {
        ll t; cin >> t; t--;
        ll x, y;
        cin >> x >> y;
        T[t].pb({x,y});
    }

    ll l0, r0, l1, r1;
    l0 = INF, r0 = -INF;
    for (ll i = 0; i < T[0].size(); i++) {
        ll num = 0, den = 0;
        num = T[0][i].first + 2 * T[0][i].second - T[0][i].first * T[0][i].first;
        den = 2 * T[0][i].first;
        l0 = min(l0, num / den);


        num = -T[0][i].first + 2 * T[0][i].second + T[0][i].first * T[0][i].first;
        den = 2 * T[0][i].first;

        r0 = max(r0, (num + den - 1) / den);
    }

    dbg(l0, r0);

    l1 = -INF, r1 = INF; 
    for (ll i = 0; i < T[1].size(); i++) {
        ll num = 0, den = 0;
        num = T[1][i].first + 2 * T[1][i].second - T[1][i].first * T[1][i].first;
        den = 2 * T[1][i].first;
        l1 = max(l1, num / den);


        num = -T[1][i].first + 2 * T[1][i].second + T[1][i].first * T[1][i].first;
        den = 2 * T[1][i].first;

        r1 = min(r1, (num + den - 1) / den);
    }

    l1++, r1--;

    dbg(l1, r1);

    ll a, b;

    if (r1 < r0) {
        return -1ll;
    }
    a = l0;
    if (l1 <= l0) {
        a = l1 - l0;
    }
    b = r1 - r0;

    return a * b;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
