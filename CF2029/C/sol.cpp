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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> b(n, 0), bm;
    ll x= 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] > x) {
            x++;
        }
        if (a[i] < x) {
            x--;
        }
        b[i] = x;
    }
    bm = b;

    for (ll i = 1; i < n; i++) {
        bm[i] = max(bm[i], bm[i - 1]);
    }

    vector<vector<ll>> dp(n, Vec<ll> (2));

    dp[0][0] = 0;
    dp[0][1] = -1e9;

    for (ll i = 1; i < n; i++) {
        dp[i][0] = bm[i - 1];

        ll mv = max(dp[i - 1][1], dp[i - 1][0]);

        if (a[i] > mv) {
            mv++;
        } 
        if (a[i] < mv) {
            mv--;
        }
        dp[i][1] = mv;
    }

    dbg(bm);
    return max(dp[n - 1][0], dp[n - 1][1]);

    // ll M = *max_element(begin(b),end(b)-1);
    // ll p = -1;
    // for (ll i = 0; i < n; i++) {
    //     if (b[i] == M) {
    //         if (p == -1) {
    //             p = i;
    //         }
    //     }
    // }
    // dbg(p, M);

    // if (p == n - 2) {
    //     return M;
    // }


    // ll cnt = 0;

    // for (ll j = p + 1; j < n; j++) {
    //     a[j] -= M;
    //     if (a[j] < cnt) {
    //         cnt--;
    //     }
    //     if (a[j] > cnt) {
    //         cnt++;
    //     }

    //     if (cnt < 0) {
    //         cnt = 0;
    //     }
        
    // }

    // dbg(p, M, cnt);
    // return  min(M + cnt, cnt);
    // return min(M + cnt, n - 1);
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
