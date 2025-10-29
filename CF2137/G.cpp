#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
#include <functional>
#include<stack>

using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/Users/shivom.1/development/CompetitiveProgramming/DataStructures/debug.cpp"
#include "/Users/shivom.1/development/CompetitiveProgramming/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42l
#endif

auto solve() {
	ll n, m, q;
	cin >> n >> m >> q;

	vector<vector<ll>> C(n, vector<ll>());
	vector<vector<ll>> P(n, vector<ll>());

	for (ll i = 0; i < m; i++) {
		ll u, v; cin >> u >> v;
		u--; v--;
		C[u].pb(v);
		P[v].pb(u);
	}

	vector<vector<ll>> Ans(n, vector<ll>(2, 0));	vector<vector<ll>> Sum(n, vector<ll>(2, 0));

	vector<ll> Ord;
	vector<bool> seen(n, false);
	function<void(int)> Topo = [&] (int i) {
		seen[i] = true;
		for (auto ch : C[i]) {
			if (!seen[ch])
				Topo(ch);
		}
		Ord.push_back(i);
	};

	for (ll i = 0; i < n; i++) {
		if (!seen[i]) Topo(i);
	}

	vector<ll> TopoIndex(n, 0);

	for (ll i = 0; i < n; i++) {
		TopoIndex[Ord[i]] = i;
	}



	for (ll i = 0; i < n; i++) {
		sort(P[i].begin(), P[i].end(), [&] (int x, int y) {
			return TopoIndex[x]>TopoIndex[y];
		});
	}

	for (auto u : Ord) {
		Ans[u][0] = 1;
		Ans[u][1] = 1;
		for (auto ch : C[u]) {
			Sum[u][0] += Ans[ch][1];
			Sum[u][1] += Ans[ch][0];
		}
	}

	dbg(Ord);

	dbg(P);
	// Sort the parent array in topo sort order


	function<void(int, int)> Rec = [&] (int u, int k) {
		// if (Sum[u][k] == 0) {
		// 	assert(Ans[u][k] == 0);
		// 	return;
		// }
		if (Ans[u][k] == 0) {
			for (auto p : P[u]) {
				if (Sum[p][k^1] == 0) continue;
				Sum[p][k^1]--;
				if (Sum[p][k^1] == 0) {
					Ans[p][k^1] = 0;
					Rec(p, k^1);
				}
			}
		}
	};

	for (ll i = 0; i < q; i++) {
		ll x, u; cin >> x >> u; u--;
		if (x == 1) {

			Ans[u][0] = 0;
			if (Ans[u][1] != 0) {
				Ans[u][1] = 0;
				for (auto p : P[u]) {
					Sum[p][0]--;
				}
			}
			

			for (auto p : P[u]) {
				Ans[p][1] = 0;
			}
			for (auto p : P[u]) {
				Rec(p, 1);
			}
			for (auto p : P[u]) {
				if (Sum[p][0] == 0) {
					Rec(p, 0);
				}
			}

					
			cout<<"----------------\n";
			for (ll i = 0; i < n; i++) {
				cout << i + 1 << " " << Ans[i][0]<<"_"<<Ans[i][1] << " " << Sum[i][0]<<"_"<<Sum[i][1] << "\n";
			}
		} else {
			if (Ans[u][0]) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}

	// cout<<"----------------\n";
	// for (ll i = 0; i < n; i++) {
	// 	cout << i + 1 << " " << Ans[i][0]<<"_"<<Ans[i][1] << " " << Sum[i][0]<<"_"<<Sum[i][1] << "\n";
	// }

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		solve();
		// cout << res << "\n";
	}
	return 0;
}
