#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

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
mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}

auto solve(ll n, vector<ll> k) {
    vector<ll> fans;
    fans= {-1ll};
    for (ll m = 1; m <= 3000; m++) {
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            sum += (m + k[i] - 1) / k[i];
        }
        if (sum < m) {
            fans.clear();
            for (ll i = 0; i < n; i++) {
                fans.push_back((m + k[i] - 1) / k[i]);
            }
        }
    }
    return fans;
}

auto bf(ll n, vector<ll> k) {
    vector<ll> fans;
    bool ok = false;
    for (ll T = 1; T <= 10000; T++) {
        ll sum = 0;
        for (ll i = 0; i < n; i++) 
            sum += (T + k[i] - 1) / k[i];
        if (sum < T) {
            for (ll i = 0; i < n; i++) {
                fans.pb((T + k[i] - 1) / k[i]);
            }
            return fans;
        }
    }
    fans= {-1ll};
    return fans;
}


auto stress() {
    while (true) {
    ll n = 8;
    vector<ll> k(n);
    for (auto&x:k) x = rnd(2,20);
    auto sans = solve(n, k);
    auto bans = bf(n, k);
    if (sans.size() != bans.size()) {
        cout << n << "\n";
        for (auto&x : k)
            cout << x << " ";
        cout << "\n";
        dbg(sans);
        dbg(bans);
        exit(0);
    } else {
        cout << "ok\n";
    }
    }
}
ll gcd(ll x, ll y) {
    if (x == 0 || y == 0) return max(x,y);
    return __gcd(x,y);
}
ll lcm(ll x, ll y){
    return x * y / gcd(x,y);
}
auto genius(ll n, vector<ll> k) {
    if (n >= 20) {
        cout << -1 << "\n";
        return;
    }
    ll l=1, s=0;
    for (ll i = 0; i < n; i++) {
        l = lcm(l, k[i]);
    }
    dbg(l);
    for (ll i = 0; i < n; i++) {
        s+=l/k[i];
    }
    if (s < l) {
        for (auto&v : k) {
            cout << l / v << " ";
        } cout << "\n";
    } else{
        cout << -1 << "\n";
    }
}

int main() {

//    stress();

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n;
        cin >> n;
        vector<ll> k(n);
        for (ll i = 0; i < n; i++)
            cin >> k[i];
        genius(n, k);
        continue;
        auto res = solve(n, k);
        for (auto&x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
