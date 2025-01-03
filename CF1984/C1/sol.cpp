#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif
const ll mod = 998244353;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll x = 0, y = 0;
    map<ll, ll> mp;
    mp[0] = 1;
    for (ll i = 0; i < n; i++) {
        map<ll, ll> cmp;
        ll f1, f2, f3, f4;
        f1 = a[i] + x;
        f2 = abs(a[i] + x);
        f3 = a[i] + y;
        f4 = abs(a[i] + y);
        cmp[f1] += mp[x];
        cmp[f2] += mp[x];
        if (x != y) {
            cmp[f3] += mp[y];
            cmp[f4] += mp[y];
        }
        cmp[f1] %= mod;
        cmp[f2] %= mod;
        cmp[f3] %= mod;
        cmp[f4] %= mod;

        mp = cmp;
        dbg(mp);
        x = min({f1, f2, f3, f4});
        y = max({f1, f2, f3, f4});
    }
    return mp[y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
