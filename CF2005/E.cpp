#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
// Debugging template
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A>
void __print(const A &x);
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename... A>
void __print(const tuple<A...> &t);
template <typename T>
void __print(stack<T> s);
template <typename T>
void __print(queue<T> q);
template <typename T, typename... U>
void __print(priority_queue<T, U...> q);
/*
void __print(Mint x) {
    cerr << x;
}
*/
template <typename A>
void __print(const A &x) {
    bool first = true;
    cerr << '{';
    for (const auto &i : x) {
        cerr << (first ? "" : ","), __print(i);
        first = false;
    }
    cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p) {
    cerr << '(';
    __print(p.first);
    cerr << ',';
    __print(p.second);
    cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t) {
    bool first = true;
    cerr << '(';
    apply([&first](const auto & ...args) { ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
    cerr << ')';
}
template <typename T>
void __print(stack<T> s) {
    vector<T> debugVector;
    while (!s.empty()) {
        T t = s.top();
        debugVector.push_back(t);
        s.pop();
    }
    reverse(debugVector.begin(), debugVector.end());
    __print(debugVector);
}
template <typename T>
void __print(queue<T> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.front();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.top();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
    __print(H);
    if (sizeof...(T))
        cerr << ", ";
    _print(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dbg(...)
#endif

ll gcd(ll x, ll y) {
    if (x == 0 || y == 0) return max(x, y);
    return __gcd(x,y);
}
ll lcm(ll x, ll y) {
    ll g = gcd(x, y);
    if (x == 0 || y == 0) return max(x,y);
    return (x*y)/gcd(x,y);
}
pair<ll, ll> solve(ll n, vector<ll> a, vector<ll> b) {
    ll fans = -1;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) {
        for (ll j = i; j < n; j++) {
            vector<ll> u = a, v = b;
            for (ll k = i; k <= j; k++) {
                swap(u[k], v[k]);
            }
            ll g1 = 0, g2 = 0;
            for (ll k = 0; k < n; k++) {
                g1 = gcd(g1, u[k]);
                g2 = gcd(g2, v[k]);
            }
            mp[g1 + g2]++;
            fans = max(fans, g1 + g2);
        }
    }
    return {fans, mp[fans]};
}


pair<ll, ll> genius(ll n, vector<ll> a, vector<ll> b) {
    vector<ll> ga, gb;
    ga = a, gb = b;
    set<ll> ind;
    ind.insert(0);
    ind.insert(n-1);
    for (ll i = 1; i < n; i++) {
        ga[i] == gcd(a[i], ga[i-1]);
        if (ga[i] < ga[i-1]) {
            ind.insert(i);
        }
    }
    for (ll i = 1; i < n; i++) {
        gb[i] == gcd(b[i], gb[i-1]);
        if (gb[i] < gb[i-1]) {
            ind.insert(i);
            ind.insert(i-1);
        }
    }

    vector<vector<ll>> g(30, vector<ll> (n));
    for (ll i = 0; i < 30; i++)
        for (ll j = 0; j < n; j++) 
            g[i][j] = 0;
 
    for (ll j = 0; j < n; j++) {
        g[0][j] = a[j];
    }
    for (ll i = 1; i < 30; i++) {
        for (ll j = 0; j < n; j++) {
            g[i][j] = gcd(g[i-1][min(n-1, j)], g[i-1][min(n-1, j + (1ll<<i-1))]);
        }
    }
 
    auto querya = [&] (ll l, ll r) {
        if (r < 0) {
            return 0ll;
        }
        if (l >= n) {
            return 0ll;
        }
        if (r == l) {
            return a[l];
        }
        ll g2 = log2(r-l);

        return gcd(g[g2][l], g[g2][r-(1ll<<g2)+1]);
    };

    vector<vector<ll>> t(30, vector<ll> (n));
    for (ll i = 0; i < 30; i++)
        for (ll j = 0; j < n; j++) 
            t[i][j] = 0;
 
    for (ll j = 0; j < n; j++) {
        t[0][j] = b[j];
    }
    for (ll i = 1; i < 30; i++) {
        for (ll j = 0; j < n; j++) {
            t[i][j] = gcd(t[i-1][min(n-1, j)], t[i-1][min(n-1, j + (1ll<<i-1))]);
        }
    }
 
    auto queryb = [&] (ll l, ll r) {
        if (r < 0) {
            return 0ll;
        }
        if (l >= n) {
            return 0ll;
        }
        if (r == l)
            return b[r];
        ll t2 = log2(r-l);
        return gcd(t[t2][l], t[t2][r-(1ll<<t2)+1]);
    };

    map<ll, ll> mp;
    ll fans = querya(0, n-1) + queryb(0, n-1);
    ll org = fans;
    dbg(ind);
    vector<ll> u(begin(ind),end(ind));
    dbg(u);
    for (ll ii = 0; ii < (ll)u.size(); ii++) {
        for (ll jj = ii; jj < (ll)u.size(); jj++) {
            ll i, j;
            i = u[ii];
            j = u[jj];
            ll g1=0, g2=0;
            g1 = gcd(g1, querya(0,i-1));
            g1 = gcd(g1, querya(j+1, n-1));
            g1 = gcd(g1, queryb(i, j));

            g2 = gcd(g2, queryb(0,i-1));
            g2 = gcd(g2, queryb(j+1, n-1));
            g2 = gcd(g2, querya(i, j));
            mp[g1+g2]++;
            dbg(i, j, g1, g2, g1 + g2);
            
        }
    }
    for (auto&[u,v]:mp) {
        fans = max(fans, u);
    }
    if (fans > org) {
        dbg("hello");
        return {fans, mp[fans]};
    }
    if (querya(0, n-1) == queryb(0, n-1)) {
        return {fans, (n * (n + 1)) / 2};
    }
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        ll l = i, r = n - 1;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            auto cond = [&] (ll mid) {
                ll g1 = querya(i ,mid);
                ll g2 = queryb(i, mid);
                return (g1%queryb(0,n-1) == 0 && g2 % querya(0,n-1) == 0);
            };
            if (cond(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        res += (r - i + 1);
    }
    ll res1 = 0;
    ll L = lcm(querya(0, n-1), queryb(0, n-1));
 
    ll s, e;
    e = n;
    s = -1;
    
    for (ll i = 0; i < n; i++) {
        if (querya(0,i) % L == 0 && queryb(0, i) % L == 0) {
            s = i;
        }
    }
    for (ll i = n - 1; i >= 0; i--) {
        if (queryb(i, n-1) % L == 0 && querya(i, n - 1) % L == 0) {
            e = i;
        }
    }
    
    if (s >= e) {
        res1 += 1;
    } else {
        res1 += (s + 2) * (n - e + 1);
    }
    
    dbg(s,e);
    dbg(res,res1);
    return {fans, res+res1};
    // return {fans, 1 + res + (querya(0,n-1)==queryb(0,n-1)?-1ll:0ll)};
    // return {fans, res + mp[fans]};
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    auto stress = [&] () {
        while (true) {

            ll MOD = 5;
            ll n = rand()% MOD + 2;
            vector<ll> a(n), b(n);
            for (ll i = 0; i < n; i++) {
                a[i] = rand() % MOD + 1;
                b[i] = rand() % MOD + 1;
            }
            auto bans = solve(n, a, b);
            auto sans = genius(n, a, b);
            
            if (bans != sans) {
                dbg(n, a, b);
                dbg(bans);
                dbg(sans);
                exit(0);
            }
        }
    };
    stress();   

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> b[i];
        }
        auto bans = solve(n, a, b);
        auto sans = genius(n, a, b);
        assert(bans.first == sans.first);

        dbg(bans,sans);
        assert(bans == sans);            
    }




}

/*
1
2 
5 5
3 5

Wrong solution the problem is 2500
*/