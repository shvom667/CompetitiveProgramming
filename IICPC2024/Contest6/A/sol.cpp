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
    char g[n][m];
    for(ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    vector<Vec<bool>> ok(n, vector<bool> (m, true));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (i + 1 < n)
            if (g[i][j] != g[i + 1][j]) {
                ok[i][j] = false;
                ok[i + 1][j] = false;
            }
            if (i - 1 >= 0)
            if (g[i][j] != g[i - 1][j] ) {
                ok[i][j] = false;
                ok[i - 1][j] = false;
            }
            if (j + 1 < m)
            if (g[i][j] != g[i][j + 1]) {
                ok[i][j] = false;
                ok[i][j + 1] = false;
            }
            if (j - 1 >= 0)
            if (g[i][j] != g[i][j - 1]) {
                ok[i][j] = false;
                ok[i][j - 1] = false;
            }
        }
    }
    ll fans = 1;
    ll MOD = 1e9 + 7;
    // for (ll i = 0; i < n; i++) {
    //     for (ll j = 0; j < m; j++) {
    //         cout << ok[i][j] << " ";
    //     }   cout << "\n";
    // }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (ok[i][j]) {
                fans *= 2;
                fans %= MOD;
            }
        }
    }
    return fans;
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
