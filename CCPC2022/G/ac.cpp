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
 
auto bf(ll x) {
    dbg(x);
    // for (ll x = 1; x <= 2e4; x++)
    ll cnt = 0;
    ll l2 = log2(x) + 1;
    l2 = 1 << l2;
    ll N = 1e4;

    vector<ll> ans;

    for (ll j = 1; j <= l2; j++) {
            ll a = gcd((j*x)^x, x);
            ans.pb(a);
    }

    for (ll k = 1; k <= N; k+=l2) {
        // set<ll> s;
        vector<ll> v;
        for (ll j = k; j <= k + l2 - 1; j++) {
            ll ans = gcd((j*x)^x, x);
            v.pb(ans);
        // dbg(k, (k*x)^x, gcd((k*x)^x, x), cnt);
        }
        dbg(v);
        assert(ans == v);
    }

    // for (ll k = 1; k <= 200; k++) {
    //     // ll b = k * x;
    //     ll ans = gcd((k*x)^x, x);
    //     ll ans2 = 2 * ((k * x) ^ x) & x;
    //     if (ans == 1) cnt++;
    //     // dbg(ans, ans2);
    //     if (x % 2 == 0) {
    //         assert(ans > 1);
    //     }
    //     // dbg(k, (k*x)^x, gcd((k*x)^x, x), cnt);
    // }
}

auto solve() {
    
    ll x, n;
    cin >> x >> n;



    ll l2 = log2(x) + 1;
    l2 = 1ll << l2;

    vector<ll> ans;
    ans.pb(0);
    
    for (ll j = 1; j <= l2; j++) {
            ll a = gcd((j*x)^x, x);
            ans.pb(a);
    }

    vector<ll> dp = ans;
    for (ll i = 1; i < dp.size(); i++){
        dp[i] = (dp[i] == 1);
    }

    dbg(dp);

    for (ll i = 1; i < dp.size(); i++) {
        dp[i] += dp[i - 1];
    }

    ll tot = dp[dp.size() - 1];

    auto get = [&] (ll val) {
        if (val < 1) return 0ll;

        ll fans = 0;
        fans += tot * (val/l2);
        fans += dp[val%l2];

        return fans;
    };


    while (n--) {
        ll l, r;
        cin >> l >> r;
        
        cout <<  get(r) - get(l - 1)  << "\n";
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
    }
    return 0;
}
