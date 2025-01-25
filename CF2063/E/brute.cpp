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


/*
	 LCA
	 -> 1 based indexing
	 -> Binary Lifting
	 -> Distance Queries On Tree
	 -> O(log(n))*Q + O(n*log(n)) 
	 -> 0 as ancestor of root
	 -> depth of root = 1
 */


using ll=long long;
const ll L=20;
const ll N=2e5+20;
vector<vector<ll>> adj, up;
ll timer;
vector<ll> tin, tout, depth;

void dfs(ll v, ll p) {
	tin[v] = ++timer;
	up[v][0] = p;
	for (ll i = 1; i < L; i++) {
		up[v][i] = up[up[v][i-1]][i-1];
	}
	for (auto& ch : adj[v]) {
		if (ch != p) {
			depth[ch] = depth[v]+1;
			dfs(ch, v);
		}
	}
	tout[v] = ++timer;
}

bool is_ancestor(ll u, ll v) {
	if (u==0) return true;
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v) {
	if (is_ancestor(u, v)) return u;
	if (is_ancestor(v, u)) return v;
	for (ll i = L - 1; i >=0; i--) {
		if (!is_ancestor(up[u][i], v)) {
			u = up[u][i];
		}
	}
	return up[u][0];
}

ll dist(ll u, ll v) {
	ll w = lca(u, v);
	return depth[u]+depth[v]-2*depth[w];
}

auto solve(){

	ll n;
	cin >> n;
	adj = vector<vector<ll>> (n+1);
	up = vector<vector<ll>> (n+1, vector<ll>(L, 0));
	depth = tout = tin = vector<ll> (n+1, 0);
	timer = 0;
	for (ll i=1;i<n;i++) {
		ll u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	depth[1] = 1;
	dfs(1, 0);	


	int fans = 0;

	for (ll i = 1; i <= n; i++) {
		for (ll j = i + 1; j <= n; j++) {
			if (is_ancestor(i, j) || is_ancestor(j, i)) {
				continue;
			}
			dbg(i, j);
			ll ca = lca(i, j);
			ll a = dist(i, ca);
			ll b = dist(j, ca);
			fans += 2 * min(a,b) - 1;
		}
	}

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
