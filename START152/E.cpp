#define ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    apply(
        [&first](const auto &...args) {
            ((cerr << (first ? "" : ","), __print(args), first = false), ...);
        },
        t);
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
    if (sizeof...(T)) cerr << ", ";
    _print(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...)                                                    \
    cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; \
    _print(__VA_ARGS__)
#else
#define dbg(...)
#endif
ll get(vector<ll> u);
ll solve(ll n, vector<ll> v);
ll bf(ll n, vector<ll> v);
void print(vector<ll> v) {
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // ll n = 5;
    // vector<ll> v;
    // for (ll i = 1; i <= n; i++) v.pb(i);

    // do {
    //     dbg(v);
    //     ll bfans = bf(n,v);
    //     ll sans = solve(n,v);
    //     if (bfans != sans) {
    //         dbg(v, bfans, sans);
    //         assert(false);
    //     }
    // } while (next_permutation(begin(v), end(v)));

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << solve(n, v) << "\n";
    }
}

ll get(vector<ll> u) {
    ll n = u.size();
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i; j < n; j++) {
            bool ok = true;
            for (ll k = i + 1; k <= j; k++) {
                if (u[k] < u[k - 1]) ok = false;
            }
            if (ok) cnt++;
        }
    }
    return cnt;
}

ll bf(ll n, vector<ll> v) {
    ll fans = get(v);
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            vector<ll> u = v;
            swap(u[i], u[j]);

            fans = max(fans, get(u));
        }
    }
    return fans;
}

ll solve(ll n, vector<ll> v) {
    vector<ll> sm(n);
    vector<ll> gr(n);
    iota(begin(sm), end(sm), 0ll);
    gr = sm;
    for (ll i = 1; i < n; i++) {
        if (v[i] > v[i - 1]) {
            sm[i] = sm[i - 1];
        }
    }
    for (ll i = n - 2; i >= 0; i--) {
        if (v[i] < v[i + 1]) {
            gr[i] = gr[i + 1];
        }
    }

    ll res = 0;

    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        for (ll j = i; j < n; j++) {
            if (gr[i] >= j) {
                ans++;
            }
        }
    }
    res = ans;

    dbg(ans);

    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            ll fans = ans;

            if (true) {
                ll x = min(j - 1, gr[i]);
                fans -= (i - sm[i] + 1) * (x - i + 1);
                if (i == 2 && j == 3) dbg((i - sm[i] + 1) * (x - i + 1));
            }
            if (true) {
                ll x = max(i + 1, sm[j]);
                fans -= (gr[j] - j + 1) * (j - x + 1);
            }
            if (true) {
                if (gr[i] >= j) {
                    fans -= (i - sm[i] + 1) * (gr[j] - j + 1);
                }
            }
            if (i == 2 && j == 3) {
                dbg(fans);
            }
            if (true) {
                ll x, y;
                if (i > 0 && v[j] > v[i - 1]) {
                    x = sm[i - 1];
                } else {
                    x = i;
                }
                if (v[j] < v[i + 1]) {
                    y = gr[i + 1];
                } else {
                    y = i;
                }
                y = min(j - 1, y);

                fans += (y - i + 1) * (i - x + 1);
                if (i == 2 && j == 3) {
                    dbg(fans);
                }
            }

            if (true) {
                ll x, y;

                if (v[i] > v[j - 1]) {
                    x = sm[j - 1];
                } else {
                    x = j;
                }
                x = max(i + 1, x);
                if (j + 1 < n && v[i] < v[j + 1]) {
                    y = gr[j + 1];
                } else {
                    y = j;
                }

                fans += (y - j + 1) * (j - x + 1);
                if (i == 2 && j == 3) {
                    dbg(fans);
                }
            }

            if (true) {
                if (v[j] < v[i]) {
                    if (gr[i + 1] >= j - 1) {
                        if (v[j] <= v[i + 1] && v[i] >= v[j - 1]) {
                            ll x, y;
                            if (i > 0 && v[i - 1] < v[j]) {
                                x = sm[i - 1];
                            } else {
                                x = i;
                            }
                            if (j + 1 < n && v[j + 1] > v[i]) {
                                y = gr[j + 1];
                            } else {
                                y = j;
                            }
                            fans += (y - j + 1) * (i - x + 1);
                            if (i == 2 && j == 3) {
                                dbg(fans);
                            }
                        }
                    }
                }
            }

            res = max(res, fans);
        }
    }
    return res;
}
