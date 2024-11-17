#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
auto solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1, 0), p;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    p = a;
    for (ll i = 1; i <= n; i++)
        p[i] += p[i - 1];
    vector<ll> dp(n + 1, 0);
    dp[n] = (a[n] <= k ? 0 : 1);
    ll fans = dp[n];
    for (ll i = n - 1; i >= 1; i--)
    {
        ll r = upper_bound(begin(p) + i, end(p), k + p[i - 1]) - begin(p);
        if (r <= n)
            dp[i] = 1 + (r + 1 <= n ? dp[r + 1] : 0);
        fans += dp[i];
    }
    return n * (n + 1) / 2 - fans;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        auto res = solve();
        cout << res << '\n';
    }
}
