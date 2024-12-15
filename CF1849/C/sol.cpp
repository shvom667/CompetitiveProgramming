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

    for (ll i = 0; i < n; i++) {
        sort(begin(qr[i]), end(qr[i]));
    }

    Vec<ll> next_one(n, n + 1), prev_zer(n, -1);

    for (ll i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            next_one[i] = i;
        } else {
            if (i + 1 < n)
                next_one[i] = next_one[i + 1];
        }
    }
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') {
            prev_zer[i] = i;
        } else {
            if (i - 1 >= 0) {
                prev_zer[i] = prev_zer[i - 1];
            }
        }
    }

    vector<ll> mins(n, 0);
    for (ll i = 1; i < n; i++) {
        if (s[i] >= s[i - 1]) {
            mins[i] = mins[i - 1];
        } else {
            mins[i] = i;
        }
    }

    auto sorted = [&] (ll l, ll r) {
        return mins[r] <= l;;
    };
    auto cnt_0 = [&] (ll l, ll r) {
        ll fans = p0[r];
        if (l - 1 >= 0) {
            fans -= p0[l - 1];
        }
        return fans;
    };
    dbg(qr);

    bool is_sorted = false;
    ll fans = 0;
    // for (ll i = 0; i < n; i++) {
    //     ll cnt_zer = 0;
    //     for (auto&y : qr[i]) {
    //         if (sorted(i, y))  {
    //             dbg("sorted", i , y);
    //             is_sorted = true;
    //             cnt_zer = 0;
    //         } else {
    //             // ll cur_cnt_zer = cnt_0(i, y);

    //             // if (cur_cnt_zer > cnt_zer) {
    //             //     fans++;
    //             //     dbg(i, y);
    //             //     cnt_zer = cur_cnt_zer;
    //             // }
    //             ll n1 = next_one[i];
    //             ll p0 = 
    //         }
    //     }
    // }

    sort(begin(Q),end(Q), [&] (auto x, auto y) {
        return x.second - x.first < y.second - y.first;
    });

    set<pair<ll, ll>> st;

    for (auto& [i, y] : Q) {
        if (sorted(i, y))  {
            dbg("sorted", i , y);
            is_sorted = true;
        } else {
            ll n1 = next_one[i];
            ll p0 = prev_zer[y];
            if (st.find({n1, p0}) == st.end()) {
                st.insert({n1, p0});
                fans++;
            }
        }
    }

    if (is_sorted) fans++;
    return fans;
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
