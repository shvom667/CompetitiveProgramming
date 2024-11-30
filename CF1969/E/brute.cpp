#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
#define dbg(...) 42
#endif

auto solve()
{
    ll n;
    cin >> n;
    Vec<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dbg(n);
    dbg(a);
    function<void(ll, ll)> dfs = [&](ll l, ll r)
    {
        if (l > r)
            return;
        if (l == r)
            return;
        map<ll, ll> mp;
        for (ll j = l; j <= r; j++)
        {
            mp[a[j]]++;
        }
        bool ok = false;
        for (ll j = l; j <= r; j++)
        {
            if (mp[a[j]] == 1)
            {
                ok = true;
                dfs(l, j - 1);
                dfs(j + 1, r);
                break;
            }
        }
        if (!ok)
        {
            // dbg("bad", l, r);
        }
    };
    // dfs(0, n - 1);
    Vec<Vec<ll>> dp(n, Vec<ll>(n + 1, 0));

    for (ll l = 2; l <= n; l++) {
        for (ll i = 0; i + l - 1 < n; i++)
        {
            // dp[i][l] ?
            map<ll, ll> mp;
            for (ll j = i; j <= i + l - 1; j++) {
                mp[a[j]]++;
            }
            bool ok = false;
            
            dp[i][l]= n;
            for(ll j = i; j <= i + l - 1; j++) {
                if (mp[a[j]] == 1) {
                    ok = true;
                    ll cur=0;
                    if (j - 1 >= i) {
                        cur += dp[i][j - i];
                    }
                    if (j + 1 <= i + l - 1) {
                        cur += dp[j+1][i + l - j - 1];
                    }
                    dp[i][l] = min(dp[i][l], cur);
                }
            }
            
            if (!ok) {
                dp[i][l] = n;
                
                for(ll j = i; j <= i + l - 1; j++) {
                    ll cur = 0;
                    
                    if (j - 1 >= i) {
                        cur += dp[i][j - i];
                    }
                    if (j + 1 <= i + l - 1) {
                        cur += dp[j+1][i + l - j - 1];
                    }
                    
                    dp[i][l] = min(dp[i][l], cur + 1);
                }

            }
        }
    }
    return dp[0][n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T=1; 
    // cin >> T;
    for (ll tc = 1; tc <= T; tc++)
    {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
