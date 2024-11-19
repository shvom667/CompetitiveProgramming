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
ll ub(ll x, ll y) {
    return (x + y - 1) / y;
}
ll lb(ll x, ll y) {
    return x / y;
}
pair<ll, ll> get(ll k, ll x) {
    ll l, r;
    l = lb(2 * x + k - k * k, 2 * k);
    r = ub(2 * x - k + k * k, 2 * k);
    l = max(l, 0ll);
    r = max(r, 0ll);
    return make_pair(l, r);
}
auto solve() {
    ll n; cin >> n;
    vector<pair<ll, ll>> T[2];
    for (ll i = 0; i < n; i++) {
        ll t; cin >> t;
        ll k, x; cin >> k >> x;
        T[t - 1].pb({k,x});
    }

    for(ll i = 0; i < 2; i++) {
        for (ll j = 0; j < T[i].size(); j++) {
            T[i][j] = get(T[i][j].first, T[i][j].second);
        }
    }
    ll lmin = 1e18, rmax = -1e18;
    dbg(T[0]);
    dbg(T[1]);
    for (ll j = 0; j < T[0].size(); j++) {
        lmin = min(lmin, T[0][j].first);
        rmax = max(rmax, T[0][j].second);
    }
    // lmin = max(lmin, 0ll);
    // rmax = max(rmax, 0ll);


    sort(begin(T[1]), end(T[1]), [&] (auto x, auto y) {
        return x.second < y.second;
    });
    ll lft = 0;
    ll fans = 0;
    bool ok = false;
    for (auto& [l, r]: T[1]) {
        if (l < lft) continue;
        // if (r < rmax) {
        //     ok = true;
        //     fans=0;
        //     break;
        // }
        fans += (min(l, lmin) - lft) * (max(r,rmax) - rmax);
        lft = l;
        if (lft >= lmin) {
            ok = true;
            break;
        }
    }
    dbg(ok , fans);
    if (ok) {
        return fans;
    } else {
        return -1ll;
        // cout << -1 << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
