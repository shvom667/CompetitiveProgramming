#include<bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;
const ll INF = 2e18;

void solve() {
	ll n, w;
	cin >> n >> w;
	vector<ll> p(n+1, -1), l(n+1, INF), r(n + 1, -1);
	vector<ll> adj[n + 1];
	for (ll i = 2; i <= n; i++) {
		cin >> p[i];
		adj[i].pb(p[i]);
		adj[p[i]].pb(i);
	}
	
	function<void(ll, ll)> dfs = [&] (ll i, ll p) {
		for (auto& ch : adj[i]) {
			if (ch == p) continue;
			dfs(ch, i);
		}
		l[i] = r[i] = i;
		for (auto& ch : adj[i]) {
			if (ch == p) continue;
			l[i] = min(l[i], l[ch]);
			r[i] = max(r[i], r[ch]);
		}
	};
	dfs(1, -1);
	map<ll, set<ll>> mp, rmp;
	for (ll i = 2; i <= n; i++) {
		mp[l[i]].insert(i);
		mp[(r[i] + 1 <= n ? r[i] + 1 : 1ll)].insert(i);
		rmp[i].insert(l[i]);
		rmp[i].insert((r[i] + 1 <= n ? r[i] + 1 : 1ll));
	}
	
	ll free, fixed, W;
	fixed = 0;
	free = n;
	W = w;
	vector<ll> fans;
	
	for (ll i = 1; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		W -= y;
		for (auto& vals: rmp[x]) {
			mp[vals].erase(x);
			fixed += y;
			if (mp[vals].size() == 0) {
				mp.erase(vals);
			}
		}			
		free = mp.size();

		fans.pb(fixed + free * W);
	}
	for (auto& x : fans) {
		cout << x << " ";
	}	cout << "\n";
}

int main() {
	ll t;
	cin >> t;
	for (ll tc = 1; tc <= t; tc++) {
		solve();
	}
}
