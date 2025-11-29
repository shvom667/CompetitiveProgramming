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

const ll inf = 1e16;

auto solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> h(n, vector<ll> (n));

	vector<ll> a(n), b(n);

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cin >> h[i][j];
		}
	}
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (ll i = 0; i < n; i++) {
		cin >> b[i];
	}
	
	ll aans = 0;
	ll bans = 0;


	

	if (true) {
		ll fans = 0;

		vector<vector<ll>> dp(n, vector<ll> (2, inf));

		dp[0][0] = 0;
		dp[0][1] = a[0];

		auto isOk = [&] (ll i, ll ich, ll j, ll jch) {
			for (ll itr = 0; itr < n; itr++) {
				if (h[i][itr] + ich == h[j][itr] + jch) {
					return false;
				}
			}
			return true;
		};
		
		
		for (ll i = 1; i < n; i++) {
			// find the value of 

			if (isOk(i, 0, i - 1, 0)) {
				dp[i][0] = min(dp[i][0], dp[i-1][0]);
			}
			if (isOk(i, 0, i - 1, 1)) {
				dp[i][0] = min(dp[i][0], dp[i-1][1]);
			}
			if (isOk(i, 1, i - 1, 0)) {
				dp[i][1] = min(dp[i][1], dp[i-1][0] + a[i]);
			}
			if (isOk(i, 1, i - 1, 1)) {
				dp[i][1] = min(dp[i][1], dp[i-1][1] + a[i]);
			}
		}
		aans = min(dp[n-1][0], dp[n-1][1]);
	}
	if (true) {
		ll fans = 0;

		vector<vector<ll>> dp(n, vector<ll> (2, inf));

		dp[0][0] = 0;
		dp[0][1] = b[0];

		auto isOk = [&] (ll i, ll ich, ll j, ll jch) {
			for (ll itr = 0; itr < n; itr++) {
				if (h[itr][i] + ich == h[itr][j] + jch) {
					return false;
				}
			}
			return true;
		};
		
		
		for (ll i = 1; i < n; i++) {

			if (isOk(i, 0, i - 1, 0)) {
				dp[i][0] = min(dp[i][0], dp[i-1][0]);
			}
			if (isOk(i, 0, i - 1, 1)) {
				dp[i][0] = min(dp[i][0], dp[i-1][1]);
			}
			if (isOk(i, 1, i - 1, 0)) {
				dp[i][1] = min(dp[i][1], dp[i-1][0] + b[i]);
			}
			if (isOk(i, 1, i - 1, 1)) {
				dp[i][1] = min(dp[i][1], dp[i-1][1] + b[i]);
			}
		}
		bans = min(dp[n-1][0], dp[n-1][1]);
	}

	if ((aans + bans) >= inf) {
		cout << -1 << "\n";
		return;
	}
	
	cout << aans + bans << "\n";
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
