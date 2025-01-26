
#include <bits/stdc++.h>


using namespace std;
using ll = int;
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

	auto good = [&] (auto& na, auto& nb) {
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
		
		Vec<ll> state(n + m, 0);
		function<bool(int)> dfs = [&] (int i) {
			if (state[i] != 0) return false;
			state[i] = 1;
			bool res = false;
			for (auto & ch : G[i]) {
				if (state[ch] == 2) continue;
				else if (state[ch] == 0) {
					res |= dfs(ch);
				}
				else if(state[ch] == 1) {
					res = true;
				}
			}
			state[i] = 2;
			return res;
		};

		for (auto x : must) {
			auto res = dfs(x);
			if (res == true) {
				return false;
			}
		}
		

		return true;
	};

	for (int bit = 0; bit < 30; bit++) {
		vector<vector<bool>> nb(n, vector<bool> (m, false));
		vector<vector<bool>> na(n, vector<bool> (m, false));
		for(ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				if (get_bit(a[i][j], bit)) na[i][j] = 1;
				else na[i][j] = 0;

				if (get_bit(b[i][j], bit)) nb[i][j] = 1;
				else nb[i][j] = 0;
			}
		}
		if (na == nb) continue;
		if (!good(na, nb)) {
			dbg(bit);
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
