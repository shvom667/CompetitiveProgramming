#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
#define ALL(x) begin(x), end(x)
long long solve() {
    ll r, c;
    long long K;
    cin >> r >> c >> K;
    vector<vector<ll>> g(r, vector<ll> (c, 0));
    
    // cout << r << " " << c << " " <<  K << "\n";


    for (ll i = 0; i < r; i++) {
        for (ll j = 0; j < c; j++) {
            cin >> g[i][j];
            // if (i == 0 && j == 0) {
            //     dbg(g[0][0]);
            // }
            g[i][j]--;
        }
    }
    

    vector<ll> fans(r + c + 1, 0);
    

    for (ll id = 0; id < r; id++) {
        dbg(id);
        vector<ll> cur_row[r*c];
        
        for (ll j = 0; j < c; j++) {
            cur_row[g[id][j]].push_back(j);
        } 
        

        for (ll i = id + 1; i < r; i++) {
            ll k = i - id;
            for (ll j = 0; j < c; j++) {
                ll l, rr;
                l = j - k + 1, rr = j + k - 1;
                l = max(0, l);
                rr = min(rr, c-1);
                ll len = rr - l + 1;
                if (len > 0) {
                    ll eq = upper_bound(ALL(cur_row[g[i][j]]), rr)-lower_bound(ALL(cur_row[g[i][j]]), l);
                    fans[k] += len - eq;
                }
            }
        }
        for (ll i = id - 1; i >= 0; i--) {
            ll k = id - i;
            for (ll j = 0; j < c; j++) {
                ll l, rr;
                l = j - k + 1, rr = j + k - 1;
                l = max(0, l);
                rr = min(rr, c-1);
                ll len = rr - l + 1;
                if (len > 0) {
                    ll eq = upper_bound(ALL(cur_row[g[i][j]]), rr)-lower_bound(ALL(cur_row[g[i][j]]), l);
                    fans[k] += len - eq;
                }
            }
        }
    }
    


    for (ll  jd = 0; jd < c; jd++) {
        // vector<vector<ll>> cur_col(r * c);
        vector<ll> cur_col[r*c];
        dbg(jd);

        for (ll i = 0; i < r; i++) {
            cur_col[g[i][jd]].push_back(i);
        }
        for (ll j = jd + 1; j < c; j++) {
            ll k = j - jd;
            for (ll i = 0; i < r; i++) {
                ll l, rr;
                l = i - k + 1, rr = i + k - 1;
                l = max(0, l);
                rr = min(rr, r-1);
                ll len = rr - l + 1;
                if (len > 0) {
                    ll eq = upper_bound(ALL(cur_col[g[i][j]]), rr)-lower_bound(ALL(cur_col[g[i][j]]), l);
                    fans[k] += len - eq;
                }

            }
        }
        for (ll j = jd - 1; j >= 0; j--) {
            ll k = jd - j;
            for (ll i = 0; i < r; i++) {
                ll l, rr;
                l = i - k + 1, rr = i + k - 1;
                l = max(0, l);
                rr = min(rr, r-1);
                ll len = rr - l + 1;
                if (len > 0) {
                    ll eq = upper_bound(ALL(cur_col[g[i][j]]), rr)-lower_bound(ALL(cur_col[g[i][j]]), l);
                    
                    fans[k] += len - eq;
                }

            }
        }
    }

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
    
    long long sum = 0;
    for (ll i = 1; i <= r + c; i++) {
        sum += fans[i];
        if (sum >= K) {
            return i;
        }
    }  
    return -1;
}

signed main() {
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << "Case #" << tc << ": " << res << "\n";
    }
    return 0;
}
