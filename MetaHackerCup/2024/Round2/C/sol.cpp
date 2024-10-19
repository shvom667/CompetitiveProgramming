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
#define ALL(x) begin(x), end(x)
auto solve() {
    ll r, c, K;
    cin >> r >> c >> K;
    vector<vector<ll>> g(r, vector<ll> (c, 0));
    vector<ll> row[r*c][r];
    vector<ll> col[r*c][c];
    for (ll i = 0; i < r; i++) {
        for (ll j = 0; j < c; j++) {
            cin >> g[i][j];
            g[i][j]--;
            row[g[i][j]][i].push_back(j);
        }
    }
    for (ll j = 0; j < c; j++) {
        for (ll i = 0; i < r; i++) {
            col[g[i][j]][j].push_back(i);
        }
    }
    vector<ll> fans(r+c, 0);
    for (ll i = 0; i < r; i++) {
        for (ll j = 0; j < c; j++) {
            for (ll k = 1; i - k >= 0; k++) {
                ll l, rr;
                l = j - k + 1, rr = j + k - 1;
                l = max(0ll, l);
                rr = min(rr, c-1);
                ll len = rr - l + 1;
                ll eq = upper_bound(ALL(row[g[i][j]][i-k]), rr+1)-upper_bound(ALL(row[g[i][j]][i-k]), l);
                fans[k] += len - eq;
            }
            for (ll k = 1; i + k < r; k++) {
                ll l, rr;
                l = j - k + 1, rr = j + k - 1;
                l = max(0ll, l);
                rr = min(rr, c-1);
                ll len = rr - l + 1;
                ll eq = upper_bound(ALL(row[g[i][j]][i+k]), rr+1)-upper_bound(ALL(row[g[i][j]][i+k]), l);
                fans[k] += len - eq;
            }
        }
    }
    dbg(fans);
    for (ll i = 0; i < r; i++) {
        for (ll j = 0; j < c; j++) {
            for (ll k = 1; j - k >= 0; k++) {
                ll l, rr;
                l = i - k + 1, rr = i + k - 1;
                l = max(0ll, l);
                rr = min(rr, r-1);
                ll len = rr - l + 1;
                ll eq = upper_bound(ALL(col[g[i][j]][j-k]), rr+1)-upper_bound(ALL(col[g[i][j]][j-k]), l);
                fans[k] += len - eq;
            }
            for (ll k = 1; j + k < c; k++) {
                ll l, rr;
                l = j - k + 1, rr = j + k - 1;
                l = max(0ll, l);
                rr = min(rr, r-1);
                ll len = rr - l + 1;
                ll eq = upper_bound(ALL(col[g[i][j]][j+k]), rr+1)-upper_bound(ALL(col[g[i][j]][j+k]), l);
                fans[k] += len - eq;
            }
        }
    }
    dbg(fans);
    for (ll i = 0; i < r; i++) {
        for (ll j = 0; j < c; j++) {
            for (ll k = 1; k <= max(r,c); k++) {
                if (i - k >= 0 && j - k >= 0) {
                    if (g[i][j] != g[i-k][j-k]) {
                        fans[k]++;
                    }
                }
                if (i - k >= 0 && j + k < c) {
                    if (g[i][j] != g[i-k][j+k]) {
                        fans[k]++;
                    }
                }
                if (i + k < r && j - k >= 0) {
                    if (g[i][j] != g[i+k][j-k]) {
                        fans[k]++;
                    }
                }
                if (i + k < r && j + k < c) {
                    if (g[i][j] != g[i + k][j + k]) {
                        fans[k]++;
                    }
                }
            }
        }
    }
    dbg(fans);
    ll sum = 0;
    for (ll i = 1; i <= max(r,c); i++) {
        sum += fans[i];
        if (sum >= K) {
            return i;
        }
    }  
    return -1ll;
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
