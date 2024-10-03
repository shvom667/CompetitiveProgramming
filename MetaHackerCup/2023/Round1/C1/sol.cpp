#define ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
using ll = int;
#define ALL(x) begin(x), end(x)

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
void makeUniq(vector<T>& vec) {
    sort(begin(vec),end(vec));
    vec.resize(unique(ALL(vec)) - vec.begin());
}

auto solve(auto n, auto a, auto q, auto x) {
    map<ll, ll> mp;
    for (auto& y : x) mp[y]++;
    dbg(mp);
    x.clear();
    for (auto&  [p, q]: mp) {
        if (q&1) x.push_back(p);
    }
    
    for (auto&v : x) {
        for (ll i = v - 1; i < n; i += v) {
            a[i] ^= 1;
        }
    }
    ll fans = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] == 1) {
            fans++;
            ll v = i + 1;
            for (ll i = v - 1; i < n; i += v) {
                a[i] ^= 1;
            }
        }
    }

    return fans;
}

int main() {
    int t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        ll n;
        cin >> n;
        vector<int> a(n);
        for (ll i = 0; i < n; i++) {
            char c;
            cin >> c;
            a[i] = c - '0';
        }
        ll q;
        cin >> q;
        vector<ll> x(q);
        for (auto&y : x) cin >> y;
        auto res = solve(n, a, q, x);
        cout << "Case #" << tc << ": " << res << "\n";
    }
}
