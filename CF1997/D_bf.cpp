#include <bits/stdc++.h>
using namespace std;

#define ll int
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


using pl = pair<ll, ll>;
// #define pb push_back
void solve() {
    ll n, q;
    cin >> n >> q;
    Vec<ll> v(n+1);
    for(ll i = 1; i <= n; i++) {
        cin >> v[i];
    }

    ll M = sqrtl(n);

    Vec<Vec<ll>> qr(n+1); 

    Vec<pl> qlo;

    for(ll i = 0; i < q; i++) {
        ll x, y;
        cin >> x >> y;
        qlo.pb({x,y});
        qr[y].pb(x);
    }


    map<pl, bool> fmap;

    for (ll k = 1; k <= M; k++) {
        if (k > n) break;
        ll fc = 0, cl = 1;
        Vec<ll> b = {0};
        for (ll i = 1; i <= n; i++) {
            if (v[i] >= cl) {
                fc++;
                if (fc % k == 0) {
                    b.pb(i);
                    cl++;
                }
            }
        }
        dbg(k, b);

        for(auto&i : qr[k]) {
            ll fans = 0;


            auto it = lower_bound(begin(b), end(b), i);
            ll lvl = it - begin(b);
            if (v[i] >= lvl) {

                fmap[{i,k}] = true;
            } else {
                fmap[{i,k}]=false;
            }
        }
    }   

    Vec<Vec<ll>> g(n+1, Vec<ll> (n/M+1, 0));

    for (ll i = n; i >= 1; i--) {
        for (ll j = 1; j <= n/M; j++) {
            if (v[i] >= j) {
                g[i][j]++;
            }
            if (i < n) {
                g[i][j] += g[i+1][j];
            }
        }
    }

    for(auto&v: g) {
        dbg(v);
    }

     for (ll k = M+1; k <= n; k++) {
        Vec<ll> b;
        b.pb(0);
        ll cl  = 0;
        while (b.back() < n) {
            cl++;
            ll sp = b.back() + 1;
            ll bl = sp, be = n;
            auto cond = [&] (ll mid) {
                ll cntm = g[b.back()+1][cl] - (mid+1<=n ? g[mid+1][cl] : 0);
                return cntm <= k;
            };
            while (bl <= be) {
                ll bm = bl + (be - bl) / 2;
                if (cond(bm)) {
                    bl = bm + 1;
                } else {
                    be = bm - 1;
                }
            }
            b.pb(be);
        }
        dbg(k, b);
        for(auto&i : qr[k]) {
            ll fans = 0;


            auto it = lower_bound(begin(b), end(b), i);
            ll lvl = it - begin(b);
            if (v[i] >= lvl) {

                fmap[{i,k}] = true;
            } else {
                fmap[{i,k}]=false;
            }

        }

    }

    for(auto&[x,y]:qlo) {
        cout << (fmap[{x,y}]==true?"YES\n":"NO\n");
    }

}

int main() {

    ll t;
    t = 1;
    while (t--) {
        solve();
    }
}
