
#include <bits/stdc++.h>

#include <algorithm>

#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
  public:
    scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    // @return pair of (# of scc, scc id)
    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

}  // namespace atcoder


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


ll get_bit(ll x, ll bit) {
	if (x & (1 << bit)) return 1;
	return 0;
}

auto solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll> (m));
	vector<vector<ll>> b(n, vector<ll> (m));

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}

	auto good = [&] (auto na, auto nb) {
		// [0...n-1 n + 0, .. n + m - 1]
		vector<vector<ll>> G(n + m);

		vector<ll> must;

		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				if (nb[i][j] == 0) {
					G[j + n].pb(i);
				} else {
					G[i].pb(j + n);
				}

				if (na[i][j] != nb[i][j]) {
					if (nb[i][j] == 0) {
						must.pb(i);
					} else {
						must.pb(j + n);
					}
				}
			}
		}

		for (auto x : must) {
			
			vector<bool> seen(n + m, false);
			function<void(int)> dfs = [&] (int i) {
				seen[i] = true;
				for (auto & ch : G[i]) {
					if (!seen[ch]) {
						dfs(ch);
					}
				}
			};

			dfs(x);

		}

		return true;
	};

	for (int bit = 0; bit < 30; bit++) {
		vector<vector<ll>> nb = b;
		vector<vector<ll>> na = a;
		for(ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				if (get_bit(na[i][j], bit)) na[i][j] = 1;
				else na[i][j] = 0;

				if (get_bit(nb[i][j], bit)) nb[i][j] = 1;
				else nb[i][j] = 0;
			}
		}
		if (!good(na, nb)) {
			return "No";
		}
	}



	return "Yes";
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
