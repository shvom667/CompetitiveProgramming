#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
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

auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> r(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> r[i];
    }

    dbg(r);

    vector<ll> g[m + 1];
    for (ll i = 1; i <= m; i++) {
        ll sz; cin >> sz;
        if (sz == 0) continue;
        g[i] = vector<ll> (sz);
        for (auto& x : g[i])
            cin >> x;
    }

    vector<ll> d[n + 1];
    for (ll i = 1; i <= m; i++) {
        for (auto x : g[i]) {
            d[x].pb(i);
        }
    }
    for (ll i = 1; i <= n; i++) {
        dbg(d[i]);
    }

    DSU dsu(max(n, m) + 1);

    vector<vector<ll>> opp(max(n, m) + 1);

    for (ll i = 1; i <= n; i++) {
        if (r[i] == 1) {
            dsu.unite(d[i][0], d[i][1]);
        } else {
            opp[d[i][0]].pb(d[i][1]);
            opp[d[i][1]].pb(d[i][0]);
        }
    }
    dbg(opp);


    for (ll i = 1; i <= n; i++) {

        for (ll j = 1; j < (ll) opp[i].size(); j++) {
            dsu.unite(opp[i][j], opp[i][j - 1]);
        }
    }

    bool ok = true;

    for (ll i = 1; i <= n; i++) {
        if (r[i] == 1) {
            if (dsu.same_set(d[i][0], d[i][1])) {
                continue;
            } else {
                ok = false;
            }
        } else {
            if (dsu.same_set(d[i][1], d[i][0])) {
                ok = false;
            } else {
                continue;
                
            }
        }
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
    }
    return 0;
}
