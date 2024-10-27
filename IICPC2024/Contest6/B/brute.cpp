#include <bits/stdc++.h>

#include <algorithm>

#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif

namespace atcoder
{
    namespace internal
    {

        template <class E>
        struct csr
        {
            std::vector<int> start;
            std::vector<E> elist;
            csr(int n, const std::vector<std::pair<int, E>> &edges)
                : start(n + 1), elist(edges.size())
            {
                for (auto e : edges)
                {
                    start[e.first + 1]++;
                }
                for (int i = 1; i <= n; i++)
                {
                    start[i] += start[i - 1];
                }
                auto counter = start;
                for (auto e : edges)
                {
                    elist[counter[e.first]++] = e.second;
                }
            }
        };

        // Reference:
        // R. Tarjan,
        // Depth-First Search and Linear Graph Algorithms
        struct scc_graph
        {
        public:
            scc_graph(int n) : _n(n) {}

            int num_vertices() { return _n; }

            void add_edge(int from, int to) { edges.push_back({from, {to}}); }

            // @return pair of (# of scc, scc id)
            std::pair<int, std::vector<int>> scc_ids()
            {
                auto g = csr<edge>(_n, edges);
                int now_ord = 0, group_num = 0;
                std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
                visited.reserve(_n);
                auto dfs = [&](auto self, int v) -> void
                {
                    low[v] = ord[v] = now_ord++;
                    visited.push_back(v);
                    for (int i = g.start[v]; i < g.start[v + 1]; i++)
                    {
                        auto to = g.elist[i].to;
                        if (ord[to] == -1)
                        {
                            self(self, to);
                            low[v] = std::min(low[v], low[to]);
                        }
                        else
                        {
                            low[v] = std::min(low[v], ord[to]);
                        }
                    }
                    if (low[v] == ord[v])
                    {
                        while (true)
                        {
                            int u = visited.back();
                            visited.pop_back();
                            ord[u] = _n;
                            ids[u] = group_num;
                            if (u == v)
                                break;
                        }
                        group_num++;
                    }
                };
                for (int i = 0; i < _n; i++)
                {
                    if (ord[i] == -1)
                        dfs(dfs, i);
                }
                for (auto &x : ids)
                {
                    x = group_num - 1 - x;
                }
                return {group_num, ids};
            }

            std::vector<std::vector<int>> scc()
            {
                auto ids = scc_ids();
                int group_num = ids.first;
                std::vector<int> counts(group_num);
                for (auto x : ids.second)
                    counts[x]++;
                std::vector<std::vector<int>> groups(ids.first);
                for (int i = 0; i < group_num; i++)
                {
                    groups[i].reserve(counts[i]);
                }
                for (int i = 0; i < _n; i++)
                {
                    groups[ids.second[i]].push_back(i);
                }
                return groups;
            }

        private:
            int _n;
            struct edge
            {
                int to;
            };
            std::vector<std::pair<int, edge>> edges;
        };

    } // namespace internal

} // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder
{

    struct scc_graph
    {
    public:
        scc_graph() : internal(0) {}
        scc_graph(int n) : internal(n) {}

        void add_edge(int from, int to)
        {
            int n = internal.num_vertices();
            assert(0 <= from && from < n);
            assert(0 <= to && to < n);
            internal.add_edge(from, to);
        }

        std::vector<std::vector<int>> scc() { return internal.scc(); }

    private:
        internal::scc_graph internal;
    };

} // namespace atcoder
using namespace atcoder;

using namespace std;
using ll = int;
#define pb push_back
template <typename T>
using Vec = vector<T>;

bool solve(ll n, ll m, vector<pair<ll, ll>> edges, vector<vector<ll>> in_edges, vector<vector<ll>> adj) 
{

    for (ll i = 0; i < n; i++) {
        if ((ll) in_edges[i].size() == 0) {
            return false;
        }
    }

    scc_graph graph(n);


    for (auto&[u, v] : edges) {
        graph.add_edge(u, v);
    }

    vector<vector<ll>> scc = graph.scc();

    vector<ll> grp(n);

    for (ll i = 0; i < scc.size(); i++) {
        for (auto&j : scc[i]) {
            grp[j] = i;
        }
    }   

    vector<vector<ll>> compressed_graph_out((ll)scc.size());
    vector<vector<ll>> compressed_graph_in((ll)scc.size());
    vector<vector<pair<ll, ll>>> compressed_scc_edges((ll)scc.size());
    for (auto&[u, v] : edges) {
        if (grp[u] == grp[v]) {
            compressed_scc_edges[grp[u]].pb({u,v});
                
            continue;
        }
        compressed_graph_out[grp[u]].push_back(grp[v]);
        compressed_graph_in[grp[v]].push_back(grp[u]);
    }

    for (ll i = 0; i < (ll) scc.size(); i++) {
        if ((ll)compressed_graph_in[i].size() == 0) {
            // check if this component is ok or not

            auto edges = compressed_scc_edges[i];
            dbg(edges);
            map<pair<ll, ll>, bool> mp;
            for (auto&x : edges) {
                mp[x] = true;
            }
            bool ok=false;
            for (auto&x : edges) {
                if (mp.find({x.second, x.first}) == mp.end()) {
                    ok=true;
                }
            }
            if ((ll) edges.size() >= 2 * scc[i].size()) {
                ok = true;
            } 

            if (!ok) {
                return false;
            }
        }
    }

    return true;
}

auto bf(ll n, ll m, vector<pair<ll, ll>> edges, vector<vector<ll>> in_edges, vector<vector<ll>> adj) 
{
    // choose a subset of edges
    bool ok=false;
    for (ll i = 0; i < (1ll << m); i++) {
        vector<pair<ll, ll>> chosen;
        for (ll bit = 0; bit < m; bit++) {
            if (i & (1ll << bit)) {
                chosen.push_back(edges[bit]);
            }
            map<pair<ll,ll>, bool> mp;
            for (auto& e : chosen) {
                mp[e] = true;
            }
            bool cur = true;
            for (auto&e : chosen) {
                if (mp.find({e.second, e.first}) != mp.end()) {
                    cur = false;
                }
            }
            vector<ll> indeg(n, 0);
            for (auto&[u, v] : chosen) {
                indeg[v]++;
            }
            for (ll i= 0; i < n; i++) {
                if (indeg[i] == 0) {
                    cur = false;
                }
            }
            if (cur == true) {
                ok = true; 
            }
        }
    }
    return ok;
}



int main()
{
    int t;
    t = 1;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<pair<ll, ll>> edges;
        vector<vector<ll>> in_edges(n);
        vector<vector<ll>> adj(n);
        for (ll i = 0; i < m; i++) {
            ll u, v;
            cin >> u >> v;
            u--; v--;
            edges.pb({u, v});
            adj[u].pb(v);
            in_edges[v].push_back(u);
        }
        auto res = bf(n, m, edges, in_edges, adj);
        cout <<( res == true ? "YES" : "NO" )<< "\n";
    }
    return 0;
}
