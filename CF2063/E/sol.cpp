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


auto solve(){

	ll n;
	cin >> n;
	auto adj = vector<vector<ll>> (n+1);

	for (ll i=1;i<n;i++) {
		ll u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<ll> depth(n + 1, 0);
	vector<ll> sz(n + 1, 0);

	depth[1] = 0;

	Vec<bool> seen(n + 1, false);

	ll fans = 0;

	vector<ll> cnt_depth(n + 1, 0);

	ll extra = 0;

	function<void(ll)> dfs = [&] (ll i) {
		cnt_depth[depth[i]]++;
		seen[i] = true;
		vector<ll> child_size;
		for (auto & ch : adj[i]) {
			if (!seen[ch]) {
				depth[ch] = depth[i] + 1;
				
				dfs(ch);
				sz[i] += sz[ch];
				child_size.push_back(sz[ch]);
			}
		}

		ll sum = 0, sq_sum = 0;
		for (auto x : child_size) {
			sq_sum += x * x;
			sum += x;
		}
		ll res = sum * sum - sq_sum;
		res /= 2;
		extra += res;

		dbg(i, res, depth[i]);
		fans -= res * (2 * depth[i]);

		sz[i]++;
	};

	depth[1] = 0;


	dfs(1);
	dbg(fans);
	dbg(cnt_depth);

	dbg(depth);

	vector<ll> sub(n, 0);

	for (ll i = 1; i <= n; i++) {
		sub[depth[i]] += sz[i] - 1;
	}

	ll prefix_sum = 0;
	for (ll d = n - 1; d >= 0; d--) {
		
		fans += (2 * d) * (cnt_depth[d] * prefix_sum - sub[d]);
		fans += (d) * cnt_depth[d] * (cnt_depth[d] - 1);
		dbg(d, fans);
		prefix_sum += cnt_depth[d];
	}	


	dbg(extra);

	fans -= extra;

	dbg(fans);

	cout << fans << '\n';

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		solve();
	}
	return 0;
}
