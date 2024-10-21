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
/*
This is with assumption c[i] <= 2 * k - 1
And it fails
*/
const ll INF=1e18;
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= k;
    }
    ll m = 2;
    vector<vector<ll>> dp(n, vector<ll> (m, INF));
    vector<vector<ll>> pi(n, vector<ll> (m, INF));


    dp[0][0] = a[0];
    pi[0][0] = 0;
    dp[0][1] = a[0] + k;
    pi[0][1] = 1;

    for (ll i = 1; i < n; i++) {
      ll val1, val2;
      val1 = dp[i - 1][1] + (a[i] >= a[i-1] ? a[i] - a[i-1] : k + a[i] - a[i - 1]);
      val2 = dp[i - 1][0] + (a[i] >= a[i-1] ? a[i] - a[i-1] : k + a[i] - a[i - 1]);
      if (val1 < val2) {
        dp[i][1] = val1;
        pi[i][1] = pi[i - 1][1] + (a[i] < a[i - 1]);
      } else {
        dp[i][1] = val2;
        pi[i][1] = pi[i - 1][0] + (a[i] < a[i - 1]);
      }
      if (i == 2) {
        dbg(pi[i][1]);
        dbg(pi[i-1][1]);
        dbg(pi[i-1][0]);
      }


      //dp[i][1] = min(dp[i-1][1], dp[i-1][0]) + (a[i] >= a[i-1] ? a[i] - a[i-1] : k + a[i] - a[i - 1]);
      //dp[i][0] = dp[i - 1][1];
      //if (a[i] < a[i - 1])
      //  dp[i][0] =  min(dp[i][0], dp[i - 1][0]);


      ll val3, val4;
      val3 = val4 = INF;

      if (a[i - 1] >= a[i]) {
        val3 = dp[i - 1][0];
        val4 = dp[i - 1][1];
      } else { // a[i - 1] < a[i]
        if (pi[i - 1][0] > 0)  {
          val3 = dp[i - 1][0];
        }
        if (pi[i - 1][1] > 0)
          val4 = dp[i - 1][1];
      }
    
      if (val3 <= val4) {
        dp[i][0] = val3;  
        pi[i][0] = pi[i-1][0] - (a[i - 1] < a[i]);
      } else {
        dp[i][0] = val4;
        pi[i][0] = pi[i-1][1] - (a[i - 1] < a[i]);
      }

    }
    for (ll i = 0; i < n; i++) {
      cout << dp[i][0] << " " << dp[i][1] << " " << pi[i][0] << " "  << pi[i][1] << "\n";
    }

    return min(dp[n-1][0], dp[n-1][1]);
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
