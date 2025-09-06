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

	vector<vector<ll>> adj(n, vector<ll> ());

	vector<ll> deg(n, 0);

	for (ll i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		u--;v--;
		adj[u].pb(v);
		adj[v].pb(u);
		deg[u]++;
		deg[v]++;
	}

	ll cnt_leaf = 0;

	ll fans=1e18;

	for (ll i = 0; i < n; i++) {
		if(deg[i] == 1) cnt_leaf++;
		ll cur_leaf = 0;
		for (auto x : adj[i]) {
			if(deg[x] == 1) {
				cur_leaf++;
			}
		}
		if (deg[i] == 1) cur_leaf++;

		fans=min(fans,-cur_leaf);

	}

	return cnt_leaf+fans;
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
