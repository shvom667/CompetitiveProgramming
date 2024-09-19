#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--) solve();
}

auto findMex(vector<ll> x) {
    set<ll> s;
    for(auto&y:x) {
        s.insert(y);
    }
    ll res = s.size();
    for (ll i = 0; i <= s.size(); i++) {
        if (s.find(i)==s.end()) {
            res = i;
            break;
        }
    }
    return res;
}
using pl = pair<ll, ll>;
void solve() {
    ll n, m;
    cin >> n >> m;
    ll fans = 0;
    ll gm = 0;
    map<ll, ll> cnt;
    ll L = 0;
    Vec<pl> vec;
    for (ll i = 0; i < n; i++) {
        ll l;
        cin >> l;
        L += l;
        vector<ll> x(l);
        for(auto&y:x){
            cin>>y;
        }
        sort(begin(x),end(x));
        ll v = findMex(x);
        ll m = v;
        x.pb(v);
        v = findMex(x);
        ll mm = v;
        
        dbg(m, mm);
        vec.pb({m,mm});
        cnt[m]++;
    }
    L += 10;
    vector<ll> g[L+1];
    for(auto&[m,mm]:vec){
        g[m].pb(mm);
    }

    vector<ll> best(L+1);

    for (ll i = L; i >= 0; i--) {
        best[i] = i;
        for (auto&x:g[i]) {
            best[i] = max(best[i], best[x]);
        }
    }
    ll gans=0;
    for (auto&[u,v]:vec) {
        gans = max(gans, u);
    }
    vector<ll> start;
    for(auto&[u,v]:cnt) {
        if (v >= 2) {
            start.pb(u);
        }
    }
    sort(begin(start),end(start));
    dbg(start);
    if (true) {
        set<ll> seen;
        queue<ll> q;
        for (auto&x:start) {
            q.push(x);
            seen.insert(x);
        }
        while (!q.empty()) {
            dbg("hello");
            ll f = q.front();
            gans = max(f, gans);
            q.pop();
            for(auto&y:g[f]){
                if (seen.count(y)==0) {
                    q.push(y);
                    seen.insert(y);
                }
            }
        }
    }
    dbg(best);
    dbg(gans);

    ll res = 0;
    for (ll i = 0; i <= min(L, m); i++) {
        res += max(gans, best[i]);
    }
    if (min(L, m) < m) {
        res += (m*(m+1)) / 2 - (L * (L + 1)) / 2;
    }
    cout << res << '\n';
}