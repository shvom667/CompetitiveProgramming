#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define i32 int
#define pb push_back
#define ALL(x) begin(x), end(x)
#define SZ(x) (ll)(x.size())
#define OVERRIDE(a, b, c, d, ...) d
#define REP2(i, n) for (i32 i = 0; i < (i32)(n); ++i)
#define REP3(i, m, n) for (i32 i = (i32)(m); i < (i32)(n); ++i)
#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
#define PER(i, n) for (i32 i = (i32)(n) - 1; i >= 0; --i)

template <typename T>
using Vec = vector<T>;
template<typename T>
vector<T> PrefixSum(vector<T> X) {
    ll n = X.size();
    vector<T> ret(n, 0);
    REP (i, n) {
        ret[i] = X[i];
        if (i > 0) ret[i] += ret[i - 1];
    }
    return ret;
}
template<typename T>
void chmax(T& a, T b) {
    a = max(a, b);
}
template<typename T>
void chmin(T& a, T b) {
    a = min(a, b);
}
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

ll N, M;
ll S(ll p, ll c1, ll c2) {
    dbg(p, c1, c2);
    ll fans = 0;
    if (true) {
        ll y = c2;
        ll x = min(c1, (M - (p + 1) * c2) / p );
        x = max(x, 0ll);
        ll cur = y * (p + 1) + x * p;
        if (cur <= M) {
            fans = max(fans, cur);
        }
    }
    if (true) {
        ll Y = min(c2, M / (p + 1));
        ll r = M % p;
        if (Y < r) {

        } else {
            ll z = (Y - r) / p;
            ll y = z * p + r;
            dbg(y);
            ll x = min(c1, (M - (p + 1) * y) / p );
            x = max(x, 0ll);
            ll cur = y * (p + 1) + x * p;
            if (cur <= M) {
                fans = max(fans, cur);
            }
        }
    }
    
    return fans;
}


void solve() {
    cin >> N >> M;

    ll a[N], b[N], I[N];
    for(ll i = 0; i < N; i++) {
        cin >> a[i];
        I[i] = i;
    }
    for(ll i = 0; i < N; i++) {
        cin >> b[i];
    }
    sort(I, I+N, [&](ll x, ll y){
        return a[x] < a[y]; 
    });
    ll fans = 0;
    for(ll j = 1; j < N; j++) {
        ll i = I[j];
        ll ip = I[j-1];
        if (a[i] == a[ip] + 1)
        fans = max(fans, 
            S(a[ip], b[ip], b[i])
        );
    }


    for(ll i = 0; i < N; i++) {
        fans = max(fans, 
            (min(M/a[i], b[i])) * a[i] 
        );
    }

    cout << fans << "\n";
}   

int main() {

    ll t;
    t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
