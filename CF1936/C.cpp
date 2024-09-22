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
    apply(
        [&first](const auto &...args) {
            ((cerr << (first ? "" : ","), __print(args), first = false), ...);
        },
        t);
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
    if (sizeof...(T)) cerr << ", ";
    _print(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...)                                                    \
    cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; \
    _print(__VA_ARGS__)
#else
#define dbg(...)
#endif
ll case1(ll n, ll m, vector<ll> c, vector<vector<ll>> a);

ll solve(ll n, ll m, vector<ll> c, vector<vector<ll>> a);
void stress3();

void stress2();
void stress1();
const ll INF = 1e18 + 20;
int main() {
    // cin.tie(nullptr)->sync_with_stdio(false);

    stress3();
    return 0;

    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> c(n);
        for (ll i = 0; i < n; i++) {
            cin >> c[i];
        }
        vector<vector<ll>> a(n, vector<ll>(m));
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        cout << solve(n, m, c, a) << '\n';
    }
}
random_device rd;
mt19937 mt(time(NULL) * rd());
ll case1(ll n, ll m, vector<ll> c, vector<vector<ll>> a) {
    return c[n - 1] + max(0ll, a[0][0] - a[n - 1][0]);
}
void stress1() {
    while (true) {
        ll n = mt() % 500 + 2;
        ll m = 1;
        vector<ll> c;
        ll M = 100;
        for (ll i = 1; i <= n; i++) {
            c.pb(mt() % M + 1);
        }
        vector<vector<ll>> a(n, vector<ll>(m));
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                a[i][j] = mt() % M + 1;
            }
        }
        ll sans = solve(n, m, c, a);
        ll cans = case1(n, m, c, a);
        if (sans == cans) {
            cout << "ok" << "\n";
        } else {
            dbg(n);
            dbg(m);
            dbg(c);
            dbg(a);
            assert(false);
        }
    }
}
void stress2() {
    while (true) {
        ll n = 50000;
        ll m = 2;
        vector<ll> c;
        ll M = 10;
        for (ll i = 1; i <= n; i++) {
            c.pb(mt() % M + 1);
        }
        vector<vector<ll>> a(n, vector<ll>(m));
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                a[i][j] = mt() % M + 1;
            }
        }
        dbg(n);
        dbg(m);
        dbg(c);
        dbg(a);
        auto res = solve(n, m, c, a);
        dbg(res);
        break;
    }
    // cout << solve(n, m, c, a) << "\n";
}

void stress3() {
    while (true) {
        ll n = 50000;
        ll m = 2;
        vector<ll> c;
        ll M = 100;
        for (ll i = 1; i <= n; i++) {
            c.pb(mt() % M + 1);
        }
        vector<vector<ll>> a(n, vector<ll>(m));
        a[0][0] = a[0][1] = M;
        for (ll i = 1; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                a[i][j] = mt() % M + 1;
            }
        }
        dbg(n);
        dbg(m);
        dbg(c);
        dbg(a);
        auto res = solve(n, m, c, a);
        dbg(res);
        break;
    }
    // cout << solve(n, m, c, a) << "\n";
}
const ll zero = 0;
using pl = pair<ll, ll>;
ll solve(ll n, ll m, vector<ll> c, vector<vector<ll>> a) {
    // dbg(n, m, c, a);

    set<pair<int, int>> pq;

    vector<ll> min_cost(n, INF);

    min_cost[0] = 0;
    pq.insert({0, 0});
    ll times = 0;   
    set<ll> not_seen;
    for (ll i = 0; i < n; i++) {
        not_seen.insert(i);
    }
    not_seen.erase(0);
    while (!pq.empty()) {
        pl f = *pq.begin();
        if (f.second == n - 1) {
            break;
        }
        pq.erase(pq.begin());

        if (min_cost[f.second] < f.first) {
            continue;
        }        
        dbg(f, times>=n*m);

        not_seen.erase(f.second);
        vector<pl> wt;
        if (true) {
            ll i = f.second;
            // for (ll j = 0; j < n; j++) {
            for (auto j : not_seen) {
                if (j == i) continue;
                ll fans = INF;
                for (ll k = 0; k < m; k++) {
                    fans = min(fans, max(a[i][k] - a[j][k], zero));
                    if (fans == 0) break;
                }
                wt.push_back({j, fans});
            }
        }
        // sort(begin(wt),end(wt),[&](auto u, auto v) {
        //     return u.second < v.second;
        // });
        ll itr = 0;
        for (auto &x : wt) {
            times++;
            ll new_cost =
                min(min_cost[x.first], f.first + x.second + c[x.first]);
            if (new_cost < min_cost[x.first]) {
                min_cost[x.first] = new_cost;
                pq.insert({new_cost, x.first});
            }
            itr++;
        }
    }
    // cout << times << "\n";
    return min_cost[n - 1]; 
}

/*
the amount and the number of nodes become important
adding k has no effect
where will you store the O(n*n) edges?
logic is totally correct, just that we need to handle mle error
*/

/*
This gives me MLE because it is O(N*N) soution
Need to do something better

Needs some optimization which my reatrded brain can not think of.
*/
/*
The problem is that there are a lot of edges.
That should be solved somehow.
We are able to generate edges as we go, reducing the space complexity
But still there are a lot of edges.
Which leads to TLE - Time Limit Exceeded

How do we want to solve it if we want to reduce it's time complexiy
*/
/*
Reduction:
n
m = 2
no updates k
how many positive weights can there be?
We have a solution where edges are O(n*n)
can we have a solution where edges are O(n * m)
each n you go alternate
so yeah edges can be O(n * m).

It is highly possible that this is the solution.
*/
/*
Still not able to find the solution after 2 days
Even  if i can  figure out in O(log^2(n)) the solution will work in O(n*m*log2(n*m)) time.
Just the question is can i?
Ok
*/