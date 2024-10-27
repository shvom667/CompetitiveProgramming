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


#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define fbo find_by_order(x)
#define ook(x) order_of_key(x)
/*
 * find_by_order(x) : return the (x + 1) th smallest element
 * order_of_key(x)  : number of elements strictly less than x
 */

auto solve() {
    ll n;
    cin >> n;
    ll a[n];
    Vec<ll> g[n + 1];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        g[a[i]].pb(i);
    }

    vector<pair<ll, ll>> vp;

    for (ll i = 1; i <= n; i++) {
        if (g[i].size() <= 1) continue;
        for (ll j = 0; j < ((ll)g[i].size()) / 2; j++) {
            vp.pb({g[i][j], g[i][(ll)g[i].size() - 1 - j]});
        }
    }
    sort(begin(vp), end(vp), [&] (auto x, auto y) {
        return x.second - x.first > y.second - y.first;
    });
    dbg(vp);

    ordered_set oset;

    for (ll i = 0; i < n; i++) {
        oset.insert(i);
    }
    ll fans = 0;
    for (auto& [x, y] : vp) {
        fans += 1 + oset.ook(y) - oset.ook(x + 1); 
        oset.erase(x);
        oset.erase(y);
    }

    return fans;
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
