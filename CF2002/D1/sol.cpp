#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include "../../DataStructures/debug.cpp"
#else
    #define dbg(...) 42

#endif

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq;
    std::vector<std::vector<int>> adj;
    int cur;
    
    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        
        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                std::swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    
    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }
        
        int d = dep[u] - k;
        
        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }
        
        return seq[in[u] - dep[u] + d];
    }
    
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
    
    int rootedParent(int u, int v) {
        std::swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }
    
    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }
    
    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};

auto solve2(auto n, auto q, auto A, auto P, auto Q) {
    
    HLD t(n);
    std::vector<int> a(n), p(n);
    a[0] = -1;
    for (ll i = 1; i < n; i++) {
        a[i] = A[i+1];
    }
    for (int i = 1; i < n; i++) {
        a[i]--;
        t.addEdge(a[i], i);
    }
    t.work();
    
    for (int i = 0; i < n; i++) {
        p[i] = P[i+1];
    }
    for (int i = 0; i < n; i++) {
        p[i]--;
    }
    
    int cnt = 0;
    std::vector<bool> good(n);
    auto check = [&](int i) {
        if (i < 1 || i >= n) {
            return;
        }
        cnt -= good[i];
        good[i] = !t.isAncester(p[i], p[i - 1]) && t.isAncester(a[p[i]], p[i - 1]);
        cnt += good[i];
    };
    for (int i = 1; i < n; i++) {
        check(i);
    }
    Vec<string>res;
    for(auto&[x,y]:Q){
        x--;
        y--;
        std::swap(p[x], p[y]);
        check(x);
        check(x + 1);
        check(y);
        check(y + 1);
        if (cnt == n - 1) {
            res.pb("Yes");
        } else {
            res.pb("No");
        }
    }
    return res;
}

auto solve(ll n, auto q, auto a, auto p, auto Q) {
    
    vector<ll> ord = {0};
    function<void(int)> dfs = [&] (ll i) {
        if (i > n) return;
        ord.pb(i);
        dfs(2 * i);
        dfs(2 * i + 1);
    };

    dfs(1);
    map<ll, ll> mp;
    for (ll i = 1; i <= n; i++) {
        mp[ord[i]] = i;
    }
    Vec<Vec<ll>> ch(n + 1);
    Vec<ll> par(n + 1, -1);
    for (ll i = 2; i <= n; i++) {
        par[i] = mp[ord[i] / 2];
        ch[par[i]].pb(i);
    }
    dbg(ch);
    dbg(par);
    dbg(ord);
    map<ll,ll> rod;
    for(ll i = 1; i <= n; i++) {
        rod[ord[i]] = i;
    }
    vector<ll> ok(n + 1, false);
    for (ll j = n; j >= 1; j--) {
        dbg(ok);
        ll i = rod[j];
        dbg(j,i);
        ok[i] = true;
        for (auto&c : ch[i]) {
            if(i==6){
                dbg(p[i]);
                dbg(c);
                dbg(p[c]);
                dbg(ok[c]);
            }
            ok[i] = (ok[i]&ok[c]);
            if (p[c] / 2 == p[i]) {
                
            } else {
                if(i==6){
                    dbg("hello");
                }
                ok[i] = false;
            }
        }
        if(i==6)
        {
            dbg(ok[i]);
        }
    }
    dbg(ok);
    
    auto update = [&] (ll ind, ll val) {
        
        p[ind] = val;
        while (ind != -1)  {
            ok[ind] = true;
            for (auto&c : ch[ind]) {
                ok[ind] &= ok[c];
                if (p[c] / 2 == p[ind]) {

                } else {
                    ok[ind] = false;
                }
            }
            ind = par[ind];
        }
    };
    Vec<string>res;
    for (auto&[x,y]:Q){
        ll a,b;
        a  = p[x];
        b = p[y];
        update(x, b);
        update(y, a);
        if (ok[1]) {
            res.pb("Yes");
        } else {
            res.pb("No");
        }
    }
    return res;
}



mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}


std::vector<int> generateRandomPermutation(int n) {
    // Create a vector containing elements from 1 to n
    std::vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1;
    }

    // Initialize the Mersenne Twister random number generator
    std::random_device rd;  // Seed with a real random value, if available
    std::mt19937 mt((int) std::chrono::steady_clock::now().time_since_epoch().count());  // Initialize the Mersenne Twister engine

    // Shuffle the vector to get a random permutation
    std::shuffle(permutation.begin(), permutation.end(), mt);

    return permutation;
}
auto bf3(ll n, auto q, auto a, auto p, auto Q) {
    assert(n==3);
    Vec<string>res;
    for(auto&[x,y]:Q){
        swap(p[x],p[y]);
        if(p[1]==1)
            res.pb("Yes");
        else
            res.pb("No");
    }
    return res;
}
auto stress() {
    while (true) 
    {
        ll n, q;
        n = rnd(15, 15);
        q = rnd(1,10);
        Vec<ll>a(n+1);
        for(ll i=2;i<=n;i++)
            a[i]=i/2;
        vector<ll> pd = generateRandomPermutation(n);
        vector<ll> p={0};
        for(auto&v:pd)p.pb(v);
        vector<pair<ll,ll>>Q(q);
        for (ll i=0;i<q;i++)  {
            Q[i].first = rnd(1, n-1);
            Q[i].second = rnd(Q[i].first + 1, n);
        }


        auto sans=solve(n,q,a,p,Q);
        auto bans=solve2(n,q,a,p,Q);
        if (sans == bans) {
            cout << "Ok\n";
        }else{
            cout << "Not Ok\n";
            cout << n << " " << q << "\n";
            for (ll i = 2; i <= n; i++)
                cout << a[i] << " ";
            cout << "\n";
            for (ll i = 2; i <= n; i++)
                cout << p[i] << " ";
            cout << "\n";
            for (auto&[x,y]:Q)
                cout<<x<<" "<<y<<"\n";
            for(auto&s:sans){
                cout<<s<<" ";
            }cout<<"\n";
            for(auto&s:bans){
                cout<<s<<" ";
            }cout<<"\n";
            exit(0);
        }
    }
}

int main() {
    //stress();
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n,q;
        cin>>n>>q;
        vector<ll>a(n+1),p(n+1);
        for(ll i=2;i<=n;i++)cin>>a[i];
        for(ll i=1;i<=n;i++)cin>>p[i];
        vector<pair<ll,ll>> Q(q);
        for(auto&[x,y]:Q)cin>>x>>y;
        auto res=solve(n,q,a,p,Q);
        for(auto&s:res)
            cout<<s<<"\n";
    }
    return 0;
}
