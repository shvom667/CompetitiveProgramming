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

auto solve() {
	ll n;
	cin >> n;
	vector<ll> L(n), R(n);
	for (ll i = 0; i < n; i++) {
		cin >> L[i] >> R[i];
	}

	vector<vector<ll>> adj(n);

	for (ll i = 1; i < n; i++) {
		ll u, v;
		cin >> u >> v;
		--u;--v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dbg(adj);

	ll extra = 0;
	vector<bool> seen(n, false);
	vector<ll> pos(n, 0), neg(n, 0);
	vector<ll> val(n, 0);

	function<void(int, int)> dfs = [&] (int i, int p) {
		seen[i] = true;
		vector<ll> child_vals;
		for (auto & ch : adj[i]) {
			if (!seen[ch]) {
				dfs(ch, i);
				child_vals.pb(val[ch]);
			}
		}
		sort(begin(child_vals), end(child_vals));
		if (child_vals.empty()) {
			val[i] = L[i];
		} else {
			if (R[i] >= child_vals.back()) {
				val[i] = max(L[i], child_vals.back());
			} else {
				val[i] = R[i];
				for (auto x : child_vals) {
					extra += max(0ll, x - val[i]);
				}
			}
		}
	};

	vector<bool> seen(n, false);

	function<void(int, int)> dfs = [&] (int i, int p) {
		seen[i] = true;
		for (auto & ch : adj[i]) {
			if (!seen[ch]) {
				dfs(ch, i);
			}
		}
	};

	dfs(0, -1);
	



	return val[0] + extra;
}

int main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		auto res = solve();
		cout << res << "\n";
	}
	return 0;
}
