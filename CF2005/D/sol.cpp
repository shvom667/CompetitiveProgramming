//#define ONLINE_JUDGE
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

using namespace std;
using ll = int;
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
void __print(const A &x)
{
    bool first = true;
    cerr << '{';
    for (const auto &i : x)
    {
        cerr << (first ? "" : ","), __print(i);
        first = false;
    }
    cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p)
{
    cerr << '(';
    __print(p.first);
    cerr << ',';
    __print(p.second);
    cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t)
{
    bool first = true;
    cerr << '(';
    apply([&first](const auto &...args)
          { ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
    cerr << ')';
}
template <typename T>
void __print(stack<T> s)
{
    vector<T> debugVector;
    while (!s.empty())
    {
        T t = s.top();
        debugVector.push_back(t);
        s.pop();
    }
    reverse(debugVector.begin(), debugVector.end());
    __print(debugVector);
}
template <typename T>
void __print(queue<T> q)
{
    vector<T> debugVector;
    while (!q.empty())
    {
        T t = q.front();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q)
{
    vector<T> debugVector;
    while (!q.empty())
    {
        T t = q.top();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T)
{
    __print(H);
    if (sizeof...(T))
        cerr << ", ";
    _print(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...)                                                    \
    cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; \
    _print(__VA_ARGS__)
#else
#define dbg(...)
#endif

// ============
// int log2v(unsigned long long i) {
//     return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
// }

const ll INF = -2e9;
template <class T, class U>
// T -> node, U->update.
struct Lsegtree
{
    vector<T> st;
    vector<U> lazy;
    ll n;
    T identity_element;
    U identity_update;
    Lsegtree(ll n, T identity_element, U identity_update)
    {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4 * n, identity_element);
        lazy.assign(4 * n, identity_update);
    }
    T combine(T l, T r)
    {
        // change this function as required.
        T ans = (l + r);
        return ans;
    }
    void buildUtil(ll v, ll tl, ll tr, vector<T> &a)
    {
        if (tl == tr)
        {
            st[v] = a[tl];
            return;
        }
        ll tm = (tl + tr) >> 1;
        buildUtil(2 * v + 1, tl, tm, a);
        buildUtil(2 * v + 2, tm + 1, tr, a);
        st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
    }
    // change the following 2 functions, and you're more or less done.
    T apply(T curr, U upd, ll tl, ll tr)
    {
        T ans = (tr - tl + 1) * upd;
        return ans;
    }
    U combineUpdate(U old_upd, U new_upd, ll tl, ll tr)
    {
        U ans = old_upd;
        ans = new_upd;
        return ans;
    }
    void push_down(ll v, ll tl, ll tr)
    {
        if (lazy[v] == identity_update)
            return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if (2 * v + 2 < 4 * n)
        {
            ll tm = (tl + tr) >> 1;
            lazy[2 * v + 1] = combineUpdate(lazy[2 * v + 1], lazy[v], tl, tm);
            lazy[2 * v + 2] = combineUpdate(lazy[2 * v + 2], lazy[v], tm + 1, tr);
        }
        lazy[v] = identity_update;
    }
    T queryUtil(ll v, ll tl, ll tr, ll l, ll r)
    {
        push_down(v, tl, tr);
        if (l > r)
            return identity_element;
        if (tr < l or tl > r)
        {
            return identity_element;
        }
        if (l <= tl and r >= tr)
        {
            return st[v];
        }
        ll tm = (tl + tr) >> 1;
        return combine(queryUtil(2 * v + 1, tl, tm, l, r), queryUtil(2 * v + 2, tm + 1, tr, l, r));
    }

    void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd)
    {
        push_down(v, tl, tr);
        if (tr < l or tl > r)
            return;
        if (tl >= l and tr <= r)
        {
            lazy[v] = combineUpdate(lazy[v], upd, tl, tr);
            push_down(v, tl, tr);
        }
        else
        {
            ll tm = (tl + tr) >> 1;
            updateUtil(2 * v + 1, tl, tm, l, r, upd);
            updateUtil(2 * v + 2, tm + 1, tr, l, r, upd);
            st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
        }
    }

    void build(vector<T> a)
    {
        assert((ll)a.size() == n);
        buildUtil(0, 0, n - 1, a);
    }
    T query(ll l, ll r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }
    void update(ll l, ll r, U upd)
    {
        updateUtil(0, 0, n - 1, l, r, upd);
    }
};
template<typename T>
void makeUniq(vector<T>& vec) {
    vec.resize(unique(begin(vec),end(vec)) - vec.begin());
}
ll gcd(ll x, ll y)
{
    if (x == 0 || y == 0)
        return max(x, y);
    return __gcd(x, y);
}
ll lcm(ll x, ll y)
{
    ll g = gcd(x, y);
    if (x == 0 || y == 0)
        return max(x, y);
    return (x * y) / gcd(x, y);
}
pair<long long, long long> solve(ll n, vector<ll> a, vector<ll> b)
{
    ll fans = -1;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i; j < n; j++)
        {
            vector<ll> u = a, v = b;
            for (ll k = i; k <= j; k++)
            {
                swap(u[k], v[k]);
            }
            ll g1 = 0, g2 = 0;
            for (ll k = 0; k < n; k++)
            {
                g1 = gcd(g1, u[k]);
                g2 = gcd(g2, v[k]);
            }
            mp[g1 + g2]++;
            if (g1 + g2 == 6)
            {
                // cout << i << " " <<  j << "\n";
            }
            fans = max(fans, g1 + g2);
        }
    }
    return {fans, mp[fans]};
}
ll log2v[(ll)2e5 + 20];
auto genius()
{


        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
        }

    ll K = log2v[n] + 1;

    vector<ll> ga, gb;
    ga = a, gb = b;

    vector<vector<ll>> g(K, vector<ll>(n));
    for (ll i = 0; i < K; i++)
        for (ll j = 0; j < n; j++)
            g[i][j] = 0;

    for (ll j = 0; j < n; j++)
    {
        g[0][j] = a[j];
    }
    for (ll i = 1; i < K; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            g[i][j] = gcd(g[i - 1][min(n - 1, j)], g[i - 1][min(n - 1, j + (1 << i - 1))]);
        }
    }
    auto querya = [&](ll l, ll r)
    {
        if (r < 0)
        {
            return 0;
        }
        if (l >= n)
        {
            return 0;
        }
        if (r == l)
        {
            return a[l];
        }
        ll g2 = log2v[r - l];

        return gcd(g[g2][l], g[g2][r - (1 << g2) + 1]);
    };

    vector<vector<ll>> t(K, vector<ll>(n));
    for (ll i = 0; i < K; i++)
        for (ll j = 0; j < n; j++)
            t[i][j] = 0;

    for (ll j = 0; j < n; j++)
    {
        t[0][j] = b[j];
    }
    for (ll i = 1; i < K; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            t[i][j] = gcd(t[i - 1][min(n - 1, j)], t[i - 1][min(n - 1, j + (1 << i - 1))]);
        }
    }

    auto queryb = [&](ll l, ll r)
    {
        if (r < 0)
        {
            return 0;
        }
        if (l >= n)
        {
            return 0;
        }
        if (r == l)
            return b[r];
        ll t2 = log2v[r - l];
        return gcd(t[t2][l], t[t2][r - (1 << t2) + 1]);
    };

    ll fans = querya(0, n - 1) + queryb(0, n - 1);
    auto getAns = [&](ll l, ll r)
    {
        ll g1, g2;
        g1 = g2 = 0;
        if (l - 1 >= 0)
        {
            g1 = gcd(g1, querya(0, l - 1));
        }
        if (r + 1 < n)
        {
            g1 = gcd(g1, querya(r + 1, n - 1));
        }
        if (l >= 0 && r < n)
        {
            g1 = gcd(g1, queryb(l, r));
        }
        if (l - 1 >= 0)
        {
            g2 = gcd(g2, queryb(0, l - 1));
        }
        if (r + 1 < n)
        {
            g2 = gcd(g2, queryb(r + 1, n - 1));
        }
        if (l >= 0 && r < n)
        {
            g2 = gcd(g2, querya(l, r));
        }
        return g1 + g2;
    };
    vector<ll> idx[n];
    for (ll i = 0; i < n; i++)
    {
        vector<ll> ind0;
        ll tgcd = queryb(i, n - 1);
        while (tgcd != b[i])
        {
            ll l = i, r = n - 1;
            auto cond = [&](ll mid)
            {
                return queryb(i, mid) <= tgcd;
            };
            while (l <= r)
            {
                ll mid = l + (r - l) / 2;
                if (cond(mid))
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            ind0.push_back(l);
            tgcd = queryb(i, l - 1);
        }
        ind0.push_back(i);
        fans = max(fans, getAns(i, n-1));
        for (ll k = 0; k < ind0.size() - 1; k++) {
            fans = max(fans, getAns(i, ind0[k]-1));
        }
        for (auto&v: ind0) {
            idx[i].pb(v);
        }
    }

    for (ll i = 0; i < n; i++)
    {
        vector<ll> ind0;
        ll tgcd = querya(i, n - 1);
        while (tgcd != a[i])
        {
            ll l = i, r = n - 1;
            auto cond = [&](ll mid)
            {
                return querya(i, mid) <= tgcd;
            };
            while (l <= r)
            {
                ll mid = l + (r - l) / 2;
                if (cond(mid))
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            ind0.push_back(l);
            tgcd = querya(i, l - 1);
        }
        ind0.push_back(i);
        fans = max(fans, getAns(i, n-1));
        for (ll k = 0; k < ind0.size() - 1; k++) {
            fans = max(fans, getAns(i, ind0[k]-1));
        }
        for (auto& v : ind0) {
            idx[i].pb(v);
        }
        
    }
    //return {0, 0};
    vector<pair<ll, ll>> aws[n];
    
    for (ll i = 0; i < n; i++)
    {
        sort(begin(idx[i]), end(idx[i]));
        
        idx[i].pb(n);
        ll sz = (ll)idx[i].size();


        for (ll j = 0; j < sz - 1; j++)
        {
            ll l = idx[i][j], r = idx[i][j + 1] - 1;
            if (l > r)
                continue;
            if (getAns(i, r) == fans)
            {
                ll L = l, R = r;
                auto cond = [&](ll mid)
                {
                    return getAns(i, mid) == fans;
                };
                while (L <= R)
                {
                    ll M = L + (R - L) / 2;
                    if (cond(M))
                    {
                        R = M - 1;
                    }
                    else
                    {
                        L = M + 1;
                    }
                }
                aws[i].push_back({L, r});
            }
        }
    }
    //cout << sum << "\n";
    long long sf = 0;
    for (ll i = 0; i < n; i++)
    {
        pair<ll, ll> p;
        p.first = -1, p.second = -2;
        sort(begin(aws[i]), end(aws[i]));
        for (ll j = 0; j < (aws[i]).size(); j++) {
            if (aws[i][j].first > p.second) {
                sf += p.second - p.first + 1;
                p.first = aws[i][j].first;
                p.second = aws[i][j].second;
            } else {
                p.second = aws[i][j].second;
            }
        }
        sf += p.second - p.first + 1;
    }
    assert(sf > 0);
    cout << fans << " " << sf << "\n";
}

mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y)
{
    return uniform_int_distribution<int>(x, y)(rng);
}
// auto stress()
// {
//     ll itr = 0;
//     while (true)
//     {
//         // cout << itr + 1 << "\n";
//         // if (itr < 100000) {
//         // itr++;
//         //} else {
//         // break;
//         //}
//         ll n = rnd(K, 50);
//         vector<ll> a(n), b(n);
//         for (ll i = 0; i < n; i++)
//         {
//             a[i] = rnd(1, 100);
//             b[i] = rnd(1, 100);
//         }

