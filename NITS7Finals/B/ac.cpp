#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 100000;

int n, q;
vector<int> adj[MAXN];
int parent[MAXN], depth[MAXN], sz[MAXN], heavy[MAXN];
int value[MAXN];  // Value of each node
int chainHead[MAXN], posInBase[MAXN], chainIndex = 0;
vector<set<int>> chainSets(MAXN);  // Store set of values for each chain

// Precompute heavy-light decomposition (HLD)
void dfs(int u) {
    sz[u] = 1;
    int maxsz = -1, heavyChild = -1;
    for (int v : adj[u]) {
        if (v == parent[u]) continue;
        parent[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
        sz[u] += sz[v];
        if (sz[v] > maxsz) {
            maxsz = sz[v];
            heavyChild = v;
        }
    }
    heavy[u] = heavyChild;
}

void decompose(int u, int head) {
    chainHead[u] = head;
    posInBase[u] = chainIndex++;
    chainSets[head].insert(value[u]);  // Insert value into the chain's set
    if (heavy[u] != -1) {
        decompose(heavy[u], head);
    }
    for (int v : adj[u]) {
        if (v != parent[u] && v != heavy[u]) {
            decompose(v, v);
        }
    }
}

// Query path from u to v for the greatest node with value less than x
int queryPath(int u, int v, int x) {
    int result = -1;

    while (chainHead[u] != chainHead[v]) {
        if (depth[chainHead[u]] < depth[chainHead[v]]) swap(u, v);
        
        // Query the chain head of u
        int head = chainHead[u];
        auto it = chainSets[head].lower_bound(x); // Find first element >= x
        if (it != chainSets[head].begin()) {
            it--; // Move back to get the largest element less than x
            result = max(result, *it);  // Update result if valid
        }

        u = parent[head];  // Move u to its parent chain
    }

    // u and v are now in the same chain, query the segment between u and v
    if (depth[u] > depth[v]) swap(u, v);
    auto it = chainSets[chainHead[u]].lower_bound(x);
    if (it != chainSets[chainHead[u]].begin()) {
        it--;
        result = max(result, *it);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Read input
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> value[i];  // Values of the nodes
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;  // 0-based indexing
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Perform DFS to calculate szs, depths, and heavy-light decomposition
    parent[0] = -1;
    depth[0] = 0;
    dfs(0);
    
    // Decompose the tree into chains
    decompose(0, 0);

    // Answer queries
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--;  // 0-based indexing
        cout << queryPath(l, r, x) << '\n';
    }

    return 0;
}

