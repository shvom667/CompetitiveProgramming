#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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

auto solve() {
    ll n; cin >> n; ll a[n]; for (ll i = 0; i < n; i++) cin >> a[i];
    
    DSU d(n);

    vector<pair<ll,ll>> v;
    for (ll i = 0; i < n; i++) {
        ll curh = a[i];
        while (!v.empty() && v.back().first > a[i] ) {
            curh = max(curh, v.back().first);
            d.unite(i, v.back().second);
            v.pop_back();
        }

        v.pb({curh, i});
    }
    vector<ll> b(n, 0);
    for (ll i  = 0; i < n; i++) {
        b[d.get(i)] = max(b[d.get(i)], a[i]);
    }
    for (ll i = 0; i < n; i++) {
        cout << b[d.get(i)] << " ";
    }
    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        // auto res = solve();
        // cout << res << "\n";
        solve();
    }
    return 0;
}
