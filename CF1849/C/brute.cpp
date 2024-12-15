#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

auto solve() {
    ll n, m;

    cin >> n >> m;
    string s;
    cin >> s;

    Vec<ll> p0(n, 0), p1(n, 0);

    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') {
            p0[i] = 1;
        }
        if (s[i] == '1') {
            p1[i] = 1;
        }
        if (i) {
            p0[i] += p0[i - 1];
            p1[i] += p1[i - 1];
        }
    }

    vector<pair<ll, ll>> Q;
    vector<Vec<ll>> qr(n, vector<ll> ());



    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        --u;--v;
        dbg(u,v);
        Q.pb({u, v});
        qr[u].pb(v);
    }

    set<string> f;
    for (auto&[x, y]: Q) {
        string ss = s;
        sort(begin(ss) + x, begin(ss) + y + 1);
        f.insert(ss);
    }

    ll res = (ll) f.size();
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
