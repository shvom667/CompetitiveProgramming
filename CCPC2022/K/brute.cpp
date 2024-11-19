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
    return make_pair(l, r);
}

auto solve() {
    ll n; cin >> n;
    vector<pair<ll,ll>> T[2];
    for (ll i = 0; i < n; i++) {
        ll t, l, r; cin >> t >> l >> r;
        T[t - 1].pb({l, r});
    }

    auto sum = [&] (ll l, ll r) {
        return r * (r + 1) / 2 - (l - 1) * l / 2;
    };
    auto good = [&] (ll l, ll r) {
        bool ok = true;
        for (auto& [u, v] : T[0]) {
            auto [L, R] = get(u, v);
            if (! (l <= L && r >= R)) ok = false;
        }
        for (auto& [u, v] : T[1]) {
            auto [L, R] = get(u, v);
            if (l <= L && r >= R) ok = false;
        }
        return ok;
    };
    ll cnt = 0;
    for (ll l = 1; l <= 1000; l++) {
        for (ll r = l; r <= 1000; r++) {
            if (good(l, r)) {
                cnt++;
            }
        }
    }

    if (T[1].size() == 0) {
        return -1ll;
    }
    dbg(cnt);
    return (cnt >= 500?-1:cnt);
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
