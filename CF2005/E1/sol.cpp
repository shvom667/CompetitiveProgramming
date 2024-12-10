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
    ll l, n, m;
    cin >> l >> n >> m;

    Vec<ll> a(l + 1, 0);
    vector<vector<ll>> g(n + 1, Vec<ll> (m + 1, 0));

    for (ll i = 1; i <= l; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    dbg(a);
    for(ll i=1;i<=n;i++){
        dbg(g[i]);
    }

    Vec<vector<vector<ll>>> f(l + 1, Vec<vector<ll>> (n + 2, Vec<ll> (m + 2, 0)));


    for (ll i = n; i>=1; i--) {
        for (ll j = m; j>= 1;j--) {
            f[l][i][j] = (g[i][j] == a[l] ? 1 : 0);
        }
    }

    vector<Vec<ll>> ff; // ff[x][y] -> is there a winning state in the submatrix?
    auto compute_prefix = [&] (ll x) {
        ff = f[x];
        for (ll i=1;i<=n;i++){
            dbg(ff[i]);
        }
        for (ll j = 0; j <= m + 1; j++) {
            ff[n+1][j] = 0;
        }
        for (ll i = 0; i <= n + 1; i++) {
            ff[i][m+1] = 0;
        }
        for (ll i = n; i >= 1; i--) {
            for (ll j = m; j>= 1; j--) {
                if (ff[i][j] == 1) continue;
                if (ff[i + 1][j] == 1) {
                    ff[i][j] = 1;
                    continue;
                }
                if (ff[i][j + 1] == 1) {
                    ff[i][j] = 1;
                    continue;
                }
            }
        }
    };

    compute_prefix(l);

    for(ll i=1;i<=n;i++){
        dbg(ff[i]);
    }

    for (ll ind = l-1; ind >= 1; ind--) {
        for (ll i = n; i>=1; i--) {
            for (ll j = m; j>= 1;j--) {
                if (g[i][j] != a[ind]) {
                    f[ind][i][j] = 0;
                    continue;
                }
                if (ff[i+1][j+1]) {
                    f[ind][i][j] = 0;
                }else{
                    f[ind][i][j] = 1;
                }
            }
        }

        compute_prefix(ind);
    }

    for(ll i=1;i<=n;i++){
        dbg(f[2][i]);
    }

    if (ff[1][1] == 1) {
        return "T";
    } 
    return "N";

    return "0";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
