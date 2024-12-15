#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<vector<string>> g;
vector<char> moves;

int rx = -1, ry = -1;

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && g[x][y] == "..";
}

int main() {
    cin >> n;
    g.resize(n, vector<string>(n, ""));

    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j) {
            if (row[j] == '#') g[i][j] = "##";
            else if (row[j] == 'O') g[i][j] = "[]";
            else if (row[j] == '.') g[i][j] = "..";
            else if (row[j] == '@') {
                g[i][j] = "@.";
                rx = i;
                ry = j;
            }
        }
    }

    cin >> m;
    moves.resize(m);

    for (int i = 0; i < m; ++i) {
        cin >> moves[i];
    }

    for (int k = 0; k < m; ++k) {
        int bx = -1, by = -1;

        if (moves[k] == '<') {
            for (int j = ry; j >= 0; --j) {
                if (g[rx][j] == "##") {
                    bx = rx;
                    by = j;
                    break;
                }
                if (g[rx][j] == "[]") {
                    continue;
                }
                if (g[rx][j] == "..") {
                    bx = rx;
                    by = j;
                    break;
                }
            }
            if (ok(bx, by)) {
                g[bx][by] = "[]";
                g[rx][ry] = "..";
                g[rx][ry - 1] = "@.";
                ry = ry - 1;
            }
        }

        if (moves[k] == '>') {
            for (int j = ry; j < n; ++j) {
                if (g[rx][j] == "##") {
                    bx = rx;
                    by = j;
                    break;
                }
                if (g[rx][j] == "[]") {
                    continue;
                }
                if (g[rx][j] == "..") {
                    bx = rx;
                    by = j;
                    break;
                }
            }
            if (ok(bx, by)) {
                g[bx][by] = "[]";
                g[rx][ry] = "..";
                g[rx][ry + 1] = "@.";
                ry = ry + 1;
            }
        }

        if (moves[k] == '^') {
            for (int i = rx; i >= 0; --i) {
                if (g[i][ry] == "##") {
                    bx = i;
                    by = ry;
                    break;
                }
                if (g[i][ry] == "[]") {
                    continue;
                }
                if (g[i][ry] == "..") {
                    bx = i;
                    by = ry;
                    break;
                }
            }
            if (ok(bx, by)) {
                g[bx][by] = "[]";
                g[rx][ry] = "..";
                g[rx - 1][ry] = "@.";
                rx = rx - 1;
            }
        }

        if (moves[k] == 'v') {
            for (int i = rx; i < n; ++i) {
                if (g[i][ry] == "##") {
                    bx = i;
                    by = ry;
                    break;
                }
                if (g[i][ry] == "[]") {
                    continue;
                }
                if (g[i][ry] == "..") {
                    bx = i;
                    by = ry;
                    break;
                }
            }
            if (ok(bx, by)) {
                g[bx][by] = "[]";
                g[rx][ry] = "..";
                g[rx + 1][ry] = "@.";
                rx = rx + 1;
            }
        }
    }

    int res = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] == "[]") {
                res += 100 * i + j;
            }
        }
    }

    cout << res << endl;

    return 0;
}