//         auto bans = solve(n, a, b);
//         auto sans = genius(n, a, b);

//         if (bans != sans)
//         {
//             cout << "not ok\n";
//             dbg(n, a, b);
//             dbg(bans);
//             dbg(sans);
//             exit(0);
//         }
//         else
//         {
//             cout << "ok\n";
//             dbg(bans);
//             dbg(sans);
//             // cout << bans.first << " " << bans.second << '\n';;
//         }
//     }
// };
// auto stress2()
// { // check.in
//     ll t;
//     cin >> t;
//     for (ll tc = 1; tc <= t; tc++)
//     {
//         ll n;
//         cin >> n;
//         vector<ll> a(n), b(n);
//         for (ll i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }
//         for (ll i = 0; i < n; i++)
//         {
//             cin >> b[i];
//         }
//         pair<long long, long long> exp;
//         cin >> exp.first >> exp.second;
//         auto bans = genius(n, a, b);
//         if (bans == exp)
//         {
//             // cout << "ok\n";
//         }
//         else
//         {
//             cout << "Test #: " << tc << "\n";
//             cout << n << "\n";
//             for (auto &x : a)
//             {
//                 cout << x << " ";
//             }
//             cout << "\n";
//             for (auto &x : b)
//             {
//                 cout << x << " ";
//             }
//             cout << "\n";
//             cout << exp.first << " " << exp.second << "\n";
//             cout << bans.first << " " << bans.second << "\n";
//             exit(0);
//         }
//         // auto sans = genius(n, a, b);
//         // assert(bans.first == sans.first);

