#include<bits/stdc++.h>
using namespace std;
using ll=int;
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
const ll INF = 1e9;
auto solve() {
    
    auto get = [&] (int a, int b) {
        assert(a >= 0 && a < 16);
        assert(b >= 0 && b < 16);
        vector<int> np;
        for (int bit = 0; bit < 3; bit++) {
            int c, d;
            c = a, d = b;
            if (c & (1 << bit)) {
                c ^= (1 << bit);
            }
            if (c & (1 << (bit + 1))) {
                c ^= (1 << (bit + 1));
            }
            if (d & (1 << bit)) {
                d ^= (1 << bit);
            }
            if (d & (1 << (bit + 1))) {
                d ^= (1 << (bit + 1));
            }
            if (c == 0) {
                np.push_back(d);
            }
        }
        return np;
    };
    
    ll n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll> (16, INF));
    vector<ll> a(n + 1, 0);
    ll xtra = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >  4) {
            a[i] = 0;
            xtra++;
        }
        a[i] = (1 << a[i]) - 1;
    }
    for (ll j = 0; j < 16; j++) {
        dp[0][j] = 0;
    }
    for (ll i = 1; i <= n; i++) {
        for (ll pm = 0; pm < 16; pm++) {
            dp[i][a[i]] = min(dp[i][a[i]], dp[i - 1][pm] + (pm == 0 ? 0 : 1));
            dp[i][0] = min(dp[i][0], dp[i - 1][pm] + (pm == 0 ? 0 : 1) + (a[i] == 0 ? 0 : 1));
            auto nmv = get(pm, a[i]);
            if (i == 2 && pm == 3) {
            }
            for (auto& nm: nmv) {
                dp[i][nm] = min(dp[i][nm], dp[i-1][pm] + 1);
            }
        }
    }
    ll fans = dp[n][0];
    for (ll i = 1; i < 16; i++) {
        fans = min(fans, dp[n][i] + 1);
    }
    return fans + xtra;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;

    T = 1;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
        // solve();
    }
    return 0;
}
