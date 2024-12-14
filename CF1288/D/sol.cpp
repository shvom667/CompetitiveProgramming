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
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> g(n, vector<ll> (m, 0));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    ll ga = -1, gb = -1;

    auto cond = [&](ll mid) {
        vector<ll> mask(n, 0);
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (g[i][j] >= mid) {
                    mask[i] ^= (1ll << j);
                }
            }
        }
        vector<bool> present(1<<m, false);
        vector<ll> par_cmp(1<<m, -1);
        present[0] = true;
        for (ll i = 0; i < (1ll << m); i++) {
            for (ll j = 0; j < n; j++) {
                if ((mask[j] & i) == i) {
                    present[i] = true;
                    par_cmp[i] = j;
                    break;
                }
            }
        }

        for (ll i = 0; i < n; i++) {

            ll cmp = 0;
            for (ll j = 0; j < m; j++) {
                if (mask[i] & (1ll << j)) {

                } else {
                    cmp ^= (1ll << j);
                }
            }
            if (present[cmp]) {
                ga = i;
                gb = par_cmp[cmp];
                return true;
            }
        }
        ga = gb = 0;
        return false;
    };
    ll L, R;
    L = 0, R = 1e9+1;
    while (L <= R) {
        ll mid = L + (R - L) /  2;
        if (cond(mid)) {
            L = mid + 1;
        }else {
            R = mid - 1;
        }
    }

    cond(R);

    cout << ga + 1 << " " << gb + 1 << '\n';
    return R;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
