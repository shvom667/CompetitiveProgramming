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
const ll INF = 1e9 + 16;
const ll nax = 1e6 + 20;
ll dp[nax];
ll best_d[nax];
auto solve() {

    for (ll i = 0; i < nax; i++) {
        best_d[i] = INF;
    }

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n), c(m), d(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }



    for (ll i = 0; i < n; i++) {
        cin >> b[i];
        d[i] = a[i] - b[i];
        best_d[a[i]] = min(best_d[a[i]], d[i]);
    }

    for (ll i = 1; i < nax; i++) {
        best_d[i] = min(best_d[i], best_d[i - 1]);
    }



    for (ll i = 0; i < m; i++) {
        cin >> c[i];
    }

    dp[0] = 0;
    for (ll i = 1; i < nax; i++) {
        if (i - best_d[i] >= 0)
            dp[i] = dp[i - best_d[i]] + 1;
        else 
            dp[i] = 0;
    }
    
    // for (ll i = 1; i <= 10; i++) {
    //     cout << dp[i] << " ";
    // }   cout << '\n';
    
    dbg(d);

    ll fans = 0;
    dbg(best_d[nax-1]);
    for (ll i = 0; i < m; i++) {
        if (c[i] < nax) continue;
        ll k = (c[i] - (nax -1) + best_d[nax-1] - 1) / best_d[nax-1];
        fans += k;
        c[i] = c[i] - k * best_d[nax - 1];
    }

    for (ll i = 0; i < m; i++) {
        fans += dp[c[i]]; 
    }

    return fans * 2;
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