//         // dbg(bans,sans);
//         // assert(bans == sans);
//     }
// }
// auto stress3()
// {
//     ll itr = 0;
//     ll n = 2e5;
//     vector<ll> a(n), b(n);
//     for (ll i = 0; i < n; i++)
//     {
//         a[i] = 1e9;
//         b[i] = 1e9;
//     }

//     auto gans = genius(n, a, b);

//     cout << gans.first << " " << gans.second << "\n";
// };
auto stress4()
{
    // for (ll itr = 1; itr <= 5; itr++)
    // {
    //     ll n = 1e5;
    //     vector<ll> a(n), b(n);
    //     for (ll i = 0; i < n; i++)
    //     {
    //         a[i] = rnd(1, 1000);
    //         b[i] = rnd(1, 1000);
    //     }

    //     auto gans = genius();

    //     cout << gans.first << " " << gans.second << "\n";
    // }
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    ll fv = 2;
    log2v[1] = 0;
    for (ll i = 2; i < (ll)2e5 + 10; i++) {
        if (i == fv) {
            log2v[i] = log2v[i-1] + 1;
            fv *= 2;
        } else {
            log2v[i] = log2v[i-1];
        }
    }
    

    // stress4();
    // exit(0);

    // stress3();
    // exit(0);

    // stress2();
    // exit(0);

    //stress();
    //exit(0);

    ll t;
    cin >> t;
    while (t--)
    {
        // auto sans = solve(n, a, b);
        genius();
        
    }
}
/*
TLE by 1 second :)
*/