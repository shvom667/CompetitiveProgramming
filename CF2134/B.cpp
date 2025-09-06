#include <bits/stdc++.h>
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
	// idea : make multiple of k - 1
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> fans = a;

	// x 

	// (x + y * k) % k - 1 == 0
	// what min y for this answer?

	// x % (k-1)
	// k-1 -(x%(k-1)) = want
	// y*k % (k-1) == want

	// y*k = want + (k-1)*z
	// y*k - want = (k-1)*z

	// how to solve this
	// 1 2 3 4 5 6 7 ... 
	
	// 6 12 18 24 30
	// 1 2  3  4 5 ... linear solvable

	// want * k

	if (k == 1) {
		for (ll i = 0; i < n; i++) {
			if (fans[i] & 1) {
				fans[i] += 1;
			}
		}

		return fans;
	}

	if (k == 2) {
		for (ll i = 0; i < n; i++) {
			if (fans[i] % 3 == 0) {
				continue;
			}
			if (fans[i] % 3 == 1) {
				fans[i] += 2;
			}
			if (fans[i] % 3 == 2) {
				fans[i] += 2 * 2;
			}
		}
		return fans;
	}

	for (ll i = 0; i < n; i++) {
		ll want = (k-1) - (a[i]%(k-1));
		fans[i] += want*k;
	}


	return fans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		auto res = solve();
		for (auto x : res ) {
			cout << x << " ";
		}	cout << '\n';
	}
	return 0;
}
