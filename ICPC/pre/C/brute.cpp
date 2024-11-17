#include <bits/stdc++.h>

using namespace std;
using ll = int;

// =================

// Debugging template
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A>
void __print(const A &x);
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename... A>
void __print(const tuple<A...> &t);
template <typename T>
void __print(stack<T> s);
template <typename T>
void __print(queue<T> q);
template <typename T, typename... U>
void __print(priority_queue<T, U...> q);
/*
void __print(Mint x) {
	cerr << x;
}
*/
template <typename A>
void __print(const A &x) {
	bool first = true;
	cerr << '{';
	for (const auto &i : x) {
		cerr << (first ? "" : ","), __print(i);
		first = false;
	}
	cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p) {
	cerr << '(';
	__print(p.first);
	cerr << ',';
	__print(p.second);
	cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t) {
	bool first = true;
	cerr << '(';
	apply([&first](const auto & ...args) { ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
	cerr << ')';
}
template <typename T>
void __print(stack<T> s) {
	vector<T> debugVector;
	while (!s.empty()) {
		T t = s.top();
		debugVector.push_back(t);
		s.pop();
	}
	reverse(debugVector.begin(), debugVector.end());
	__print(debugVector);
}
template <typename T>
void __print(queue<T> q) {
	vector<T> debugVector;
	while (!q.empty()) {
		T t = q.front();
		debugVector.push_back(t);
		q.pop();
	}
	__print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q) {
	vector<T> debugVector;
	while (!q.empty()) {
		T t = q.top();
		debugVector.push_back(t);
		q.pop();
	}
	__print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
	__print(H);
	if (sizeof...(T))
		cerr << ", ";
	_print(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dbg(...)
#endif

// =================

// Structure to represent an edge
struct Edge {
    int u, v;       // Nodes u and v
    long long weight; // Weight of the edge
};

// Comparator for sorting edges
bool compare(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Union-Find (Disjoint Set) functions
class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};

long long computeMST(int n, const vector<int>& x, const vector<int>& a) {
    vector<Edge> edges;

    // Generate all edges and their weights
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long weight = (long long)min(a[i], a[j]) * abs(x[i] - x[j]);
            edges.push_back({i, j, weight});
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compare);

    // Kruskal's algorithm
    UnionFind uf(n);
    long long mstWeight = 0;
    int edgesUsed = 0;

    for (const Edge& edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            mstWeight += edge.weight;
            edgesUsed++;
            if (edgesUsed == n - 1) break;
        }
    }

    return mstWeight;
}


int main(int argc, char** argv) {

    int n;
    cin>>n;



    vector<int> x(n), a(n);
    // Input positions and costs

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    // Compute the MST weight
 //   dbg(n, a, x);
    ll ans = computeMST(n, x, a);
    
    cout << ans << '\n';

    return 0;

}
