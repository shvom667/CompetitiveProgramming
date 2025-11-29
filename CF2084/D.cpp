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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> ans(n, 0);


    ll u = n / (m + 1);

    if (u == 0) {
        for (ll i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }   cout << "\n";
        return;
    }

    if (k > u) {
        for (ll i = 0; i < n; i++) {
            ans[i] = (i%k);
        }
    } else {
        for (ll i = 0; i < n; i++) {
            ans[i] = (i%u);
        }
    }



    for (ll i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }   cout << "\n";
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
