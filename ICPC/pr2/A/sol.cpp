#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifdef SHIVOM
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
 
auto solve() {
    ll k;
    ll n; cin >> n >> k;
    ll a[n + 1], p[n + 1]; p[0] = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        a[0] = 0;
    }
    sort(a+1,a+n+1);
    for (ll i = 1; i <= n; i++) {
        p[i] = a[i];
        p[i] += p[i - 1];
    }
    ll dp[n + 1]; dp[0] = 0;
    for (ll i = 1; i <= k; i++) {
        dp[i] = p[i];
    }
    for (ll i = k + 1; i <= n; i++) {
        dp[i] = p[i] - p[i - k] + dp[i - k - 1];
    }
    for (ll i = 1; i <= n; i++) {
        cout << dp[i] << " ";   
    }   cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        // auto res = solve();
        // cout << res << "\n";
        solve();
    }
    return 0;
}

