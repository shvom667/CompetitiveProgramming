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

ll solve(ll n, ll m, vector<ll> c, vector<vector<ll>> a);
const ll INF=1e18+20;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> c(n);
        for (ll i = 0; i < n; i++) {
            cin >> c[i];
        }
        vector<vector<ll>> a(n, vector<ll> (m));
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        cout << solve(n, m, c, a) << '\n';
    }
}


const ll zero = 0;
using pl = pair<ll, ll>;
ll solve(ll n, ll m, vector<ll> c, vector<vector<ll>> a) {
    
    dbg(n, m, c, a);

    set<pair<int, int>> pq;

    vector<ll> min_cost(n,INF);

    min_cost[0] = 0;
    pq.insert({0,0});
    ll times = 0;
    while (!pq.empty()) {
        pl f = *pq.begin();        
        dbg(f);
        if (f.second == n-1) {
            break;
        }
        pq.erase(pq.begin());
        if (min_cost[f.second] < f.first) {
            continue;
        }
                       
        vector<pl> wt;
        if (true) {
            ll i = f.second;
            for (ll j = 0; j < n; j++) {
                if (j == i) continue;
                ll fans = INF; 
                for (ll k = 0; k < m; k++) {
                    fans = min(fans, max(a[i][k]-a[j][k], zero));
                    if (fans == 0) break;
                }
                wt.push_back({j,fans});
            }
        }

        for (auto& x: wt) {
            times++;
            ll new_cost = min(min_cost[x.first], 
                f.first + x.second + c[x.first]
            );
            if (new_cost < min_cost[x.first]) {
                min_cost[x.first] = new_cost;
                pq.insert({new_cost, x.first});
                while (pq.size() >= 1e3) {
                    pq.erase(*pq.rbegin());
                }
            }

        }
        
    }
    // cout << times << "\n";
    return min_cost[n-1];
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