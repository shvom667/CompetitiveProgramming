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
	vector<ll> b(n);
	vector<vector<ll>> sb(n + 1, vector<ll> ());
	for (ll i = 0; i < n; i++) {
		cin >> b[i];
		sb[b[i]].pb(i);
	}

	for (ll i = n; i >= 1; i--) {
		if ((sb[i].size())%i) {
			cout << -1 << '\n';
			return;
		}
	}

	vector<ll> a(n, -1);
	for (ll i = n, c = 1; i >= 1; i--) {
		for (ll j = 1; j <= (ll)sb[i].size(); j++) {
			a[sb[i][j-1]] = c;
			if (j%i == 0) {
				c++;
			}
		}
	}

	for (auto x : a) {
		cout << x << " ";
	}
	cout << '\n';

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
