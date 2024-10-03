// #define ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
using ll = int;
#define ALL(x) begin(x), end(x)
#define pb push_back
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
auto print(auto a) {
    for (auto& x : a) {
        cout << x << " ";
    }   cout << "\n";
}
auto bf(auto n, auto a, auto q, auto x) {
    vector<ll> vals;
    auto calc = [&] (vector<ll> a) {
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
    };
    
    vals.push_back(calc(a));
    print(a);
    for (auto&v : x) {
        for (ll i = v - 1; i < n; i += v) {
            a[i] ^= 1;
        }
        print(a);
        vals.push_back(calc(a));
    }
    ll fans = 0;
    
    // dbg(vals);
    return vals;
    for (ll i = 1; i < vals.size(); i++) {
        fans+=vals[i];
    }
    // return fans;
}
/*
    How many times we have used it previously is what we want to know
*/

auto solve(auto n, auto a, auto q, auto x) {
    map<ll, ll> mp;
    vector<ll> vals;
    auto calc = [&] (vector<ll> a) {
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
    };
    
    vals.push_back(calc(a));

    vector<ll> cnt(n+1, 0);

    for (auto&v : x) {
        cnt[v]++;
        ll sum = 0;
        dbg(v);
        vector<ll> F;
        for (ll i = 1; i <= sqrt(v); i++) {

            dbg(i);
            if (v % i == 0) {
                ll fac = i;
                F.pb(i);
                // if (cnt[fac]&1) sum++;
                if (v / i != i) {
                    ll fac = v / i;
                    F.pb(v/i);
                    // if (cnt[fac]&1) sum++;
                }
            }
        }
        sort(begin(F),end(F));
        sum = 0;
        ll zero = 0, sex=0, fv = -1;
        dbg(F); 
        for (auto& f : F) {
            sum += cnt[f];
            ll actAs = -1;
            if (sum & 1) {
                if (a[f-1] == 0) {
                    actAs = 1;
                }  else {
                    actAs = 0;
                }
            } else {
                if (a[f-1] == 0) {
                    actAs = 0;
                } else {
                    actAs = 1;
                }
            }
            // if (actAs != zero) {
            //     zero = actAs;
            // }
            // if (actAs != zero) {
            //     sex++;
            //     zero=actAs; 
            // }
            sex ^= actAs;
            if (fv == -1) {
                fv = actAs;
            }
            dbg(f, actAs);
        }
        dbg(sum);
        dbg(zero);
        dbg(cnt);
        dbg(a);
        dbg(sex);
        fv = -1;
        if (mp[1]&1) {
            fv = (a[0]^1);
        }else{
            fv = a[0];
        }
        dbg(fv, zero);
        sex = fv == zero;
        if (sex&1) {
            if (zero == 0) {
                vals.push_back(vals.back() + 1);
            } else {
                vals.push_back(vals.back() - 1);
            }
        } else {
            if (zero == 0) {
                vals.push_back(vals.back() - 1);
            } else {
                vals.push_back(vals.back() + 1);
            }
        }
    }
    ll fans = 0;
    
    // dbg(vals);
    return vals;
    for (ll i = 1; i < vals.size(); i++) {
        fans+=vals[i];
    }
    // return fans;
}


mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}
auto stress1() {
    while (true) {
        ll n, q;
        n = rnd(2, 2);
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            a[i] = rnd(0,1);
        }
        q = rnd(1, 1);
        vector<ll> x(q);
        for (auto& y: x) {
            y = rnd(1, n);
        }
        auto bvals = bf(n, a, q, x);
        auto svals = solve(n, a, q, x);
        // bool ok = true;
        // for (ll i = 1; i < bvals.size(); i++) {
        //     if (abs(bvals[i] - bvals[i-1]) == 1) {

        //     } else {
        //         ok = false;
        //     }
        // }
        // if (ok) {
        //     cout << "ok\n";
        // } else {
        //     assert(false);
        // }
        if (bvals == svals) {
            cout << "ok\n";
        } else {
            cout << "not ok\n";
            dbg(n);
            dbg(a);
            dbg(q);
            dbg(x);
            dbg(bvals);
            dbg(svals);
            exit(0);
        }
        
    }
}

int main() {
    // stress1();
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
        auto bans = bf(n, a, q, x);
        auto sans = solve(n, a, q, x);
        dbg(bans, sans);
        for (auto& x : bans) {
            cout << x << " ";
        }   cout << "\n";
        for (auto& x : sans) {
            cout << x << " ";
        }   cout << "\n";
        // cout << "Case #" << tc << ": " << res << "\n";
    }
}
