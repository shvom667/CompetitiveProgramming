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
	ll n, m;
	cin>>n>>m;
	vector<vector<ll>> g(n);
	for(ll i=0;i<m;i++){
		ll u,v;cin>>u>>v;--u;--v;
		g[u].pb(v);g[v].pb(u);
	}


	vector<Vec<ll>> adjTree(n);
	vector<bool> seen(n, false);

	Vec<ll> sz(n, 0);
	Vec<ll> dep(n, 0);
	function<void(ll)>dfs=[&](ll i){
		seen[i] = true;
		for (auto ch : g[i]) {
			if (!seen[ch]) {
				adjTree[ch].pb(i);
				adjTree[i].pb(ch);
				dep[ch] = dep[i] + 1;
				dfs(ch);
				sz[i] += sz[ch];
			}
		}
		sz[i] += 1;
	};

	dfs(0);

	seen = vector<bool>(n,false);

	ll fans = n * (n - 1) / 2;

	auto upd = [&] (ll n, ll a, ll b) {
		ll cur = 0;
		cur += a * (a - 1) / 2;
		cur += b * (b - 1) / 2;
		fans = min(fans, cur);
	};
	dbg(adjTree);
	dbg(g);
	set<ll> st;
	function<ll(ll, ll)>dfs1=[&](ll i, ll p){
		seen[i] = true;
		ll res = n  + 1;
		for (auto ch : adjTree[i]) {
			if (!seen[ch]) {
				// [i, ch]
				ll ch_res = dfs1(ch, i);
				if (res == n + 1) {
					res = ch_res;
				}else {
					if (ch_res != n + 1 && dep[ch_res] < dep[res]) {
						res = ch_res;
					}
				}
			}
		}



		for (auto x : g[i]) {
			if (dep[x] < dep[i] && x != p) {
				if (res == n + 1) {
					res = x;
				} else {
					if (dep[x] < dep[res]) {
						res = x;
					}
				}
			}
		}
		

		dbg(i, res);
		if (res == n + 1 || dep[res] >= dep[i]) {
			upd(n, sz[i], n - sz[i]);
		}
		return res;
	};

	dfs1(0, -1);



	return fans;
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
