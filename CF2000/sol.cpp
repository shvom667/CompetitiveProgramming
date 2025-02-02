#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif
using pl = pair<ll, ll>;
const ll inf = 1e10;
auto solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n), b(n);
	for (ll i = 0; i < n; i++) 
	{
		cin >> a[i] >> b[i];
	}

	ll op[n][101];
	for (ll i = 0; i < n; i++) for (ll j = 0; j < 101; j++) op[i][j] = inf;

	for (ll i = 0; i < n; i++) {
		op[i][0] = 0;
		for (ll j = 1; j <= 100; j++) {
			if (a[i] == b[i] && a[i] == 1) {
				op[i][j] = op[i][j - 1] + 1;
				if (j  + 1 <= 100) {
					op[i][j + 1] = op[i][j]; 
				}
				break;
			}
			if (a[i] < b[i]) {
				b[i]--;
				op[i][j] = op[i][j - 1]  + a[i];
			} else {
				a[i]--;
				op[i][j] = op[i][j - 1] + b[i];
			} 
		}
	}

	ll dp[n][k+1];

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j <= k; j++) {
			dp[i][j] = inf;
		}
	}

	for (ll j = 0; j <= k; j++) {
		dp[0][j] = op[0][j];
	}

	for (ll i = 1; i < n; i++) {
		for (ll j = 0; j <= k; j++) {
			for (ll l = 0; l <= j; l++) {
				dp[i][j] = min(dp[i][j], dp[i - 1][l] + op[i][j - l]);
			}
		}
	}

	if (dp[n - 1][k] >= inf) {
		return -1ll;
	}
	return dp[n - 1][k];
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
