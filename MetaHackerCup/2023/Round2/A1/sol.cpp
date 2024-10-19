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
    vector<vector<char>> g(n, vector<char> (m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    auto check = [] (vector<vector<char>> g, ll p, ll q, ll n, ll m) {
        g[p][q] = 'B';
        dbg(g);
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (g[i][j] == 'W') {
                    bool ok1, ok2, ok3, ok4;
                    ok1 = ok2 = ok3 = ok4 = false;
                    for (ll x = 0; x < i; x++) {
                        if (g[x][j]=='B') ok1=true;
                    }
                    for (ll x = i + 1; x < n; x++){
                        if (g[x][j] == 'B') ok2=true;
                    }
                    for (ll y = 0; y<j; y++) {
                        if (g[i][y] == 'B') ok3 = true;
                    }
                    for (ll y = j + 1;  y < m; y++) {
                        if (g[i][y] == 'B') ok4 = true;
                    }
                    if (p == 1 && q == 2 && i == 1 && j == 2) {
                        dbg(ok1, ok2, ok3, ok4);
                    }
                    if (ok1 && ok2 && ok3 && ok4) {
                        return true;
                    }
                }
            }
        }
        return false;
    };
    string res = "NO";

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                if (check(g,i,j, n, m))
                    res = "YES";
            }
        }

    return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << "Case #" << tc << ": " << res << "\n";
    }
    return 0;
}
