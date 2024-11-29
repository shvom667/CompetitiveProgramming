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
    ll n; cin>> n;
    map<ll, ll> mp;
    while(n--){
        ll x;cin>>x;
        mp[x]++;
    }
    vector<ll> a;
    for(auto&[u,v]:mp){
        // dbg(u,v);
        a.pb(v);
    }
    n = a.size();
    dbg(a);
    const ll INF = 1e10;
    vector<Vec<ll>> dp(n, Vec<ll> (n + 1, INF));

    for (ll i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    for (ll i = 1; i < n; i++) {
        for (ll k = 1; k <= n; k++) {
            dp[i][k] = min(dp[i - 1][k], dp[i][k]);
            dp[i][k] = min(dp[i - 1][k - 1] + 1 + a[i], dp[i][k]);
            if (dp[i][k] <= i+1) {

            } else {
                dp[i][k] = INF;
            }
        }
    }
    ll take=0;
    for (ll i = 0; i <= n; i++) {
        if (dp[n-1][i] < INF) {
            take=i;
        }
    }

    ll res= n-take;
    // res = min(res, (n+1)/2);

    return res;
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
