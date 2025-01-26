
#include <bits/stdc++.h>
#include <atcoder/scc>

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


ll get_bit(ll x, ll bit) {
	if (x & (1 << bit)) return 1;
	return 0;
}

auto solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll> (m));
	vector<vector<ll>> b(n, vector<ll> (m));

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}

	auto good = [&] (auto na, auto nb) {
		// [0...n-1 n + 0, .. n + m - 1]
		vector<vector<ll>> G(n + m);

		vector<ll> must;

		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				if (nb[i][j] == 0) {
					G[j + n].pb(i);
				} else {
					G[i].pb(j + n);
				}

				if (na[i][j] != nb[i][j]) {
					if (nb[i][j] == 0) {
						must.pb(i);
					} else {
						must.pb(j + n);
					}
				}
			}
		}

		for (auto x : must) {
			
			vector<bool> seen(n + m, false);
			function<void(int)> dfs = [&] (int i) {
				seen[i] = true;
				for (auto & ch : G[i]) {
					if (!seen[ch]) {
						dfs(ch);
					}
				}
			};

			dfs(x);

		}

		return true;
	};

	for (int bit = 0; bit < 30; bit++) {
		vector<vector<ll>> nb = b;
		vector<vector<ll>> na = a;
		for(ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				if (get_bit(na[i][j], bit)) na[i][j] = 1;
				else na[i][j] = 0;

				if (get_bit(nb[i][j], bit)) nb[i][j] = 1;
				else nb[i][j] = 0;
			}
		}
		if (!good(na, nb)) {
			return "No";
		}
	}



	return "Yes";
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
