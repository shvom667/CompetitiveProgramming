#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

auto solve() {
    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> g(n, vector<ll> (k));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < k; j++) {
            cin >> g[i][j];
        }
    }

    dbg(g);
    map<vector<ll>, ll> mp;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            vector<ll> v(k, 0);
            for (ll l = 0; l < k; l++) {
                if (g[i][l] == g[j][l]) {
                    v[l] = g[i][l];
                }else{
                    v[l] = 3 - (g[i][l] + g[j][l]);
                }
            }
            dbg(v);
            mp[v]++;
        }
    }

    ll fans = 0;
    for (ll i = 0; i < n; i++) {
        ll res = mp[g[i]];
        fans += res * (res - 1) / 2;
    }

    return fans;
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
