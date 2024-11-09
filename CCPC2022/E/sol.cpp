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
 
const ll N = 1e6 + 20;

ll dp[N];

auto give(ll g) {
    cout <<  "Python 3." << g << " will be faster than C++\n";
}

auto solve() {
    ll n, k;
    cin >> n >> k;

    ll g = -1;
    for (ll i = 1; i <= n; i++) {
        cin >> dp[i];
        if (g == -1 && dp[i] < k) {
            g = i;
        }
    }
    if (g != -1) {
        give(g);
    }
    if (dp[n] >= dp[n - 1]) {
        cout << "Python will never be faster than C++\n";
    }
    for (ll i = n + 1; i < N; i++) {
        dp[i] = max(0ll, 2 * dp[i - 1] - dp[i - 2]);
        if (dp[i] < k) {
            give(i);
            return;
        }
    }

}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
        // cout << res << "\n";
    }
    return 0;
}
