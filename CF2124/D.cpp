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


bool isp(vector<ll> v) {
	ll n = (ll)v.size();
	for (ll i = 0; i < n; i++) {
		if (v[i] != v[n - i -1]) {
			return false;
		}
	}
	return true;
}

auto solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n), b;

	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	b = a;
	sort(begin(b),end(b));

	ll e = b[k-1];

	vector<ll> ts,bs;

	for (ll i = 0; i < n; i++) {
		if (a[i] <= e) {
			bs.pb(a[i]);
		}
		if (a[i] >= e) {
			continue;
		}
		ts.pb(a[i]);
	}

	if (!isp(ts)) {
		cout << "NO\n";
		return;
	}

	ll cnt = 0;
	ll T = (ll)ts.size();
	dbg(bs);
	vector<ll> bk((ll)ts.size() + 1, 0);
	for (ll i = 0, cnt = 0; i < (ll)bs.size(); i++) {
		if (bs[i] < e) {
			cnt++;
		}
		else {
			bk[cnt]++;
		}
	}

	dbg(bk);

	ll pad = 0;
	for (ll i = 0; i < T + 1; i++) {
		if (i > T - i) continue;
		if (i == T - i) {
			pad += bk[i];
		} else {
			pad += min(bk[i] , bk[T - i]) * 2;
		}
	}

	dbg(pad, T);
	if ((pad + T) >= k - 1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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
