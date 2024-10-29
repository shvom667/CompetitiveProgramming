#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    // cin >> tt;
    tt = 1;
    
    while (tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<pair<int, int>>> adj(n + m);
        for (int j = 0; j < k; j++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--;y1--;x2--;y2--;

            adj[min(x1, x2)].push_back({n + min(y1, y2), (x1+y1 != x2 + y2)});
            adj[n + min(y1, y2)].push_back({min(x1, x2), (x1+y1 != x2 + y2)});
        }
        
        vector<int> color(n+m, -1);

        function<void(int, int)> dfs = [&] (int i, int c) {
            if (color[i] != -1) return;
            color[i] = c;
            for (auto& [ch, x] : adj[i]) {
                if (color[ch] == -1) {
                    dfs(ch, c ^ x); 
                } 
            }
        };
        
        for (int i = 0; i < n + m; i++) {
            if (color[i] == -1) {
                dfs(i, 0);
            }
        }

        bool ok = true;
        for (int i = 0; i < n + m; i++) {
            for (auto [j, x] : adj[i]) {
                if (color[i] != (color[j] ^ x)) {
                    ok = false;
                }
            }
        }

        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
}