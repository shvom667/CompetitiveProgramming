#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max

struct DSU{
    std::vector<int> par, sz;
    int n;

    DSU() {}
    DSU(int _n) { init(_n); }
    void init(int _n) {
        n = _n;
        sz.assign(n, 1);
        par.assign(n, 0);
        std::iota(par.begin(), par.end(), 0);
    }

    void join(int x, int y) {
        int xr = root(x), yr = root(y);
        if(xr == yr) return;

        if(sz[xr] < sz[yr]) swap(xr, yr);
        par[yr] = xr;
        sz[xr] += sz[yr];
    }

    int root(int x){ //Uses path splitting.
        while(par[x] != x) {
            int prev = x;
            x = par[x];
            par[prev] = par[x];
        }
        return x;
    }

    bool together(int x, int y) {return root(x) == root(y);}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    t = 1;
    forn(ti, t) {
        int n, m, k; cin >> n >> m >> k;
        vector<pair<pii, int>> v(k); //constraints.
        forn(i, k) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int x = (x1 + x2) / 2 - 1;
            int y = (y1 + y2) / 2 - 1;
            if(y2 == y1 + 1) {
                v[i] = {{x, n + y}, 1};
            } else {
                v[i] = {{x, n + y}, 0};
            }
        }

        // constraints are of the form {{x, y}, b} means that x + y = b mod 2
        // tell whether or not it has a solution with dfs
        vector<vector<pair<int, int>>> adj(n + m);
        for(auto p : v) {
            int x = p.f.f, y = p.f.s, b = p.s;
            assert(x < n + m && y < n + m);
            adj[x].pb({y, b});
            adj[y].pb({x, b});
        }
        vector<int> color(n + m, -1);
        bool works = true;
        function<void(int, int)> dfs = [&](int u, int p) {
            for(auto v : adj[u]) {
                if(v.f == p) continue;
                if(color[v.f] == -1) {
                    color[v.f] = color[u] ^ v.s;
                    dfs(v.f, u);
                } else {
                    if (color[v.f] != (color[u] ^ v.s)) {
                        works = false;
                    }
                }
            }
        };
        forn(i, n+m) {
            if(color[i] == -1) {
                color[i] = 0;
                dfs(i, -1);
            }
        }
        if(works) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
