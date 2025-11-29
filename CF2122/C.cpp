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

	vector<pair<ll,ll>> p(n);
	
	vector<pair<ll,ll>> xpos,ypos;

	for (ll i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
		
		xpos.pb({p[i].first, i});
		ypos.pb({p[i].second, i});
	}

	sort(begin(xpos), end(xpos), [&](auto i, auto j) {
		return i.first < j.first;
	});

	sort(begin(ypos), end(ypos), [&](auto i, auto j) {
		return i.first < j.first;
	});

	vector<ll> xl, yl, xr, yr;
	map<ll,ll> xlmap, ylmap, xrmap, yrmap;
	for (ll i = 0; i < n; i++) {
		if (i < n / 2) {
			xl.pb(xpos[i].second);
			yl.pb(ypos[i].second);
			xlmap[xpos[i].second] = 1;
			ylmap[ypos[i].second] = 1;
		}else{
			xr.pb(xpos[i].second);
			yr.pb(ypos[i].second);
			xrmap[xpos[i].second] = 1;
			yrmap[ypos[i].second] = 1;
		}

	}

	vector<ll> xlyl, xlyr, xryl, xryr;

	dbg(xl, yl);
	dbg(xr, yr);

	for (auto xL : xl) {
		if (ylmap[xL] == 1) {
			xlyl.pb(xL);
		}
		if (yrmap[xL] == 1) {
			xlyr.pb(xL);
		}
	}

	for (auto xR : xr) {
		if (ylmap[xR] == 1) {
			xryl.pb(xR);
		}
		if (yrmap[xR] == 1) {
			xryr.pb(xR);
		}
	}
	
	dbg(xlyl);
	dbg(xryr);
	dbg(xryl);
	dbg(xlyr);

	assert((ll)xlyl.size() == (ll)xryr.size());
	assert((ll)xryl.size() == (ll)xlyr.size());

	for (ll i = 0; i < (ll)xlyl.size(); i++) {
		cout << xlyl[i] + 1 << " " << xryr[i] + 1 << "\n";
	}

	for (ll i = 0; i < (ll)xlyr.size(); i++) {
		cout << xlyr[i] + 1 << " " << xryl[i] + 1 << "\n";
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
