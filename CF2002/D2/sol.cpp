#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif

const int N = 3e5 + 20;

int n, q;
int sz[N], par[N], p[N], pos[N], bad[N], cnt_bad;
vector<int> adj[N];
multiset<int> min_set[N], max_set[N];

void dfs(int i, int p) {
	for (auto&ch : adj[i]) {
		dfs(ch, i);
		sz[i] += sz[ch];
	}
	sz[i]++;
}

void dfs2(int i, int p) {
	for (auto& ch : adj[i]) {
		min_set[i].insert(pos[ch]);
		max_set[i].insert(pos[ch] + sz[ch] - 1);
		dfs2(ch, i);
	}
} 

void update(int x) {
	if (x < 1 || x > n) return;
	if (min_set[x].size() == 0) return;
	bool ok1 = pos[x] < *min_set[x].begin();
	bool ok2 = pos[x] + sz[x] - 1 >= *max_set[x].rbegin();
	
	if (ok1 && ok2) {
		if (bad[x] == 1) {
			bad[x] = 0;
			cnt_bad--;
		}
	} else {
		if (bad[x] == 0) {
			bad[x] = 1;
			cnt_bad++;
		}
	}
	
}

auto solve() {
	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		cin >> par[i];
		adj[par[i]].push_back(i);
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	
	dfs(1, -1);
	
	dfs2(1, -1);
	
	
	for (int i = 1; i <= n; i++) {
		if (min_set[i].size() == 0) continue;
		bool ok1 = pos[i] < *min_set[i].begin();
		bool ok2 = pos[i] + sz[i] - 1 >= *max_set[i].rbegin();
		if (ok1 && ok2) {
		} else {
			cnt_bad++;
			bad[i] = 1;
		}
	}
	
	vector<string> fans;
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (par[p[x]] >= 1 && par[p[x]] <= n) {
			min_set[par[p[x]]].erase(min_set[par[p[x]]].find(x));
			max_set[par[p[x]]].erase(max_set[par[p[x]]].find(x + sz[p[x]] - 1));
		}
		if (par[p[y]] >=1 && par[p[y]] <= n) {
			min_set[par[p[y]]].erase(min_set[par[p[y]]].find(y));
			max_set[par[p[y]]].erase(max_set[par[p[y]]].find(y + sz[p[y]] - 1));
		}
		int vx, vy;
		vx = p[x], vy = p[y];
		
		p[x] = vy;
		p[y] = vx;
		pos[p[x]] = x;
		pos[p[y]] = y;
		
	
		if (par[p[x]] >= 1 && par[p[x]] <= n) {
			min_set[par[p[x]]].insert(x);
			max_set[par[p[x]]].insert(x + sz[p[x]] - 1);
		}
		if (par[p[y]] >=1 && par[p[y]] <= n) {
			min_set[par[p[y]]].insert(y);
			max_set[par[p[y]]].insert(y + sz[p[y]] - 1);
		}
		update(p[x]);
		update(par[p[x]]);
		update(p[y]);
		update(par[p[y]]);
		fans.push_back((cnt_bad == 0 ? "YES" : "NO"));
	}
	
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		min_set[i].clear();
		max_set[i].clear();
		sz[i] = 0;
		p[i] = 0;
		pos[i] = 0;
		par[i] = 0;
		bad[i] = 0;
		cnt_bad = 0;
	}
	return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        for (auto& ans: res) {
			cout << ans << "\n";
		}
    }
    return 0;
}
