#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
#include <functional>
#include <stack>

using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;


#ifndef ONLINE_JUDGE
#include "/Users/shivom.1/development/CompetitiveProgramming/DataStructures/debug.cpp"
#include "/Users/shivom.1/development/CompetitiveProgramming/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif


auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<ll, ll>> fans;

    dbg(a);dbg(b);

    ll eq_cnt = 0, eq_val = -1;

    for (ll i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            eq_cnt++;
            eq_val = a[i];
        }
    }
    if (n%2==0) {
        if (eq_cnt > 0) {
            cout << -1 << "\n";
            return;
        }
    }

    if (n&1) {
        if (eq_cnt != 1) 
        {  
            cout << -1 << "\n";
            return;
        }
    }


    map<pair<ll, ll>, ll> mp;
    for (ll i = 0; i < n; i++) {
        mp[{a[i], b[i]}] = i;
    }

    for (ll i = 0; i < n; i++) {
        if (mp.find({b[i], a[i]}) == mp.end()) {
            cout << -1 << "\n";
            return;
        }
    }

    auto op = [&] (ll x, ll y) {
        ll X = mp[{a[x], b[x]}];
        ll Y = mp[{a[y], b[y]}];

        mp[{a[x], b[x]}] = Y;
        mp[{a[y], b[y]}] = X;

        swap(a[x], a[y]);
        swap(b[x], b[y]);

        if (x!=y)
            fans.pb({x, y});
    };

    if (n&1) {
        op(mp[{eq_val, eq_val}], n/2);
    }

    for (ll i = 0; i < n; i++) {
        if (mp[{a[i], b[i]}] != n - mp[{b[i], a[i]}] - 1) {
            op(mp[{b[i], a[i]}], n - mp[{a[i], b[i]}] - 1);
        }
    }

    dbg(a);
    dbg(b);

    cout << (ll)fans.size() << "\n";

    for (auto& [x, y]: fans) {
        cout << x+1 << " " << y+1 << "\n";
    }

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		solve();
		// auto res = solve();
		// cout << res << "\n";
	}
	return 0;
}
