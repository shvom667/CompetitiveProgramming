#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CompetitiveProgramming/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif
 
auto solve() {
    ll fans = 1;
    map<ll, ll> mp;
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n),dp(n,0);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(begin(a),end(a));
    dp[n-1]=n-1;
    for (ll i=n-2; i>=0; i--) {
        if (a[i]==a[i+1]) {
            dp[i] = dp[i+1];
        }
        if (a[i]==a[i+1]-1){
            if (a[dp[i+1]] > a[i] + k - 1) {
                dp[i] = dp[i+1]-mp[a[i]+k];
            } else {
                dp[i] = dp[i+1];
            }
        }
        if(a[i]<a[i+1]-1){
            dp[i]=i;
        }
        fans=max(fans,dp[i]-i+1);
    }
    return fans;
}

int main() {
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
