#define ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll M = 11;


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

// =================

mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y)
{
    return uniform_int_distribution<int>(x, y)(rng);
}


// ============

struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }
    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool same_set(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

// ============


auto bf(ll n, ll m, vector<ll> a, vector<ll> d, vector<ll> k) {
    for (ll i = 0; i < m ; i++) {
        a[i]--;
    }
    DSU dsu(n);
    for (ll i = 0; i < m; i++) {
        for (ll kk = 0; kk <= k[i]; kk++) {
            dsu.unite(a[i], a[i] + kk * d[i]);
        }
    }
    set<ll> s;
    for (ll i = 0; i < n; i++) {
        s.insert(dsu.get(i));
    }
    ll res = s.size();
    return res;
}

auto solve(ll n, ll m, vector<ll> a, vector<ll> d, vector<ll> k) {
    
    ll tab[M][n+1];
    DSU dsu(n + 1);

    for (ll i = 0; i < M; i++) for (ll j = 0; j <= n; j++) tab[i][j] = 0;
    for (ll i = 0; i < m; i++) {
        
        tab[d[i]][a[i]] = max(a[i]  + k[i] * d[i], tab[d[i]][a[i]]);
    }
    for (ll d = 1; d <= 10; d++) {
        for (ll i = 1; i <= n; i++) {
            if (i - d >= 0) {
                tab[d][i] = max(tab[d][i], tab[d][i-d]);
            }
        }
    }
    ll cnt = 0;
    for (ll i = 1; i <= n; i++) {
        bool ok = false;
        for (ll d = 1; d <= 10; d++) {
            
            if (i - d >= 1) {
                if (tab[d][i-d] >= i) {
                    dsu.unite(i-d, i);
                }
            }
        }
        if (!ok) {
            cnt++;
        }
    }
    

    set<ll> s;
    for (ll i = 1; i <= n; i++) {
        s.insert(dsu.get(i));
    }
    ll res = s.size();
    return res;
}

void stress() {
    while (true) {
        ll n = rnd(1, 100);
        ll m = rnd(2, 100);
        vector<ll> a(m), d(m), k(m);
        for (ll i = 0; i < m; i++) {
            a[i] = rnd(1, n);
            d[i] = rnd(1, 10);
            k[i] = rnd(0, ((n - a[i]) / d[i]));
        }
        auto sans = solve(n, m, a, d, k);
        auto bans = bf(n, m, a, d, k);

        if (sans != bans) {
            dbg(n, m);
            dbg(a);
            dbg(d);
            dbg(k);
            dbg(sans, bans);
            exit(0);
        } else {
            cout << "ok\n";
        }
    }
    
}


int main() {

    // stress();

    int T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {

        ll n, m;
        cin >> n >> m;
        vector<ll> a(m), d(m), k(m);
        for (ll i = 0; i < m; i++) {
            cin >> a[i] >> d[i] >> k[i];
        }
        auto sans = solve(n, m, a, d, k);
        // auto bans = bf(n, m, a, d, k);
        // cout << sans << " " << bans << "\n";
        cout << sans << "\n";
    }
}
