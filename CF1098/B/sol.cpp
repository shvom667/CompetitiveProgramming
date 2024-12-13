#include <bits/stdc++.h>
using namespace std;
using ll = int;
#define pb push_back
template <typename T>
using Vec = vector<T>;

// #define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif
const ll inf = 1e9;
auto solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m));
    
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    // dbg(g);

    if (min(n, m) == 1) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cout << g[i][j];
            }   cout << '\n';
        }
        return;
    }

    vector<Vec<char>> fans_g;
    ll fans_val = inf;

    vector<char> C = {'A','G','C','T'};


    auto get = [&] (vector<vector<char>>& h) {
        ll res = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (g[i][j] != h[i][j]) res++;
            }
        }
        return res;
    };

    for (ll i = 0; i < (ll)C.size(); i++) {
        for (ll j = 0; j < (ll)C.size(); j++) {
            if (i == j)continue;

            vector<vector<char>> cur_g = g;

            ll a, b, c, d; c=-1,d=-1;
            a = i, b = j;
            
            for (ll k = 0; k < 4; k++) {
                if (k == i || k == j) continue;
                if (c == -1) {
                    c = k;
                    continue;
                }
                if (d == -1) {
                    d = k;
                    continue;
                }
            }

            // set<ll> s;s.insert(a);s.insert(b);s.insert(c);s.insert(d);
            // set<ll> id;id.insert(0);id.insert(1);id.insert(2);id.insert(3);
            // assert(s == id);

            // dbg(a,b,c,d);
            
            for (ll col = 0; col < m; col++) {
                if (col & 1) { // a, b
                    ll f1 = 0, f2 = 0;
                    for (ll row = 0; row < n; row++) {
                        if (row&1) {
                            if (g[row][col] == C[a]) f2++;
                            if (g[row][col] == C[b]) f1++;
                        }
                        if (row%2==0) {
                            if (g[row][col] == C[a]) f1++;
                            if (g[row][col] == C[b]) f2++;
                        }
                    }
                    if (f1 >= f2) {
                        for (ll row = 0; row < n; row++) {
                            if (row%2==0) {
                                cur_g[row][col] = C[a];
                            } else {
                                cur_g[row][col] = C[b];
                            }
                        }
                    } else {
                        for (ll row = 0; row < n; row++) {
                            if (row%2==0) {
                                cur_g[row][col] = C[b];
                            } else {
                                cur_g[row][col] = C[a];
                            }
                        }
                    }
                }
                else { // c, d
                    ll f1 = 0, f2 = 0;
                    for (ll row = 0; row < n; row++) {
                        if (row&1) {
                            if (g[row][col] == C[c]) f2++;
                            if (g[row][col] == C[d]) f1++;
                        }
                        if (row%2==0) {
                            if (g[row][col] == C[c]) f1++;
                            if (g[row][col] == C[d]) f2++;
                        }
                    }
                    if (f1 >= f2) {
                        for (ll row = 0; row < n; row++) {
                            if (row%2==0) {
                                cur_g[row][col] = C[c];
                            } else {
                                cur_g[row][col] = C[d];
                            }
                        }
                    } else {
                        for (ll row = 0; row < n; row++) {
                            if (row%2==0) {
                                cur_g[row][col] = C[d];
                            } else {
                                cur_g[row][col] = C[c];
                            }
                        }
                    }
                }

            }  

            // for(auto&x:cur_g){
            //     dbg(x);
            // }
            // exit(0);

            ll cur_res = get(cur_g);
            
            fans_val = min(fans_val, cur_res);
            if (fans_val == cur_res) {
                fans_g = cur_g;
            }
        }
    }

    // dbg(g);
    // dbg(C);

    for (ll i = 0; i < (ll)C.size(); i++) {
        for (ll j = 0; j < (ll)C.size(); j++) {
            if (i == j)continue;

            vector<vector<char>> cur_g = g;

            ll a, b, c, d; c=-1,d=-1;
            a = i, b = j;
            // dbg(i,j);
            for (ll k = 0; k < 4; k++) {
                if (k == i || k == j) continue;
                if (c == -1) {
                    c = k;
                    continue;
                }
                if (d == -1) {
                    d = k;
                    continue;
                }
            }
            // dbg(c,d);

            // set<ll> s;s.insert(a);s.insert(b);s.insert(c);s.insert(d);
            // set<ll> id;id.insert(0);id.insert(1);id.insert(2);id.insert(3);
            // // dbg(s);
            // assert(s == id);

            // dbg(a,b,c,d);
            
            for (ll row = 0; row < n; row++) {
                if (row & 1) { // a, b
                    ll f1 = 0, f2 = 0;
                    for (ll col = 0; col < m; col++) {
                        if (col&1) {
                            if (g[row][col] == C[a]) f2++;
                            if (g[row][col] == C[b]) f1++;
                        }
                        if (col%2==0) {
                            if (g[row][col] == C[a]) f1++;
                            if (g[row][col] == C[b]) f2++;
                        }
                    }
                    if (f1 >= f2) {
                        for (ll col = 0; col < m; col++) {
                            if (col%2==0) {
                                cur_g[row][col] = C[a];
                            } else {
                                cur_g[row][col] = C[b];
                            }
                        }
                    } else {
                        for (ll col = 0; col < m; col++) {
                            if (col%2==0) {
                                cur_g[row][col] = C[b];
                            } else {
                                cur_g[row][col] = C[a];
                            }
                        }
                    }
                }
                else { // c, d
                    ll f1 = 0, f2 = 0;
                    for (ll col = 0; col < m; col++) {
                        if (col&1) {
                            if (g[row][col] == C[c]) f2++;
                            if (g[row][col] == C[d]) f1++;
                        }
                        if (col%2==0) {
                            if (g[row][col] == C[c]) f1++;
                            if (g[row][col] == C[d]) f2++;
                        }
                    }
                    if (f1 >= f2) {
                        for (ll col = 0; col < m; col++) {
                            if (col%2==0) {
                                cur_g[row][col] = C[c];
                            } else {
                                cur_g[row][col] = C[d];
                            }
                        }
                    } else {
                        for (ll col = 0; col < m; col++) {
                            if (col%2==0) {
                                cur_g[row][col] = C[d];
                            } else {
                                cur_g[row][col] = C[c];
                            }
                        }
                    }
                }
            }  

            ll cur_res = get(cur_g);
            fans_val = min(fans_val, cur_res);
            if (fans_val == cur_res) {
                fans_g = cur_g;
            }
        }
    }

    dbg(fans_val);

    for (ll i = 0; i < n; i++) 
    {
        for (ll j = 0; j < m; j++) {
            cout << fans_g[i][j];
        }   cout << '\n';
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
	    // auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
