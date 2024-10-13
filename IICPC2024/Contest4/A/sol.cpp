#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CompetitiveProgramming/DataStructures/debug.cpp"
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


auto solve(auto n, auto m, auto w, Vec<ll> x, Vec<ll> y, Vec<ll> rad) {
    DSU d(w);
    for (ll i = 0; i < w; i++) {
        for (ll j = i + 1; j < w; j++) {
            if ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) <= (rad[i]+rad[j])*(rad[i]+rad[j])) {
                d.unite(i,j);
            }
        }
    }
    Vec<ll> max_x(w, -1),min_x(w, 1e5),max_y(w, -1),min_y(w, 1e5);

    for (ll i = 0; i < w; i++) {
        ll p = d.get(i);
        dbg(p);
        max_x[p] = max(max_x[p], x[i]+rad[i]);
        max_y[p] = max(max_y[p], y[i]+rad[i]);
        min_x[p] = min(min_x[p], x[i]-rad[i]);
        min_y[p] = min(min_y[p], y[i]-rad[i]);
    }
    dbg(w);
    for (ll i = 0; i < w; i++) {
        ll p = d.get(i);
        dbg(p, max_x[p],min_x[p],max_y[p],min_y[p]);
    }
    bool ok=false;
    for (ll i = 0; i < w; i++) {
        if(max_x[i] >= n && min_x[i]<=0){
            ok=true;
        }
        if(max_y[i] >= m && min_y[i]<=0){
            ok=true;
        }
        if(max_y[i] >= m && max_x[i]>=n){
            ok=true;
        }
        if(min_y[i] <= 0 && min_x[i]<=0){
            ok=true;
        }
    }
    dbg(ok);
    string res;
    if (ok) {
        res="N";
    }else{
        res="S";
    }
    return res;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll T;
    T=1;
    for (ll tc = 1; tc <= T; tc++) {
        ll n, m, w;
        cin >> n >> m >> w;
        vector<ll> x(w),y(w),r(w);
        for(ll i = 0; i < w; i++) {
            cin >> x[i] >> y[i] >> r[i];
        }
        auto res = solve(n, m, w, x, y, r);
        cout << res << "\n";
    }
    return 0;
}
