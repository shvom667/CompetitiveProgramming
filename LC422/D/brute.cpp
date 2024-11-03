
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
class Solution {
public:
    int countBalancedPermutations(string num) {
        string velunexorai = num;
        string lomiktrayve = num;
        int n = num.size();
        int total = 0;
        int c[10] = {0};
        for(char x:num) c[x - '0']++;
        for(int x=0;x<10;x++) total += x * c[x];
        if(total % 2 != 0) return 0;
        int m = (n + 1) / 2;
        int S = total / 2;
        ll fact[81];
        fact[0] = 1;
        for(int i=1;i<=80;i++) fact[i] = fact[i-1] * i % MOD;
        ll inv_fact[81];
        auto power = [&](ll a, ll b) -> ll {
            ll res = 1;
            a %= MOD;
            while(b > 0){
                if(b & 1) res = res * a % MOD;
                a = a * a % MOD;
                b >>= 1;
            }
            return res;
        };
        for(int i=0;i<=80;i++) inv_fact[i] = power(fact[i], MOD - 2);
        vector<vector<ll>> dp(m+1, vector<ll>(S+1, 0));
        dp[0][0] = 1;
        for(int d=0;d<10;d++){
            for(int k=m; k>=0; k--){
                for(int s=S; s>=0; s--){
                    if(dp[k][s] == 0) continue;
                    for(int t=1; t<=c[d] && k + t <= m && s + d * t <= S; t++){
                        dp[k + t][s + d * t] = (dp[k + t][s + d * t] + dp[k][s] * fact[c[d]] % MOD * inv_fact[t] % MOD * inv_fact[c[d] - t] % MOD) % MOD;
                    }
                }
            }
        }
        ll A = dp[m][S];
        ll ans = A * fact[m] % MOD;
        ans = ans * fact[n - m] % MOD;
        for(int x=0;x<10;x++) ans = ans * inv_fact[c[x]] % MOD;
        return ans;
    }
};

int main(){
  string s;
  cin >> s;
  
  Solution sol;
  cout << sol.countBalancedPermutations(s) <<  "\n";
  return 0;
}
