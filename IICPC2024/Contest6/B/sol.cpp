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
 
auto solve() {
    ll n, m;
    cin >> n >> m;
    ll g[n][m], ans[n][m];
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            char c;
            cin >> c;
            g[i][j] = (c == 'B' ? 1 : 0);
        }
    }

    // for (ll i = 0; i < n; i++) {
    //     for (ll j = 0; j < m; j++) {
    //         cout << g[i][j] << " \n"[j == m - 1];
    //     }
    // }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0;  j < m; j++) {
            ll cnt = 0;
            if (i + 1 < n) cnt++;
            if (j + 1 < m) cnt++;
            dbg(i, j, cnt);
            if (cnt&1) {
                if (g[i][j] == 1) {
                    // do type 2
                    ans[i][j] = 2;
                    g[i][j] ^= 0;
                    if (i)
                    g[i-1][j] ^= 1;
                    if (i + 1 < n)
                    g[i + 1][j] ^= 1;
                    if (j + 1 < m)
                    g[i][j + 1] ^= 1;
                    if (j)
                    g[i][j - 1] ^= 1;
                }
                else  {
                    // do type 3
                    ans[i][j] = 3;
                    g[i][j] ^= 1;
                    if (i)
                    g[i-1][j] ^= 1;
                    if (i + 1 < n)
                    g[i + 1][j] ^= 1;
                    if (j + 1 < m)
                    g[i][j + 1] ^= 1;
                    if (j)
                    g[i][j - 1] ^= 1;
                }
            }
            else {
                if (g[i][j] == 1) {
                    dbg(i, j);
                    // do type 3
                    ans[i][j] = 3;
                    g[i][j] ^= 1;
                    if (i)
                    g[i-1][j] ^= 1;
                    if (i + 1 < n)
                    g[i + 1][j] ^= 1;
                    if (j + 1 < m)
                    g[i][j + 1] ^= 1;
                    if (j)
                    g[i][j - 1] ^= 1;
                }
                else {
                    // do type 2
                    ans[i][j] = 2;
                    g[i][j] ^= 0;
                    if (i)
                    g[i-1][j] ^= 1;
                    if (i + 1 < n)
                    g[i + 1][j] ^= 1;
                    if (j + 1 < m)
                    g[i][j + 1] ^= 1;
                    if (j)
                    g[i][j - 1] ^= 1;
                }
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            assert(g[i][j] == 0);
        }
    }

    cout << 1 << "\n";
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cout << ans[i][j];
        }cout<<'\n';
    }

}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        // auto res = solve();
        // cout << res << "\n";
        solve();
    }
    return 0;
}
