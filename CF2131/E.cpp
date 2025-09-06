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
	ll n;
	cin >> n;

	vector<ll> a(n), b(n);

	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll i = 0; i < n; i++) {
		cin >> b[i];
	}
	if (a[n - 1] != b[n - 1]) {
		return "NO";
	}
	for (ll i = n - 2; i >=  0; i--) {
		if (a[i] == b[i]) {
			continue;
		}
		if ((a[i]^a[i + 1]) == (b[i])) {
			continue;
		}
		if ((a[i]^b[i + 1]) == b[i]) {
			continue;
		}
		return "NO";
	}
	return "YES";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		auto res = solve();
		cout << res << "\n";
	}
	return 0;
}
