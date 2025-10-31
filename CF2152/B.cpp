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
    ll n, px, py, hx, hy;
    cin >> n >> px >> py >> hx >> hy;

    ll x1, y1, x2, y2;


    x1 = abs(px - hx);
    y1 = abs(py - hy);

    if (true) {
        if (px - 0 < hx - 0) {
            x2 = px + 1;
        } else if (n - px + 1 < n - hx + 1) {
            x2 = n - px + 1;
        } else {
            x2 = 0;
        }
    }

    if (true) {
        if (py - 0 < hy - 0) {
            y2 = py + 1;
        } else if (n - py + 1 < n - hy + 1) {
            y2 = n - py + 1;
        } else {
            y2 = 0;
        }
    }

    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';

    if (hx == px) {
        if (hy > py) {
            cout << hy << '\n';
        } else {
            cout << n - hy << "\n";
        }
        return;
    }

    if (hy == py) {
        if (hx > px) {
            cout << hx << "\n";
        } else {
            cout << n - hx << '\n';
        }
        return;
    }

    ll fans =  max(max(0ll, min(x1-1, y2)) + x2, max(0ll, min(y1-1, x2)) + y2);

    auto corner = [&] (ll x, ll y) {
        bool a = x == 0 || x == n;
        bool b = y == 0 || y == n;


        return a & b;
    };

    if (corner(px, py)) {
        fans++;
    }

    cout << fans << '\n'; 
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
