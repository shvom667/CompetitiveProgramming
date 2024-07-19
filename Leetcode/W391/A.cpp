#include <bits/stdc++.h>
using ll = long long;
using namespace std;
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& a) {
      ll n = a.size();
      ll fans = 0;
      vector<ll> dp(n);
      dp[0] = 1;
      for (ll i = 1; i < n; i++) {
        dp[i] = 1;
        if ((a[i]^a[i-1]) == 1) {
          dp[i] += dp[i-1];
        }
      }
      fans = accumulate(begin(a), end(a), 0ll);
      return fans;
    }
};
