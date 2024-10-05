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

auto solve(ll n, ll k, vector<ll> a) {
    return 0;
}

auto bf(ll n, ll k, vector<ll> a) {
    ll M = *max_element(begin(a),end(a));
    ll S = accumulate(begin(a),end(a),0ll);

    ll L = (M - S%M);
    dbg(S, M);
    dbg(L, k);
    if (L <= k) {
        return min(n, S / M + (k - L) / M + (L>0));
    }
    else {
        ll l, r, fans=-1;
        l = S, r = S + k;
        dbg(l,r);
        for (ll s = n; s >= 1; s--) {
            ll L, R;
            L = l / s, R = r / s;
            dbg(s,L,R);
            if (R >= M) {
                if (L < R || l%s==0 || r%s==0)
                return s;
            }
        }
        // ll l, r, fans=-1;
        // l = S, r = S + k;
        // dbg(l, r);
        // for (ll v = M; ; v++) {
        //     for (ll i = l; i <= r; i++) {
        //         if (i % v == 0) {
        //             fans = i/v;
        //             goto jump;
        //         }
        //     }
        // }
        // jump:
        // return min(n,fans);
    }

}

auto stress() {
    // for (ll n = 1; n <= 1000; n++) {
    //     bool ok = true;
    //     for (ll i = 1; i <= n; i++) {
    //         for (ll j = n; j >= 1; j--) {
    //             if (i % j == 0) {
    //                 if (ok)
    //                     ok = (n%i == n%j);
    //                 break;
    //             }
    //         }
    //     }
    //     if (ok) {
    //         cout << "ok\n";
    //     } else {
    //         assert(false);
    //     }
    // }
    // ll n = 16;
    // for (ll i = 1; i <= n ; i++) {
    //     cout << i << " " << n % i << "\n";
    // }

        ll fans = 0;
    while (true) {
        ll l, r, k;
        k = rnd(20, 100000);
        l = rnd(k + 100000, k + 500000);
        r = rnd(l, l+100000 );
        for (ll v = k; ; v++) {
            for (ll i = l; i <= r; i++) {
                if (i % v == 0) {
                    if (v != k) {
                        // dbg(l, r, k, i, v);
                        // fans = max(fans)
                    }
                    fans = max(fans, v - k);
                    dbg(fans);
                    goto jump;
                }
            }
        }
        jump:
    }
    return;
}

int main() {
    // stress();
    // return 0;

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (auto& x: a) cin >> x;
        auto res = bf(n, k, a);
        cout << res << "\n";
    }
    return 0;
}
