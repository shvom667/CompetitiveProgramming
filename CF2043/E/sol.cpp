#include <bits/stdc++.h>
using namespace std;
using ll = int;
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
#define mp make_pair

ll n, m;
bool canSolve(Vec<Vec<bool>> &a, Vec<Vec<bool>> &b) {
    vector<ll> row_1(n, 0);
    vector<ll> col_0(m, 0);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if (b[i][j] == 1) row_1[i]++;
            else col_0[j]++;
        }
    }
    set<pair<int, int>> rows, cols;
    for (ll i = 0; i < n; i++) rows.insert(mp(row_1[i], i));
    for (ll j = 0; j < m; j++) cols.insert(mp(col_0[j], j));

    while (true) {
        if (rows.empty() || cols.empty()) break;
        if (!rows.empty() && (*rows.begin()).first == 0) {
            auto pr = (*rows.begin());
            rows.erase(pr);
            ll idx = pr.second;
            for (ll j = 0; j < m; j++) if (col_0[j])
            {
                cols.erase({col_0[j], j});
                col_0[j]--;
                cols.insert(mp(col_0[j], j));
            }
            continue;
        }
        if (!cols.empty() && (*cols.begin()).first == 0) {
            auto pr = (*cols.begin());
            cols.erase(pr);
            ll idx = pr.second;
            for (ll i = 0; i < n; i++) if (row_1[i])
            {
                rows.erase({row_1[i], i});
                row_1[i]--;
                rows.insert(mp(row_1[i], i));
            }
            continue;
        }
        break;
    }
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++) if (col_0[j] && row_1[i]) 
        {
            if (a[i][j] != b[i][j]) return false;
        }
    return true;
};


auto solve() {
    cin >> n >> m;
    Vec<Vec<ll>> a(n, Vec<ll> (m)), b(n, Vec<ll> (m));
    
    Vec<Vec<bool>> ba(n, Vec<bool> (m)), bb(n, Vec<bool> (m));

    
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }



    for(ll bit = 0; bit < 30; bit++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if ((a[i][j] & (1 << bit))) {
                    ba[i][j] = 1;
                }   else {
                    ba[i][j] = 0;
                }
            }
        }
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if ((b[i][j] & (1 << bit))) {
                    bb[i][j] = 1;
                }   else {
                    bb[i][j] = 0;
                }
            }
        }
        
        if (!canSolve(ba, bb)) {
            cout<<"No\n";return;
        }
    }


    cout<<"Yes\n";return;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
    }
    return 0;
}
