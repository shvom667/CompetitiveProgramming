#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll mod=998244353;
long long binpow_remainder(long long a, long long b, long long m=mod) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll inv(ll n){
    return binpow_remainder(n,mod-2);
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    vector<vector<ll>> dp(n+1,vector<ll> (2));
    vector<vector<ll>> dp1(n+1,vector<ll> (2));
    dp[1]={0,1};
    for(ll i=2;i<=n;i++) {
        // ll p=0;
        ll p=(i-1)*inv(n);p%=mod;

        ll s1,s2;
        s1=inv(1-(p*p)%mod+mod);
        s2=(s1*p)%mod;

        dp[i][0] = dp[i-1][1]*(1-p+mod) % mod * s1 %mod + dp[i-1][0] * (1-p+mod) %mod * s2 %mod; dp[i][0]%=mod;
        dp[i][1] = dp[i-1][0]*(1-p+mod) % mod * s1 %mod + dp[i-1][1] * (1-p+mod) %mod * s2 %mod; dp[i][1]%=mod;

        dp1[i][0] = dp1[i-1][0] + dp[i-1][0] * p % mod * s1 %mod + dp[i-1][1] * p % mod * s2 %mod;dp1[i][0]%=mod;
        dp1[i][1] = dp1[i-1][1] + dp[i-1][1] * p % mod * s1 %mod + dp[i-1][0] * p % mod * s2 %mod;dp1[i][1]%=mod;
    }
    cout<<dp1[n][0]<<" "<<dp1[n][1]<<"\n";
    cout << (dp1[n][0]+dp1[n][1]) % mod << "\n";
}
