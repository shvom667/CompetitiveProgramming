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

auto ask(ll i, ll x) {
    cout << "? " << i + 1 << " " << x << endl;
    ll res;
    cin >> res;
    return res;
}

auto give(ll x) {
    cout << "! " << x << endl;
}

auto hbit(ll x) {
    ll res = -1;
    for (ll i = 0; i < 31; i++) {
        if ((1ll<<i) & x) {
            res = i;
        }
    }
    return res;   
}

auto solve() {
    ll n;
    cin >> n;

    ll H = hbit(n);

    ll x = 0;
    vector<bool> seen(n, false);
    for (ll bit = H; bit >= 0; bit--) {
        ll sb = 0;

        x ^= (1ll << bit);

        for (ll i = 1; i <= n; i++) {
            if ((x & i) == x) {
                sb++;
            }
        }
        dbg(x, bit);

        dbg(x, bit);
        dbg(sb);
        ll sbp = 0;
        vector<ll> ans1, ans0;
        for (ll i = 0; i < n - 1; i++) {
            if (seen[i]) continue;
            if (ask(i, x)) {
                sbp++;
                ans1.pb(i);
            } else {
                ans0.pb(i);
            }
        }
        dbg(x, sbp, sb);
        if (sbp == sb) {
            x ^= (1ll << bit);
            // x has 0 bit ans1 seen
            for (auto x : ans1) {
                seen[x] = true;
            }
        } else {
            assert(sbp == sb - 1);
            for (auto x : ans0) {
                seen[x] = true;
            }
        }
        dbg(x);
    }
    give(x);
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
