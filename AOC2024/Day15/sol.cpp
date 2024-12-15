#include<bits/stdc++.h>
using ll = int;
using namespace std;
#define pb push_back

#include"../../DataStructures/debug.cpp"

int n, m;
vector<vector<char>> g, h;
vector<char> moves;

int rx = -1, ry = -1;

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < 2 * n && h[x][y] == '.';
}


auto print(auto h) {

    for (ll i = 0; i < n; i++) {
        for (auto&x : h[i]) {
            cout << x;
        }   cout << '\n';
    }
}


auto get_new_grid(vector<vector<char>> g) {
    vector<vector<char>> h(n);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (g[i][j] == '#') {
                h[i].pb('#');
                h[i].pb('#');
            }
            if (g[i][j] == 'O') {
                h[i].pb('[');
                h[i].pb(']');
            }
            if (g[i][j] == '.') {
                h[i].pb('.');
                h[i].pb('.');
            }
            if (g[i][j] == '@') {
                h[i].pb('@');
                h[i].pb('.');
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 2 * n; j++) {
            if (h[i][j] == '@') {
                rx = i;
                ry = j;
            }
        }
    }

    // print(h);
    return h;
}
int main() {
    cin >> n;
    g.resize(n, vector<char>(n, 'a'));

    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j) {
            g[i][j] = row[j];
            if (g[i][j] == '@') {
                rx = i;
                ry = j;
            }
        }
    }

    cin >> m;
    moves.resize(m);

    h = get_new_grid(g);


    for (int i = 0; i < m; ++i) {
        cin >> moves[i];
    }


    auto make_move_up = [&] () {
        vector<vector<bool>> affected(n, vector<bool> (2 * n, false));
        affected[rx][ry] = true;
        for (ll i = rx - 1; i >= 0; i--) {
            for (ll j = 0; j < 2 * n; j++) {
                if (h[i][j] == '#' || h[i][j] == '.') continue;
                if (affected[i + 1][j] == true) {
                    affected[i][j] = true;
                    if (h[i][j] == ']') {
                        affected[i][j - 1] = true;
                    }
                    if (h[i][j] == '[') {
                        affected[i][j + 1] = true;
                    }
                }
            }
        }
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < 2 * n; j++) {
                if (affected[i][j] && h[i - 1][j] == '#') { // up is either [] or .
                    return;
                }
            }
        }

        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < 2 * n; j++) {
                if (affected[i][j]) {
                    h[i - 1][j] = h[i][j];
                    h[i][j] = '.';
                }
            }
        }
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < 2 * n; j++) {
                if (h[i][j] == '@') {
                    rx = i;
                    ry = j;
                }
            }
        }
        
    };
    auto make_move_down = [&] () {
        vector<vector<bool>> affected(n, vector<bool> (2 * n, false));
        affected[rx][ry] = true;



        for (ll i = rx + 1; i < n; i++) {
            for (ll j = 0; j < 2 * n; j++) {
                if (h[i][j] == '#' || h[i][j] == '.') continue;
                if (affected[i - 1][j] == true) {
                    affected[i][j] = true;
                    if (h[i][j] == ']') {
                        affected[i][j - 1] = true;
                    }
                    if (h[i][j] == '[') {
                        affected[i][j + 1] = true;
                    }
                }
            }
        }

        // for(ll i=0;i<n;i++){
        //     for(auto x:affected[i]){
        //         cout<<x;
        //     }   cout<<'\n';
        // }

        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < 2 * n; j++) {
                if (affected[i][j] && h[i + 1][j] == '#') { // up is either [] or .
                    return;
                }
            }
        }

        for (ll i = n - 2; i >= 0; i--) {
            for (ll j = 0; j < 2 * n; j++) {
                if (affected[i][j]) {
                    // dbg(i, j);
                    h[i + 1][j] = h[i][j];
                    h[i][j] = '.';
                }
            }
        }
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < 2 * n; j++) {
                if (h[i][j] == '@') {
                    rx = i;
                    ry = j;
                }
            }
        }
        
    };

    for (ll k = 0; k < m; k++) {
        if (moves[k] == '^') {
            make_move_up();
        }
        if (moves[k] == 'v') {
            make_move_down();
        }
        if (moves[k] == '<') {
            ll bx = -1, by = -1;
            for (ll j = ry; j >= 0; j--) {
                if (h[rx][j] == '#') {
                    bx = rx;
                    by = j;
                    break;
                }
                if (h[rx][j] == '.') {
                    bx = rx;
                    by = j;
                    break;
                }
            }
            if (ok(bx, by)) {
                for (ll j = by; j <= ry - 1; j++) {
                    h[rx][j] = h[rx][j + 1];
                }
                h[rx][ry] = '.';
                rx = rx;
                ry = ry - 1;
            }
        }
        if (moves[k] == '>') {
            ll bx = -1, by = -1;
            for (ll j = ry; j < 2 * n; j++) {
                if (h[rx][j] == '#') {
                    bx = rx;
                    by = j;
                    break;
                }
                if (h[rx][j] == '.') {
                    bx = rx;
                    by = j;
                    break;
                }
            }
            // dbg(bx, by);
            if (ok(bx, by)) {
                for (ll j = by; j >= ry + 1; j--) {
                    h[rx][j] = h[rx][j - 1];
                }
                h[rx][ry] = '.';
                rx = rx;
                ry = ry + 1;
            }

        }

        // print(h);
    }

    // print(h);
    

    int res = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            if (h[i][j] == '[') {
                res += 100 * i + j;
            }
        }
    }

    cout << res << endl;

    return 0;
}
