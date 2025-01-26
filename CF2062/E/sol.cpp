# include <iostream>
# include <vector>
# include <algorithm>
# include <queue>
using namespace std;

struct Node {
    int value;
    vector<int> children;
};

bool dfs(int node, int parent, const vector<Node>& tree, vector<int>& canWin) {
    bool hasLosingChild = false;
    for (int child : tree[node].children) {
        if (child == parent) continue;
        hasLosingChild |= dfs(child, node, tree, canWin);
    }
    canWin[node] = !hasLosingChild;
    return canWin[node];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<Node> tree(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> tree[i].value;
        }

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].children.push_back(v);
            tree[v].children.push_back(u);
        }

        vector<int> canWin(n + 1, 0);
        dfs(1, -1, tree, canWin);

        bool cirnoCanWin = false;
        for (int i = 1; i <= n; ++i) {
            if (canWin[i]) {
                cirnoCanWin = true;
                cout << i << "\n";
                break;
            }
        }

        if (!cirnoCanWin) {
            cout << "0\n";
        }
    }

    return 0;
}