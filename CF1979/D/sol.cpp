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
auto solve(ll n, ll k, vector<char> s) {
	char p = '$';
	ll j = 0;
	for (ll i = 0, cnt = 0; i < n; i++) {
		if (s[i] == p) {
			cnt++;
		} else {
			if (cnt == k || i == 0) {
				cnt = 0;
				cnt++;
				p = s[i];
			} else {
				if (cnt > k) {
					j = i - k;
					break;
				} else {
					j = i;
					break;
				}
			}
		}
		dbg(i, cnt);

	}

	auto valid = [&] (vector<char> ss) {
		bool ok = true;
        dbg(ss);
        char p = '$';
        ll cnt = 0;
		for (ll i = 0; i < n; i++) {
			if (ss[i] == p) {
				cnt++;
			} else {
				if (cnt == k || i == 0) {
					cnt = 0;
					cnt++;
					p = ss[i];
				} else {
					ok = false;
				}
			}
		}
		if (cnt != k) {
			ok = false;
		}
		return ok;
	};
	vector<char> ss = s;
	reverse(ss.begin() + j, ss.end());
	if (valid(ss)) {
		return (j == 0 ? n : j);
	} 
	return -1ll;
}

auto bf(ll n, ll k, vector<char> s) {
	ll fans = -1;
	for (ll j = 0; j < n; j++) {
		vector<char> ss = s;
		reverse(ss.begin()+j,ss.end());
		char p = '$';
		bool ok = true;
        dbg(ss);

        ll cnt = 0;
		for (ll i = 0; i < n; i++) {
			if (ss[i] == p) {
				cnt++;
			} else {
				if (cnt == k || i == 0) {
					cnt = 0;
					cnt++;
					p = ss[i];
				} else {
					ok = false;
				}
			}
			dbg(i, cnt);

		}
		if (cnt != k) {
			ok = false;
		}
		dbg(ok);
		if (ok) {
			dbg("hello", j);
			fans = j;
		}
		dbg(fans);
	}
	if (fans == 0) fans = n;
	return fans;
}


mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}
auto stress() {
	while(true){
		ll n = rnd(5, 10);
		ll k = 11;
		while (n % k > 0) {
			k = rnd(1, 10);
		}
		vector<char> s(n);
		for(ll i = 0; i < n; i++) {
			if ((i / k) % 2 == 0) {
				s[i] = '0';
			}else{
				s[i] = '1';
			}
		}
		do {
	        auto sans = solve(n, k, s);
	        auto bans = bf(n, k, s);
	        // cout << sans << " " << bans << "\n";
	        if ((sans != -1) == (bans != -1)) {
	        	cout << "ok\n";
	        } else {
	        	cout << n << " " << k << "\n";
	        	for (auto&v:s){
	        		cout<<v;
	        	}	cout<<"\n";
	        	cout << sans << " " << bans << "\n";
	        	exit(0);
	        }
		}	while (next_permutation(begin(s), end(s)));
	}
}


int main() {
	// stress();
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
    	ll n, k;
    	cin >> n >> k;
    	vector<char> s(n);
    	for (auto&c : s) cin >> c;
        auto sans = solve(n, k, s);
        // auto bans = bf(n, k, s);
        // cout << sans << " " << bans << "\n";
    	cout << sans << "\n";
    }
    return 0;
}
