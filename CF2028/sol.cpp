#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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
const ll INF = 1e18;
auto solve() {
    ll n;
    cin >> n;

    ll a[3][n + 1];

    for (ll i = 0; i < 3; i++)
        for (ll j = 1; j <= n; j++)
            cin >> a[i][j];
    
    bool dp[3][n + 1];

    for (ll j = 0; j < 3; j++)
        for (ll i = 1; i <= n; i++) {
            dp[j][i] = false;
        }

    dp[0][n] = dp[1][n] = dp[2][n] = true;
    ll fc, fv, t;
    fv = INF;
    for (ll i = 0; i < 3; i++) {
        fv = min(fv, a[i][n]);
        if (fv == a[i][n]) {
            fc = n;
            t = i;
        }
    }
    dbg(fv);

    vector<pair<ll, ll>> fans(n + 1, {-1, -1});
    ll b[3];

    for (ll i = 0; i < 3; i++) {
        b[i] = n;
    }

    for (ll i = n - 1; i >= 1; i--) {
        bool ok = false;
        for (ll j = 0; j < 3; j++) {
            if (a[j][i] > a[j][b[j]]) {
                ok = true;
                dp[j][i] = true;
            }
        }
        dbg(i, ok);
        if (ok) {
            ll ct = 0;
            for (ll j = 0; j < 3; j++) {
                if (a[j][b[j]] < a[j][i]) {
                    fans[i] = {b[j], j};
                }
            }

            for (ll j = 0; j < 3; j++) 
            {
                fv = min(fv, a[j][i]);
                if (fv == a[j][i]) {
                    fc = i;
                    t = j;
                }
            }

            for (ll j = 0; j < 3; j++) {
                if (i == 2 && j == 0) {
                    dbg(a[j][i], a[j][b[j]], i, b[j], j);
                }
                b[j] = (a[j][i]  < a[j][b[j]] ? i : b[j]);
            }
        }
        dbg(i, fv, fc);
        
    }
    bool ok = false;
    for (ll j = 0; j < 3; j++) {
        if (dp[j][1]) {
            ok = true;
        }
    }
    
    if (!ok) {
        cout << "NO\n";
        return;
    }

    //     for (ll i = 1; i <= n; i++) {
    // for (ll j = 0; j < 3; j++) {
    //         cout << dp[j][i] << " ";    
    //     }   cout << "\n";
    // }

    cout << "YES\n";
    dbg(fans);
    ll s = 1;
    ll cnt = 0;
    vector<char>f1;
    vector<ll> f2;
    while (s != n) {
        // dbg(cnt);
        cnt++;
        f1.pb("qkj"[fans[s].second]) ;
        f2.pb(fans[s].first);
        s = fans[s].first;
    }
    cout << cnt << "\n";
    for (ll i = 0; i < cnt; i++) {
        cout << f1[i] << "  " << f2[i] << "\n";
    }

}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
        // auto res = solve();
        // cout << res << "\n";
    }
    return 0;
}
