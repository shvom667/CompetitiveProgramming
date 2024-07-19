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
ll hb(ll x) {
    ll f = 0;
    for (ll i = 0; i < 30; i++)
        if ((1ll<<i)&x)
            f = i;
    return f;
}
void solve() {
    ll n;
    cin >> n;
    Vec<ll> a(n), h(n);
    Vec<Vec<ll>> bit(30, Vec<ll> (n, 0)), pe, po, se, so, pbit, sbit;
    pbit = sbit = bit;
    pe = po = se = so = bit;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        h[i] = hb(a[i]);
    }
    dbg(h);
    for (ll b = 0; b < 30; b++) {
        for (ll j = 0; j < n; j++) {
            if ((1ll<<b) & a[j])
                bit[b][j] = 1;
        }
    }
    for (ll b = 0; b < 30; b++) {
        ll ce, co;
        ce = 1, co = 0;
        for (ll j = 0; j < n; j++) {
            if (j) {
                pbit[b][j] += pbit[b][j-1];
            }
            pbit[b][j] += ((1ll<<b)&a[j]) > 0;
            if (j) {
                if (pbit[b][j-1]%2==1) {
                    pe[b][j] = co-1;
                    po[b][j] = ce;
                }
                if (pbit[b][j-1]%2==0) {
                    pe[b][j] = ce-1;
                    po[b][j] = co;
                }
                        
            }
            if (pbit[b][j]%2==1) {
                co++;
            } else {
                ce++;
            }

        }
    }
    for (ll b = 0; b < 30; b++) {
        ll ce = 1, co = 0;
        for (ll j = n-1; j >= 0; j--) {
            if (j + 1 < n) {
                sbit[b][j] += sbit[b][j+1];
            }
            sbit[b][j] += ((1ll<<b) & a[j]) > 0;
            if (j+1<n) {
                if (sbit[b][j+1]%2==1) {
                    se[b][j] = co-1;
                    so[b][j] = ce;
                }
                if (sbit[b][j+1]%2==0) {
                    se[b][j] = ce-1;
                    so[b][j] = co;
                }
                        
            }
            if (sbit[b][j]%2==1) {
                co++;
            } else {
                ce++;
            }
        }
    }
    ll fans = 0;
    for (ll i = 0; i < n; i++) {
        fans += po[h[i]][i];
        fans += so[h[i]][i];
        fans += se[h[i]][i] * po[h[i]][i];
        fans += pe[h[i]][i] * so[h[i]][i];
    }
    //dbg(pbit);
    //dbg(pe);
    //dbg(po);
    cout << fans << '\n';
}


int main() {

    ll t;
    t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}

