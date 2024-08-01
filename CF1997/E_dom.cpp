#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
#define int long long
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<bool> ans(q);
    std::vector<std::vector<std::pair<int, int>>> ask(n + 1);
    for (int j = 0; j < q; j++) {
        int i, x;
        std::cin >> i >> x;
        i--;
        ask[x].emplace_back(i, j);
    }
    
    for (int k = 1; k <= n; k++) {
        std::sort(ask[k].begin(), ask[k].end());
    }
    
    std::vector<int> pos(n + 1);
    std::vector<int> cur(n + 1);
    
    Fenwick<int> fen(n);
    std::vector<std::vector<int>> vec(n + 1);
    for (int i = 0; i < n; i++) {
        vec[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        fen.add(i, 1);
    }
    
    for (int t = 1; t <= n; t++) {
        for (int k = 1; k <= n && n > k * (t - 1); k++) {
            if (pos[k] == n) {
                continue;
            }
            int npos = fen.select(fen.sum(pos[k]) + k);
            int &i = cur[k];
            while (i < ask[k].size() && ask[k][i].first < npos) {
                auto [x, j] = ask[k][i];
                ans[j] = (a[x] >= t);
                i++;
            }
            pos[k] = npos;
        }
        for (auto i : vec[t]) {
            fen.add(i, -1);
        }
    }
    
    for (int i = 0; i < q; i++) {
        std::cout << (ans[i] ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
