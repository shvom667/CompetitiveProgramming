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
    ll n;
    cin >> n;
    ll cnt = 0;
    ll fans = 0, ans = 0;
    ll tot = 0;
    vector<pair<ll, ll>> ab;
    for (ll j = 0; j < n; j++) {
        ll a, b;
        cin >> a >> b;
        ab.pb({a, b});
        tot += a;
        if (b == 0) {
            cnt++;
            continue;
        }
        dbg(a, b);
        fans = max(fans, a - b + 1);
        ans += a;
    }
    dbg(cnt);   
    if (cnt > 1) {
        cout << fans << " " << ans << "\n";
        return;
    }
    if (cnt == 0) {
        vector<ll> v;
        for (auto&[x,y]:ab)v.pb(x-y);
        sort(begin(v),end(v));
        ll b = 1e18;
        dbg(v);
        if (v.size() >= 2) b = v[v.size() - 2] + 1;
        cout << min(v[(ll)v.size() - 1] + 1, b + 1) << " " << tot << "\n";
        return;
    }
    fans += cnt;
    cout << fans << " " << tot << "\n";
    return;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        // auto res = solve();
        // cout << res << "\n";
        solve();
    }
    return 0;
}
