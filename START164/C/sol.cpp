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
    ll n;
    cin >> n;
    Vec<ll> x(n), y(n);
    for (ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    ll L=0, R=1e12;


    auto cond = [&] (ll mid) {
        DSU d(n);
        for (ll i = 0; i < n; i++) {
            for (ll j = i + 1; j < n; j++) {
                if (max(abs(x[i]-x[j]), abs(y[i] - y[j])) <= mid) {
                    d.unite(i, j);
                }
                if (x[i] == x[j]) {
                    if ((abs(y[i] - y[j]) + 1) / 2 <= mid) {
                        d.unite(i,j);
                    }
                }
                if (y[i] == y[j]) {
                    if ((abs(x[i] - x[j]) + 1) / 2 <= mid) {
                        d.unite(i, j);
                    }
                }
            }
        }
        if (d.size(0) == n) {
            return true;
        }
        return false;
    };

    while (L <= R)
    {
        ll mid = L + (R - L) / 2;
        if (cond(mid)) {
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    
    return L;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
