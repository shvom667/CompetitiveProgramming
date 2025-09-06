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

	for (ll i = 1; i < n; i++) {
		ll u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	ll root = 0;
	vector<ll> seen(n, false);
	vector<ll> h(n, 0);
	h[root] = 0;
	function<void(int)> dfs = [&] (int i) {
		seen[i] = true;
		for (auto x : adj[i]) {
			if (!seen[x]) {
				h[x] = h[i] + 1;
				dfs(x);
			}
		}
	};
	dfs(root);

	ll new_root = root;
	for (ll i = 0; i < n; i++) {
		if (h[i] > h[new_root]) {
			new_root = i;
		}
	}

	vector<bool> seen2(n, false);
	vector<ll> h2(n, 0);
	h2[new_root] = 0;

	function<void(int)> dfs2 = [&] (int i) {
		seen2[i] = true;
		for (auto x : adj[i]) {
			if (!seen2[x]) {
				h2[x] = h2[i] + 1;
				dfs2(x);
			}
		}
	};


	ll second_root = new_root;
	dfs2(second_root);

	for (ll i = 0; i < n; i++) {
		if (h2[second_root] < h2[i]){
			second_root = i;
		}
	}

	vector<ll> ord;
	vector<bool> seen3(n, false);
	bool is_seen = false;
	function<void(int)> dfs3 = [&] (int i) {
		// cout << i << "\n";
		seen3[i] = true;
		ord.push_back(i);
		if(is_seen)return;
		if (i == second_root) {
			is_seen = true;
		}
		if(is_seen)return;
		for (auto x : adj[i]) {
			if (!seen3[x]) {
				if(is_seen)return;
				if (x == second_root) {
					is_seen = true;
				}
				dfs3(x);
				if(is_seen)return;
			}
			if(is_seen) return;
		
		}
		if (is_seen) return;
		ord.pop_back();
	};

	dfs3(new_root);

	// cout << new_root << " " << second_root << "\n";
	// cout << "ord\n";
	// for (auto x : ord) {
	// 	cout << x << " ";
	// }	cout << '\n';

	// cout <<"new + second root " << new_root << " " << second_root << "\n";

	vector<ll> deg(n, 0);
	for (ll i = 0; i < n; i++) {
		for (auto x: adj[i]) {
			deg[x]++;
		}
	}
	set<int> inOrd;
	for (auto x : ord) {
		inOrd.insert(x);
	}


	int A = -1, B = -1, C = -1;
	for (ll i = 0; i < (ll)ord.size(); i++) {
		ll node = ord[i];
		ll prev_node = -1;
		if (i - 1 >= 0) {
			prev_node = ord[i - 1];
		}
		if (deg[node] > 2) {
			// cout << "inside " << node << '\n';
			for (auto y : adj[node]) {
				if (inOrd.count(y) == 0) {
					// cout << "very much inside\n";
					A = prev_node;
					B = node;
					C = y;
					cout << A + 1 << " " << B + 1 << " " << C + 1 << '\n';
					return 0;
				}
			}

		}
	}

	cout << -1 << '\n';
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		auto res = solve();
		// cout << res << "\n";
	}
	return 0;
}
