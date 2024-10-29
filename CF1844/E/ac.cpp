#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
 
// ============

struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }
    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool same_set(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

// ============


struct Slant
{
    ll Type, Row, Col;
    ll x1, y1, x2, y2;
};

Slant read() {
    Slant s;
    cin >> s.x1 >> s.y1 >> s.x2 >> s.y2;

    if ( (s.y2 - s.y1) / (s.x2 - s.x1) == -1) {
        s.Type = 1;
        s.Row = min(s.x1, s.x2);
        s.Col = max(s.y1, s.y2);
        if (s.y1 > s.y2) {

        } else {
            swap(s.x1, s.x2);
            swap(s.y1, s.y2);
        }
    } else {
        s.Type = 2;
        s.Row = min(s.x1, s.x2);
        s.Col = max(s.y1, s.y2);
        if (s.y1 > s.y2) {

        } else {
            swap(s.x1, s.x2);
            swap(s.y1, s.y2);
        }
    }
    return s;
}

void print(Slant s) {
    cout <<  s.Type << " " <<  s.Row << " " << s.Col << "\n";
}

ll Test = 0;


auto solve() {
    
    ll n, m, k;
    cin >> n >> m >> k;


    vector<Slant> in(k);

    for (ll i = 0; i < k; i++) {
        in[i] = read();
    }

    

    
    DSU d(n + 1);

    Vec<vector<ll>> adj(n, vector<ll>());

    vector<bool> in_rows(n, false);
    vector<pair<ll, ll>> same_grp, diff_grp;

    for (ll i = 0; i < k; i++) {
        for (ll j = i + 1; j < k; j++) {
            if (in[i].Col == in[j].Col) {
                if (in[i].Type == in[j].Type) {
                    d.unite(in[i].Row, in[j].Row);
                    same_grp.pb({in[i].Row, in[j].Row});
                    // in_rows[in[i].Row - 1] = true;
                    // in_rows[in[j].Row - 1] = true;
                } else {
                    in_rows[in[i].Row - 1] = true;
                    in_rows[in[j].Row - 1] = true;
                    diff_grp.pb({in[i].Row, in[j].Row});
                    adj[in[i].Row - 1].pb(in[j].Row - 1);
                    adj[in[j].Row - 1].pb(in[i].Row - 1);
                    // cout << in[i].Row << " " << in[j].Row << "\n";
                }
            }
        }
    }


    Vec<ll> color(n, -1);
    Vec<ll> dfs_itr(n, -1);
    ll jadoo = 0;

    dbg(same_grp);
    dbg(diff_grp);

    function<void(int, int)> dfs = [&] (int i, int p) {
        dfs_itr[i] = jadoo;
        for (auto& ch : adj[i]) {
            if (color[ch] == -1) {
                color[ch] = color[i] ^ 1;
                dfs(ch, i);
            }
        }
    };
    dbg(in_rows);

    for (ll i = 0; i < n; i++) {
        if (color[i] == -1 && in_rows[i]) {
            dbg(i);
            color[i] = 0;
            dfs(i, -1);
            jadoo++;
        }
    }

    // dbg(d.get(1));
    // dbg(d.get(2));
    // dbg(d.get(5));
    // dbg(d.get(8));
    // dbg(color[2 - 1], color[7-1]);


    // dbg(color);

    for (ll i = 0; i < n; i++) {
        for (auto& u : adj[i]) {
            if (color[u] == -1) continue;
            
            if (color[u] == color[i]) {
                string res = "NO";
                return res;
            }
            
        }
    }
    dbg("hello");

    dbg(color);

    for (auto [x,y]: same_grp) {
        if (color[x - 1] == -1 || color[y - 1] == -1) continue;
        if (dfs_itr[x - 1] != dfs_itr[y - 1]) continue;
        if (color[x - 1] != color[y - 1]) {
            dbg(x, y);
            string res = "NO";
            return res;
        }
    }
    dbg("hello");

    string res = "YES";

    for (ll i = 0; i < k; i++) {
        for (ll j = i + 1; j < k; j++) {
            if (in[i].Col == in[j].Col) {
                if (in[i].Type != in[j].Type) {
                    if (abs(in[i].x1 - in[j].x1) == 1 && abs(in[i].x2 - in[j].x2) == 1) 
                    {
                        res = "NO";
                    }
                }
            }
        }
    }

    for (ll i = 0; i < k; i++) {
        for (ll j = i + 1; j < k; j++) {
            if (in[i].Col == in[j].Col) {
                if (in[i].Type != in[j].Type) {
                    if (d.same_set(in[i].Row, in[j].Row)) {
                        res = "NO";
                    }
                }
                if (in[i].Type == in[j].Type) {
                    if (!d.same_set(in[i].Row, in[j].Row)) {
                        res = "NO";
                    }
                }
            }
        }
    }

    return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        Test++;
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
