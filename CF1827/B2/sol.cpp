#define ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// =================

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
void __print(maxt x) {
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

// =================
auto getNse(vector<ll> a)
{
    ll n = a.size();
    vector<ll> res, nse;

    res.push_back(n);
    nse = a;
    for (ll i = n - 1; i >= 0; i--)
    {
        while (res.back() != n && a[res.back()] > a[i])
        {
            res.pop_back();
        }
        nse[i] = res.back();
        res.push_back(i);
    }
    // dbg(nse);
    return nse;
}
auto getPse(vector<ll> a)
{
    ll n = a.size();
    deque<ll> res;
    vector<ll> pse(n);
    res.push_back(-1);
    pse[0] = -1;
    for (ll i = 0; i < n; i++)
    {
        while (res.back() != -1 && a[res.back()] > a[i])
        {
            res.pop_back();
        }
        pse[i] = res.back();
        res.push_back(i);
    }
    return pse;
}
auto ctp(ll n, vector<ll> a)
{
    vector<ll> b = a;
    sort(begin(b), end(b));
    map<ll, ll> mp, rmp;
    for (ll i = 1; i <= n; i++)
    {
        mp[b[i - 1]] = i;
        rmp[i] = b[i - 1];
    }
    for (ll i = 0; i < n; i++)
        a[i] = mp[a[i]];
    return a;
}

auto bf(ll n, vector<ll> a)
{
    map<ll, ll> mp;
    ll fans = 0, sum = 0;
    for (ll i = 0; i < n; i++)
    {
        deque<pair<ll, ll>> dq;
        ll pr = 0;
        for (ll j = i; j < n; j++)
        {
            ll l = a[j], r = a[j];
            while (!dq.empty() && dq.back().second > a[j])
            {
                auto b = dq.back();
                l = min(l, b.first);
                r = max(r, b.second);
                dq.pop_back();
            }
            dq.push_back({l, r});
            sum += dq.size();
            for (auto &[u, v] : dq)
            {
                mp[u]++;
            }
            fans += j - i + 1 - dq.size();
            // dbg(dq);
        }
        // dbg("$$$$$$$$$$$$$$");
    }
    ll full = ((n + 1) * (n + 1) * (n)) / 2;
    full -= (n * (n + 1) * (2 * n + 1)) / 6;

    dbg(full);
    dbg(mp);
    dbg(sum);
    return fans;
}
const ll M = 20;

auto solve(ll n, vector<ll> a)
{
    vector<ll> r(n), l(n);
    vector<ll> nse, pse;
    nse = getNse(a);
    for (ll i = 0; i < n; i++)
    {
        r[i] = nse[i] - i;
    }
    // dbg(r);
    pse = getPse(a);
    dbg(pse);

    vector<vector<ll>> rmax(20, vector<ll>(n));
    // ll rmax[20][n];
    for (ll i = 0; i < n; i++)
    {
        rmax[0][i] = a[i];
    }
    for (ll m = 1; m < 20; m++)
    {
        for (ll i = 0; i < n; i++)
        {

            rmax[m][i] = max(rmax[m - 1][i],
                             rmax[m - 1][min(n - 1, i + (1 << (m - 1)))]);
        }
    }
    auto query = [&](ll x, ll y)
    {
        ll p2 = log2(y - x + 1);
        return max(
            rmax[p2][x],
            rmax[p2][y - (1ll << p2) + 1]);
    };

    for (ll i = 0; i < n; i++)
    {
        ll m = pse[i] + 1;
        ll fm = m;
        if (m > 0)
        {
            ll l = 0, r = m - 1;
            while (l <= r)
            {
                ll mid = l + (r - l) / 2;
                bool ok = query(mid, m - 1) <= a[i];
                if (ok)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            fm = l;
        }
        dbg(m, fm);
        l[i] = i - fm + 1;
    }
    dbg(l);

    ll full = ((n + 1) * (n + 1) * (n)) / 2;
    full -= (n * (n + 1) * (2 * n + 1)) / 6;
    ll fans = 0;
    for (ll i = 0; i < n; i++)
    {
        fans += r[i] * l[i];
    }
    return full - fans;
}

auto stress()
{
    ll n;
    n = 200;
    std::random_device rd;  // obtain a random number from hardware
    std::mt19937 rng(rd()); // seed the generator

    vector<ll> a(n), I;
    for (ll i = 0; i < n; i++)
    {
        a[i] = i + 1;
        I.push_back(i + 1);
    }
    // a = ctp(n, a);

    // dbg(a);
    // dbg(I);
    while (true)
    {
        std::shuffle(a.begin(), a.end(), rng);
        

        auto sans = solve(n, a);
        auto bans = bf(n, a);

        if (bans != sans) {
            cout << n << "\n";
            for (auto&x : a) {
                cout << x << " ";
            }   cout << '\n';
            exit(0);
        } else{
            cout << "ok\n";
        }
    }
}

int main()
{

    // stress();

    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++)
    {
        ll n;
        cin >> n;
        vector<ll> a(n), I;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            I.push_back(i + 1);
        }

        a = ctp(n, a);

        dbg(a);
        // dbg(I);
        auto res = solve(n, a);

        cout << res << "\n";
    }
}
