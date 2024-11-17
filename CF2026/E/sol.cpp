#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
vector<vector<int>> g;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

signed main() {
    //... reading the graph ...

    int tt;
    cin >> tt;
    while (tt--) {

        int N; cin >> N; int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

        n = 60 + N;
        g = vector<vector<int>> (n);
        k = 0;

        for (int i = 0; i < N; i++) {
            for (int b = 0; b < 60; b++) {
                if ((A[i] && (1ll << b)) == 0) continue;
                g[b].push_back(i);
                g[i].push_back(b);
                k++;
            }
        }

        mt.assign(k, -1);
        for (int v = 0; v < n; ++v) {
            used.assign(n, false);
            try_kuhn(v);
        }
        int cnt = 0;
        for (int i = 0; i < k; ++i)
            if (mt[i] != -1) {
                printf("%d %d\n", mt[i] + 1, i + 1);
                cnt++;
            }

        cout << cnt << "\n";
        g.clear();
    }
}
