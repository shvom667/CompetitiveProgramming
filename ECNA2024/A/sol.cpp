#include<bits/stdc++.h>
using namespace std;
using ll= int;
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

const ll N = 1e5 + 20;

ll dp[N];
const ll INF = 1e12;

auto chmin(auto&a, auto b) {
    a = min(a, b);
}

auto bf() {
    dbg(N);
    for (ll i = 1; i < N; i++) dp[i] = INF;

    dp[0] = INF;
    dp[1] = 1;
    for (ll i = 2; i < N; i++) {
        
        for (int j = 1; j < i; j++) {
            chmin(dp[i], dp[j] + dp[i - j]);
        }

        for (ll j = 1; j <= sqrtl(i); j++) {
            if (i % j == 0) {
                chmin(dp[i], dp[j] + dp[i / j]);
            }
        }

        ll k = i;
        ll f, b, sz, p10;
        f = 0, b = 0, sz = 0, p10 = 1;
        while (k > 0) {
            ll r = k % 10;
            k /= 10;
            b = p10 * r + b;
            // dbg(i, k, b);
            if (r) {
                chmin(dp[i], dp[k] + dp[b]);
            }
            p10 *= 10;
        }
    }

    // for (ll i = 1; i <= 20; i++) {
    //     cout << dp[i] << " ";
    // }   cout << "\n";
}

auto solve() {
    bf();
    ll n;
    cin >> n;
    return dp[n];
}

int main() {
	// ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    // cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
