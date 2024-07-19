/* Description:
Algorithm: Hopcroft-Karp
Implementation: https://usaco.guide/adv/max-flow?lang=cpp
*/
#include <bits/stdc++.h>
using namespace std;
using ll = int;
const int INF = 1e9;
#define pb push_back
int n, m, k;
// dist[node] = the position of node in the alternating path
vector<int> match, dist;
vector<vector<int>> g;

bool bfs() {
	queue<int> q;
	// The alternating path starts with unmatched nodes
	for (int node = 1; node <= n; node++) {
		if (!match[node]) {
			q.push(node);
			dist[node] = 0;
		} else {
			dist[node] = INF;
		}
	}

	dist[0] = INF;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (dist[node] >= dist[0]) { continue; }
		for (int son : g[node]) {
			// If the match of son is matched
			if (dist[match[son]] == INF) {
				dist[match[son]] = dist[node] + 1;
				q.push(match[son]);
			}
		}
	}
	// Returns true if an alternating path has been found
	return dist[0] != INF;
}

// Returns true if an augmenting path has been found starting from vertex node
bool dfs(int node) {
	if (node == 0) { return true; }
	for (int son : g[node]) {
		if (dist[match[son]] == dist[node] + 1 && dfs(match[son])) {
			match[node] = son;
			match[son] = node;
			return true;
		}
	}
	dist[node] = INF;
	return false;
}

int hopcroft_karp() {
	int cnt = 0;
	// While there is an alternating path
	while (bfs()) {
		for (int node = 1; node <= n; node++) {
			// If node is unmatched but we can match it using an augmenting path
			if (!match[node] && dfs(node)) { cnt++; }
		}
	}
	return cnt;
}
void all_clear() {
  g.clear();
  match.clear();
  dist.clear();
}
bool cond(vector<pair<ll, ll>>& edges, ll nn) {
  n = nn;
  m = nn;
  k = edges.size();

	dist.resize(n + m + 1);
	match.resize(n + m + 1);
	g.resize(n + m + 1);

	for (int i = 1; i <= k; i++) {
		int x, y;
    x = edges[i-1].first;
    y = edges[i-1].second;

		y += n;

		g[x].push_back(y);
		g[y].push_back(x);
	}

  ll res;
	res = hopcroft_karp();
  all_clear();
  return res >= nn;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<ll> u(m), v(m), d(m);
  for (ll i = 0; i < m; i++) {
    cin >> u[i] >> v[i] >> d[i];
  }
  ll l = 0, r = INF+20;
  while (l <= r) {
    ll mid = l + (r - l) / 2;
    vector<pair<ll, ll>> edges;
    for (ll i = 0; i < m; i++) 
      if (d[i] <= mid)
        edges.pb({u[i], v[i]});
    if (cond(edges, n) && edges.size() >= n) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << (l>INF?-1:l) << "\n";
}
