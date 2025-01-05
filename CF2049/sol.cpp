#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define int long long

const int INF = 1e18;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> g(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }

    vector<vector<vector<int>>> s(n, vector<vector<int>>(m, vector<int>(m + 1, 0)));

    for (int l = 1; l <= m; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                s[i][j][l] = s[i][j][l - 1] + g[i][(j + l - 1) % m];
            }
        }
    }

    for (int l = 0; l <= m; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                s[i][j][l] += j * k;
            }
        }
    }

    auto sp = s, ss = s;

    for (int l = 0; l <= m; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                sp[i][j][l] = min(sp[i][j][l], sp[i][j - 1][l]);
            }
        }
    }

    for (int l = 0; l <= m; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = m - 2; j >= 0; --j) {
                ss[i][j][l] = min(ss[i][j][l], ss[i][j + 1][l]);
            }
        }
    }

    vector<vector<vector<long long>>> f(n, vector<vector<long long>>(m, vector<long long>(m + 1, INF)));

    for (int l = 0; l <= m; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                f[i][j][l] = min(f[i][j][l], -k * j + ss[i][j][l]);
                if (j - 1 >= 0) {
                    f[i][j][l] = min(f[i][j][l], -k * j + m * k + sp[i][j - 1][l]);
                }
            }
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(m, INF));

    for (int j = 0; j < m; ++j) {
        dp[0][j] = f[0][0][j + 1];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int l = 0; l <= j; ++l) {
                dp[i][j] = min(dp[i][j], dp[i - 1][l] + f[i][l][j - l + 1]);
            }
        }
    }

    cout << dp[n - 1][m - 1] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
