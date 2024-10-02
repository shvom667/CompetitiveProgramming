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
// ============
const ll INF = 1e9;
vector<ll> fac;
using pl = pair<ll, ll>;
map<pl, pair<ll, vector<ll>>> mp;

pair<ll, vector<ll>> dfs(ll s, ll p) {

    if (s == p) {
        pair<ll, vector<ll>> fans;
        fans.first = 1;
        vector<ll> vec;
        vec.push_back(s);
        fans.second = vec;
        return fans;
    }
    if (mp.find({s,p}) != mp.end()) {
        return mp[{s,p}];
    }

    pair<ll, vector<ll>> fans;
    fans.first = INF;
    fans.second = vector<ll>();

    for (auto& x : fac) {
        if (x <= s && p % x == 0) {
            auto res = dfs(s - x, p / x);
            fans.first = min(fans.first, 1 + res.first);
            if (fans.first == res.first + 1) {
                fans.second = res.second;
                fans.second.push_back(x);
            }
        }
    }

    return mp[{s,p}] = fans;
}

auto solve2(ll n) {
    dbg(fac);
    pair<ll, vector<ll>> fans;
    fans.first = INF;
    fans.second = vector<ll>();

    for (ll s = 1; s <= 41; s++) {
        auto cur = dfs(s, n);
        fans.first = min(fans.first, cur.first -s + 41);
        if (cur.first -s + 41== fans.first) {
            fans.second = cur.second;
        }
    }
    return fans.second;
}

auto solve(ll n) {
    ll N = n;
    vector<ll> f;
    while (n > 1) {
        ll mf = 44;
        for (ll i = 2; i <= 41; i++) {
            if (n % i == 0) {
                n /= i;
                mf = i;
                break;
            } 
        }
        if (mf > 41) {
            f.clear();
            f.push_back(-1);
            return f;
        } else {
            f.push_back(mf);
            continue;
        }
    }
    ll sum = 0;
    for (auto&x : f) {
        sum += x;
    }
    if (sum > 41) {
        f.clear();
        f.push_back(-1);
        return f;
    }
    f =  solve2(N);
    sum = 0;
    for (auto&x : f) {
        sum += x;
    }
    while (sum < 41) {
        sum++;
        f.push_back(1);
    }
    return f;
}

int main() {
    ll t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        ll n;
        cin >> n;
        fac.clear();
        for (ll i = 2; i <= 41; i++) {
            if (n % i == 0) fac.push_back(i);
        }
        auto res = solve(n);
        cout << "Case #" << tc << ": " ;
        if (res[0] == -1)
            for (auto&x : res)
                cout << x << " ";
        else {
            cout << res.size() << " ";
            for (auto&x : res)
                cout << x << " ";
        }
        cout << "\n";
    }
}
