#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

const ll M = 998244353;
const ll N = 5005;

bool ok[N][2];
ll dp[N][2][N];
ll P[N];
ll V[N];

ll n, q;

auto solve() { 
	cin >> n >> q;

	for (ll i = 1; i <= q; i++) {
		cin >> P[i] >> V[i];
	}

	ok[1][0] = ok[1][1] = true;
	for (ll i = 2; i <= q; i++) {
		ll vl, vr; vl = vr = 0;
		for (ll j = i - 1; j >= 1; j--) {
			if (P[i] >= P[j]) {
				vl = max(vl, V[j]);
			}
			if (P[i] <= P[j]) {
				vr = max(vr, V[j]);
			}
		}
		if (vl <= V[i]) {
			ok[i][0] = true;
		} else {
			ok[i][0] = false;
		}
		if (vr <= V[i]) {
			ok[i][1] = true;
		} else {
			ok[i][1] = false;
		}
	}

	dp[1][0][0] = 1;
	dp[1][1][0] = 1;


	for (ll i = 2; i <= q; i++) {
		if (ok[i][0]) {
			for (ll k = i - 2, j = i - 1; k >= 0; k--) {
				if (V[j] <= V[i]) {
					dp[i][0][k] += dp[j][0][k];
					dp[i][0][k] %= M;
				}
			}
			for (ll j = i - 2, k = i - 1; j >= 0; j--) {
				if (V[j] <= V[i]) {
					dp[i][0][k] += dp[k][1][j];
					dp[i][0][k] %= M;
				}
			}
		}

		if (ok[i][1]) {
			for (ll k = i - 2, j = i - 1; k >= 0; k--) {
				if (V[j] <= V[i]) {
					dp[i][1][k] += dp[j][1][k];
					dp[i][1][k] %= M;
				}
			}
			for (ll j = i - 2, k = i - 1; j >= 0; j--) {
				if (V[j] <= V[i]) {
					dp[i][1][k] += dp[k][0][j];
					dp[i][1][k] %= M;
				}
			}
		}
	}

	ll fans = 0;

	for (ll k = 0; k <= q - 1; k++) {
		fans += dp[q][0][k];
		fans %= M;
		fans += dp[q][1][k];
		fans %= M;
	}

	cout << fans << "\n";

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  solve();

  return 0;
}
