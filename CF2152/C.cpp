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

// #ifndef ONLINE_JUDGE
// #include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
// #include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
// #else
// #define dbg(...) 42
// #define rnd(...) 42
// #endif



auto solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n), c0(n, 0), c1(n, 0);


    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        c0[i] = v[i] == 0;
        c1[i] = v[i] == 1;
        if (i) {
            c0[i] += c0[i - 1];
            c1[i] += c1[i - 1];
        }
    }


    vector<ll> alt(n);
    for (ll i = 0; i < n; i++) {
        alt[i] = i;
    }

    for (ll i = 1; i < n; i++) {
        if (v[i - 1] != v[i]) {
            alt[i] = alt[i - 1];
        } else {
            alt[i] = i;
        }
    }

    for (ll i = 0; i < q; i++) {
        ll l, r; cin >> l >> r;
        l--; r--;

        if (((r -l + 1) % 3) != 0) {
            cout << -1 << '\n';
            continue;
        }
        
        if ((c0[r] - (l - 1 >= 0 ? c0[l - 1] : 0ll)) % 3 != 0) {
            cout << -1 << '\n';
            continue;
        }

        // check that range [l..r] alt or not

        ll fans = (r - l + 1) / 3;

        if (alt[r] <= l) {
            fans++;
        }
        cout << fans << '\n';
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

/*

*/