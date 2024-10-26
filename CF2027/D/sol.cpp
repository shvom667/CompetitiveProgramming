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

    for (ll i = 0; i < m; i++) {
        dp[i][n - 1] = (b[i] >= a[n - 1] ? m - (i + 1) : INF);
    }
    for (ll j = 0; j < n; j++) {
        dp[m - 1][j] = (b[m - 1] >= smax[j] ? m - (m - 1 + 1) : INF);
    }

    Vec<ll> minv(n, INF);
    for (ll i = n - 1; i >= 0; i--) {
        for (ll j = m - 1; j >= 0; j--) {
            minv[i] = min(minv[i], dp[j][i]);
        }
    }

    for (ll j = n - 2; j >= 0; j--) {
        for (ll i = m - 2; i >= 0; i--) {
            ll k = md[i][j];
            if (k < j) continue;
            ll cur = INF;
            if (k + 1 < n) {
                cur = minv[k + 1];
            } else {
                cur = 0;
            }
            cur += m - (i + 1);
            dp[i][j] = min(dp[i][j] , cur);
            minv[j] = min(minv[j], dp[i][j]);
        }
    }

    ll fans = INF;
    for (ll i = 0; i < m; i++) {
        fans = min(fans, dp[i][0]);
    }
    return (fans >= INF ? -1ll : fans);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
