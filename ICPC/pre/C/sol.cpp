#include <bits/stdc++.h>
using namespace std;
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;//oset name name.order_of_key(#ele<k) *name.find_by_order(index) less_equal greater greater_equal

#define vi vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define int long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << "\n";
#define no cout << "NO" << "\n";
#define nl "\n"
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define mod 1000000007
const int oo = 1e18;
//-------------------------DSU---------------------------//

class DSU
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    vector<int> l, r;
    // Constructor to initialize DSU with 'n' elements
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        l.resize(n, 0);
        r.resize(n, 0);
        // Initializing each element as a separate set
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            l[i] = i;
            r[i] = i;
        }
    }

    // Find operation with path compression
    int findSet(int v)
    {
        if (v == parent[v])
        {
            return v;
        }
        return parent[v] = findSet(parent[v]); // Path compression
    }

    // Union operation by rank to optimize the tree height
    void unionSets(int a, int b)
    {
        int rootA = findSet(a);
        int rootB = findSet(b);
        if (rootA != rootB)
        {
            if (rank[rootA] < rank[rootB])
            {
                swap(rootA, rootB);
            }
            parent[rootB] = rootA;
            l[rootA] = min(l[rootA], l[rootB]);
            r[rootA] = max(r[rootA], r[rootB]);

            if (rank[rootA] == rank[rootB])
            {
                rank[rootA]++;
            }
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    vi xs(n + 1, 0);
    vector<vector<int>> gets;
    for (int i = 1; i <= n; i++)
    {
        cin >> xs[i];
    }
    vi as(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> as[i];
    }
    for (int i = 1; i <= n; i++)
    {
        gets.push_back({xs[i], as[i]});
    }
    sort(all(gets));
    for (int i = 0; i < n; i++)
    {
        xs[i + 1] = gets[i][0];
        as[i + 1] = gets[i][1];
    }
    if (n == 1)
    {
        cout << 0 << nl;
        return;
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 2; i < n; i++)
    {
        // cout<<xs[i]<<" "<<as[i]*abs(xs[i]-xs[i+1])<<nl;
        pq.push({as[i] * abs(xs[i] - xs[i + 1]), i, i + 1});
        pq.push({as[i] * abs(xs[i - 1] - xs[i]), i, i - 1});
    }
    pq.push({as[1] * abs(xs[1] - xs[2]), 1, 2});
    pq.push({as[n] * abs(xs[n - 1] - xs[n]), n, n - 1});

    DSU dsu(n + 1);
    int ans = 0;
    int edges = 0;
    // while(pq.size()){
    //     vi tt=pq.top();
    //     cout<<tt[0]<<" "<<xs[tt[1]]<<" "<<xs[tt[2]]<<nl;
    //     pq.pop();
    // }
    while (pq.size())
    {
        if (edges == n - 1)
        {
            break;
        }
        vi tt = pq.top();
        pq.pop();
        int uu = dsu.findSet(tt[1]);
        int vv = dsu.findSet(tt[2]);
        int u = tt[1];
        int v = tt[2];

        if (uu != vv)
        {
            ans += tt[0];
            dsu.unionSets(u, v);
            // cout<<xs[u]<<" "<<xs[v]<<" "<<tt[0]<<" "<<nl;
            edges++;
            if (v < u)
            {
                //v = dsu.l[dsu.findSet(u)];
                v = dsu.l[u];
                if (v - 1 >= 1)
                {

                    if (as[v - 1] >= as[u])
                    {
                        pq.push({as[u] * (abs(xs[u] - xs[v - 1])), u, v - 1});
                    }
                }
            }
            else
            {
                //v = dsu.r[dsu.findSet(u)];
                v = dsu.r[u];

                if (v + 1 <= n)
                {
                    if (as[v + 1] >= as[u])
                    {

                        pq.push({as[u] * (abs(xs[v + 1] - xs[u])), u, v + 1});
                    }
                }
            }
        }
        else
        {
            if (v < u)
            {
                //v = dsu.l[dsu.findSet(u)];
                v = dsu.l[u];

                if (v - 1 >= 1)
                {

                    if (as[v - 1] >= as[u])
                    {
                        pq.push({as[u] * (abs(xs[u] - xs[v - 1])), u, v - 1});
                    }
                }
            }
            else
            {
                //v = dsu.r[dsu.findSet(u)];
                v = dsu.r[u];

                if (v + 1 <= n)
                {
                    if (as[v + 1] >= as[u])
                    {

                        pq.push({as[u] * (abs(xs[v + 1] - xs[u])), u, v + 1});
                    }
                }
            }
        }
    }
    cout << ans << nl;
}
signed main()
{
    FastIO;
    // freopen("p.in", "r", stdin);
    // freopen("p.out", "w", stdout);
    int test = 1;
    //cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}

//------------------------binary exponentiation------------------
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
long long invertmod(long long a, long long m)
{
    return binpow(a, m - 2, m);
}

//-----------------------------------SPARSE TABLE----------------------------------------//
class SparseTable
{

    //    SparseTable spr(arr);
    //    spr.query(l,r);

private:
    vector<vector<int>> table;
    vector<int> logs;

public:
    SparseTable(const vector<int> &arr)
    {
        int n = arr.size();
        int maxLog = log2(n) + 1;

        // Initialize logs array for quick lookup
        logs.resize(n + 1);
        for (int i = 2; i <= n; i++)
        {
            logs[i] = logs[i / 2] + 1;
        }

        // Initialize the sparse table
        table.resize(maxLog, vector<int>(n));
        table[0] = arr;

        for (int k = 1; k < maxLog; k++)
        {
            for (int i = 0; i + (1 << k) <= n; i++)
            {
                table[k][i] = min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    // Query the range [l, r] for the minimum value
    int query(int l, int r)
    {
        int k = logs[r - l + 1];
        return min(table[k][l], table[k][r - (1 << k) + 1]);
    }
};

//-----------------------------------SEGMENT TREE----------------------------------------//
class SegmentTree
{
private:
    vector<int> tree;
    int n;

    // Function to build the segment tree
    void build(const vector<int> &arr, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = arr[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(arr, v * 2, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            tree[v] = tree[v * 2] + tree[v * 2 + 1]; // Modify this line based on the query
        }
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n); // Adjust the size based on the maximum size of your input array
        build(arr, 1, 0, n - 1);
    }

    // Function to update a value at index idx to val
    void update(int idx, int val)
    {
        update(1, 0, n - 1, idx, val);
    }

    // Function to query the range [l, r]
    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }

private:
    // Function to update a value at index idx to val in the segment tree
    void update(int v, int tl, int tr, int idx, int val)
    {
        if (tl == tr)
        {
            tree[v] = val;
        }
        else
        {
            int tm = (tl + tr) / 2;
            if (idx <= tm)
            {
                update(v * 2, tl, tm, idx, val);
            }
            else
            {
                update(v * 2 + 1, tm + 1, tr, idx, val);
            }
            tree[v] = tree[v * 2] + tree[v * 2 + 1]; // Modify this line based on the query
        }
    }

    // Function to query the range [l, r] in the segment tree
    int query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
        {
            return 0; // Modify this line based on the query
        }
        if (l == tl && r == tr)
        {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        // Modify the line above based on the query
    }
};

//-------------------------SEGMENT TREE with LAZY PROPOGATION---------------------------//

class SegmentTreeL
{
private:
    vector<int> tree, lazy;
    int n;

    // Function to propagate lazy updates
    void propagate(int v, int tl, int tr)
    {
        if (lazy[v] != 0)
        {
            tree[v] += lazy[v] * (tr - tl + 1);

            if (tl != tr)
            {
                lazy[v * 2] += lazy[v];
                lazy[v * 2 + 1] += lazy[v];
            }

            lazy[v] = 0;
        }
    }

    // Function to build the segment tree
    void build(const vector<int> &arr, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = arr[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(arr, v * 2, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            tree[v] = tree[v * 2] + tree[v * 2 + 1]; // Modify this line based on the query
        }
    }

public:
    SegmentTreeL(const vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n); // Adjust the size based on the maximum size of your input array
        lazy.resize(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    // Function to update a range [l, r] with a value val
    void update(int l, int r, int val)
    {
        update(1, 0, n - 1, l, r, val);
    }

    // Function to query the range [l, r]
    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }

private:
    // Function to update a range [l, r] with a value val in the segment tree
    void update(int v, int tl, int tr, int l, int r, int val)
    {
        propagate(v, tl, tr);

        if (l > r)
        {
            return;
        }

        if (l == tl && r == tr)
        {
            tree[v] += val * (tr - tl + 1);

            if (tl != tr)
            {
                lazy[v * 2] += val;
                lazy[v * 2 + 1] += val;
            }
        }
        else
        {
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), val);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
            tree[v] = tree[v * 2] + tree[v * 2 + 1]; // Modify this line based on the query
        }
    }

    // Function to query the range [l, r] in the segment tree
    int query(int v, int tl, int tr, int l, int r)
    {
        propagate(v, tl, tr);

        if (l > r)
        {
            return 0; // Modify this line based on the query
        }

        if (l == tl && r == tr)
        {
            return tree[v];
        }

        int tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        // Modify the line above based on the query
    }
};

//-------------------------LCA OF TREE---------------------------//

class LCA
{
public:
    int n, logN;
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;
    vector<vector<int>> data;
    vector<int> height;
    vector<int> vis;
    vector<int> valNodes;

    LCA(vector<vector<int>> &graph, int noOfNodes, vector<int> &valOfNodes)
    {
        noOfNodes++;
        logN = ceil(log2(noOfNodes));
        tin.resize(noOfNodes);
        tout.resize(noOfNodes);
        up.resize(noOfNodes);
        data.resize(noOfNodes);
        height.resize(noOfNodes);
        vis.resize(noOfNodes, 0);
        valNodes = valOfNodes;
        for (int i = 0; i < noOfNodes; i++)
            up[i].resize(logN + 1, 0),
                data[i].resize(logN + 1, 0);

        DFS(graph, 1, 1);
    }

    void DFS(vector<vector<int>> &graph, int vertex, int parent)
    {
        vis[vertex] = 1;
        tin[vertex] = ++timer;
        up[vertex][0] = parent;
        data[vertex][0] = valNodes[vertex];

        for (int i = 1; i <= logN; i++)
            up[vertex][i] = up[up[vertex][i - 1]][i - 1],
            data[vertex][i] = max(data[vertex][i - 1], data[up[vertex][i - 1]][i - 1]);

        for (auto child : graph[vertex])
        {
            if (vis[child] == 0)
            {
                height[child] = 1 + height[vertex];
                DFS(graph, child, vertex);
            }
        }

        tout[vertex] = ++timer;
    }

    bool is_ancestor(int parent, int child)
    {
        return (tin[parent] <= tin[child] && tout[parent] >= tout[child]);
    }

    int getLCA(int u, int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;

        for (int i = logN; i >= 0; i--)
        {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }

        return up[u][0];
    }

    int getPthParent(int u, int pTH)
    {
        int parent = u;

        for (int i = logN; i >= 0; i--)
        {
            if ((1ll << (i)) <= pTH)
            {
                parent = up[parent][i];
                pTH -= (1ll << i);
            }
        }

        return parent;
    }

    int edgesBetween(int u, int v)
    {
        int lca = getLCA(u, v);
        int val = abs(height[u] + height[v] - 2 * height[lca]);

        return val;
    }
    int pathQuery(int child, int ancestor)
    {
        int len = log2(height[child] - height[ancestor] + 1);
        int p = height[child] - height[ancestor] + 1 - (1ll << (len));
        int next = getPthParent(child, p);
        return max(data[child][len], data[next][len]);
    }
};
