#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

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

struct cs {
    bool operator() (pair<ll,ll> a, pair<ll,ll> b) const {
        if (a.first < b.first) return true;
        if (a.first > b.first) return false;
        if (a.first == b.first) {
			return a.second < b.second;
		}
    }
};
struct cg {
    bool operator() (pair<ll,ll> a, pair<ll,ll> b) const {
        if (a.first > b.first) return true;
        if (a.first < b.first) return false;
        if (a.first == b.first) {
			return a.second < b.second;
		}
    }
};

void test() {
	set<pair<ll,ll>, cs> ms;
	set<pair<ll,ll>, cg> mg;
	
	ms.insert({1,2});
	ms.insert({1,3});
	ms.insert({1,4});
	ms.insert({2,5});
	ms.insert({2,0});
	ms.insert({2,6});
	
	
	mg.insert({1,2});
	mg.insert({1,3});
	mg.insert({1,4});
	mg.insert({2,5});
	mg.insert({2,0});
	mg.insert({2,6});
	
	for (auto&[a,b]:ms){
		cout << a << " " << b << "\n";
	}
	cout << "\n";
	
	for (auto&[a,b]:mg){
		cout << a << " " << b << "\n";
	}
	cout << "\n";
}

auto solve(ll n, vector<ll> a) {
	set<pair<ll,ll>, cs> ms;
	set<pair<ll,ll>, cg> mg;
	vector<ll> ans = {-1};
	
	set<ll> s;
	vector<ll> d(n + 1, 0), p(n+1, 0);
	map<ll, ll> last_pos;
	for (ll i = n - 1; i >= 0; i--) {
		s.insert(a[i]);
		d[i] = s.size();
		if (last_pos.find(a[i]) == last_pos.end()) {
			last_pos[a[i]] = i;
		}
	}
	ll L = s.size();
	
	
	ll ai = 1, l = L;
	set<ll> seen;
	
	for (ll i = 0; i < n; i++) {			
		
		if (i) p[i] = p[i] +  p[i-1];
		dbg(i, d, l, ans, ms, mg, p, d[i], p[i]);
		if (seen.find(a[i]) != seen.end()) {
			dbg("continue");
			continue;
		}
		dbg(l, d[i] + p[i]);
		if (i == 5 && l == 2 && l == d[i] + p[i]) {
			cout << "Yeaaaaaaaaaah" << '\n';
			exit(0);
		}
		if (l == d[i] + p[i]) {
			cout << "entered\n";
			if (i == 5) exit(0);
			dbg("entered");
			ms.insert({a[i], i});
			mg.insert({a[i], i});
		}
		else {
			assert(l > d[i] + p[i]);
			pair<ll, ll> f;
			if (ai & 1) {
				f = *mg.begin();
			} else {
				f = *ms.begin();
			}
			for (ll i = ans.back() + 1; i <= f.second; i++) {
				ms.erase({a[i], i});
				mg.erase({a[i], i});
			}
			ans.pb(f.second);
			seen.insert(f.first);
			
			
			ai++;
			l--;
			// update p[i]
			if (last_pos[f.first] > i) { 
				dbg(f, i);
				p[i] += -1;
				p[last_pos[f.first]] += 1;
			}
			i--;
		}
		
	}
	
	if (true) {
		pair<ll, ll> f;
		while (true) {
			if (ai&1) {
				f = *mg.begin();
			} else {
				f = *ms.begin();
			}
			
			if (seen.count(f.first) > 0) {
				if (!mg.empty())
					mg.erase(mg.begin());
				if (!ms.empty())
					ms.erase(ms.begin());
				continue;
			} else {
				break;
			}
		}
		dbg(mg, ms);	
		ans.pb(f.second);
		dbg(f);
	}
	vector<ll> fans;
	for (ll i = 1; i < ans.size(); i++) {
		fans.pb(a[ans[i]]);
	}
	
	return fans;
}

int main() {
	//~ test();
	//~ return 0;
	
    int t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
		ll n;
		cin >> n;
		vector<ll> a(n);
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		auto res = solve(n, a);
		for (auto & x : res)
			cout << x << " ";
		cout << "\n";
    }
}
