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

const ll inf = 1e18;

auto solve() {
	ll n;
	cin >> n;
	vector<ll> a(n, 0), dp;
	dp = a;

	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0] = a[0];
	dp[1] = a[0] + a[1] - 1;

	for (ll i = 2; i < n; i++) {
		dp[i] = max(a[i] - i, 0ll) + dp[i - 2] + a[i - 1];
		dp[i] = min(dp[i], dp[i - 1] + a[i] - 1);
	}

	return dp[n - 1];
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
