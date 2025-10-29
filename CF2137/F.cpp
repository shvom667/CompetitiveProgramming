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
	ll n;
	cin >> n;
	vector<ll> x(n), y(n);
	for (ll i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (ll i = 0; i < n; i++) {
		cin >> y[i];
	}

	vector<ll> pge(n, -1);
	
	deque<ll> d;
	d.pb(0);

	ll fans = 0;


	if (x[0] == y[0]) {
		fans += n;
	}
	

	for (ll i = 1; i < n; i++) {
		while (!d.empty() &&  x[d.back()] < x[i]) {
			d.pop_back();
		}
		if (d.empty()) {
			pge[i] = -1;
		} else {
			pge[i] = d.back();
		}

		if (x[i] == y[i]) {
			fans += (n - i) * (i + 1);
		}

		if (true && x[i] != y[i] && d.size() > 0) {
			ll L, R;
			L = 0, R = d.size() - 1;
			auto cond = [&] (int k) {
				return x[d[k]] >= y[i];
			};
			while (L <= R) {
				ll mid = L + (R - L) / 2;
				if (cond(mid)) {
					L = mid + 1;
				} else {
					R = mid - 1;
				}
			}
			
			if (R != -1)
				fans += (d[R] + 1) * (n - i);
		}

		d.push_back(i);
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
	}
	return 0;
}
