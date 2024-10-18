#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    // #include"/home/shivom/Downloads/CP/DataStructures/dsu.cpp"
#else
    #define dbg(...) 42
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


 
auto solve(ll n, vector<ll> a) {
    map<ll, vector<ll>> mp1, mp2;
    for (ll i = 0; i < n; i++) {
        mp1[i + a[i]].pb(i);
        mp2[i - a[i]].pb(i);
    }    
    DSU d(n);
    for (auto& [u, v] : mp1) {
        for (ll i = 1; i < (ll)v.size(); i++) {
            d.unite(v[i], v[i-1]);
        }
    }
    for (auto& [u, v] : mp2) {
        for (ll i = 1; i < (ll)v.size(); i++) {
            d.unite(v[i], v[i-1]);
        }
    }

    map<ll, vector<ll>> mp;
    for (ll i = 0; i < n; i++) {
        mp[d.get(i)].pb(i);
    }
    bool ok = true;
    for (auto& [u, v] : mp) {
        if (((ll)v.size()) & 1) 
            ok = false;
    }
    if (!ok) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for (auto&[u, v] : mp) {
        for (ll i = 0; i < (ll)v.size(); i+= 2) {
            cout << v[i] + 1 << " " << v[i + 1] + 1 << "\n";
        }
    }
    // return "$$$$$$$$$$$$$$";
}

auto bf(ll n, vector<ll> a) {
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            if (abs(a[i] - a[j]) == abs(i - j)) {
                dbg(i, j);
            }
        }
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(n, a);
        // cout << res << "\n";
    }
    return 0;
}
