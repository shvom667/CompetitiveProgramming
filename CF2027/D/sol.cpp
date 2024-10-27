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
const ll INF = 1e11;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m), p(n), smax(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = a[i];
        smax[i] = a[i];
        if (i) p[i] += p[i - 1];
    }
    for (ll i = n - 2; i >= 0; i--) {
        smax[i] = max(smax[i], smax[i + 1]);
    }
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
    }

    if (smax[0] > b[0]) {
        return -1ll;
    }

    vector<vector<ll>> md(m, vector<ll> (n));
    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
            auto it = upper_bound(begin(p), end(p), b[i] + (j > 0 ? p[j - 1] : 0ll)) - begin(p);
            md[i][j] = it - 1;
            if (md[i][j] < j) {
                md[i][j] = -1;
            }
        }
    }
    

    vector<vector<ll>> dp(m, vector<ll> (n, INF));

    for (ll i = m - 1; i >= 0; i--) {
        dp[i][n - 1] = (b[i] >= a[n - 1] ? m - (i + 1) : INF);
        if (i + 1 < m)
            dp[i][n - 1] = min(dp[i][n-1], dp[i + 1][n - 1]);
    }
    for (ll j = 0; j < n; j++) {
        dp[m - 1][j] = (b[m - 1] >= smax[j] ? m - (m - 1 + 1) : INF);
    }

    Vec<ll> minv(n, INF);
    for (ll i = n - 1; i >= 0; i--) {
        for (ll j = m - 1; j >= m - 1; j--) {
            minv[i] = min(minv[i], dp[j][i]);
        }
    }

    // dbg(md[3][0]);

    dbg(minv);
    dbg("hello");
        for (ll i = m - 2; i >= 0; i--) {
    for (ll j = n - 1; j >= 0; j--) {
            ll k = md[i][j];
            if (k < j) continue;
            ll cur = INF;
            if (k + 1 < n) {
                cur = minv[k + 1];
            } else {
                cur = 0;
            }
            cur += m - (i + 1);
            if (i == 0 && j == 0){
                dbg(i, j, minv);
            }
            dp[i][j] = min(dp[i][j] , cur);
            dp[i][j] = min(dp[i][j], dp[i + 1][j]);
            minv[j] = min(minv[j], dp[i][j]);
            if (i == 0 && j == 1 ) {
                dbg(i, j, dp[i][j], minv);
            }
            dbg(j, i, minv);
        }
        for (ll j = 0; j < n; j++) {
            minv[j] = min(minv[j], dp[i][j]);
        }
    }
    dbg(md[1][0]);
    ll fans = INF;
    for (ll i = 0; i < m; i++) {
        fans = min(fans, dp[i][0]);
    }
    // for (ll i = 0; i < m; i++) {
    //     for (ll j = 0; j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }   cout << "\n";
    // }
    return (fans >= INF ? -1ll : fans);

}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;   
    T = 1;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
