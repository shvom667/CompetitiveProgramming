#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
/*
    Thinking is progress
    1. We can simulate in O(N * N)
    2. The initial vector a, doesn't matter
    3. Updates of smaller value must be considered.
*/
const ll INF = 1e18;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll q;
    cin >> q;
    vector<array<ll, 3>> Q;
    vector<vector<pair<ll, ll>>> G(n + 1);

    for (ll i = 1; i <= n; i++) {
        G[i].push_back({0, -1});
    }

    for (ll i = 0; i < q; i++) {
        ll l, r, u;
        cin >> l >> r >> u;
        Q.push_back({l, r, u});
        G[l].push_back({u, i});
        if (r + 1 <= n) {
            G[r + 1].push_back({-u, i});
        }
    }
    set<ll> gjs, bjs;

    // bjs should not be required

    ll prev_val = 0;
    for (ll i = 0; i < q; i++) {
        gjs.insert(i);
    }
    bjs.insert(INF);

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j < (ll)G[i].size(); j++) {
            G[i][j].first += G[i][j-1].first;
        }
    }

    for (ll i = 1; i <= n; i++) {
        dbg(G[i]);
    }

    vector<ll> fans;

    for (ll i = 1; i <= n; i++) {
        dbg(gjs, prev_val, bjs);
        ll cnt = 0;
        ll cur_min = INF;

        dbg(G[i]);
        ll prev_j = INF;
        for (ll j = G[i].size() - 1; j >= 0; j--) {
            // if (j > *bjs.begin()) continue;
            auto it = gjs.lower_bound(G[i][j].second);
            if (it == end(gjs)) {
                dbg("end1");
                continue;
            }
            if (*it == prev_j) {
                dbg("end2");
                continue;
            }
            dbg("end3");
            dbg(G[i][j].first, prev_val);
            cur_min = min(cur_min, G[i][j].first + prev_val);
            prev_j = *it;
        }


        dbg(cur_min, cnt);

        // now you need to update gjs & bjs here...

        prev_j = INF;
        vector<ll> erase;
        for (ll j = G[i].size() - 1; j >= 0; j--) {
            // if (j > *bjs.begin()) continue;
            auto it = gjs.lower_bound(G[i][j].second);
            if (it == end(gjs)) {
                continue;
            }
            if (*it == prev_j) {
                continue;
            }
            ll cur_val = G[i][j].first + prev_val;
            if (cur_val > cur_min) {
                auto jt = it;
                while (jt != end(gjs) && *jt != prev_j) {
                    erase.pb(*jt);
                    jt++;
                }
            }
            // cur_min = min(cur_min, G[i][j].first + prev_val);
            prev_j = *it;
        }

        for (auto&x : erase) {
            gjs.erase(x);
            bjs.insert(x);
        }

        prev_val = cur_min;
        fans.pb(cur_min);
    }

    for (ll i = 0; i < n; i++) {
        fans[i] += a[i];
    }
    dbg(fans);
    fans = min(fans, a);

    return fans;
}

auto bf() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        a[i] = 0;
    }
    Vec<ll> fans = a;
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll x, y, incr;
        cin >> x >> y >> incr;
        x--; y--;
        for (ll j = x; j <= y; j++) {
            a[j] += incr;
        }
        fans = min(fans, a);
    }
    for (ll i = 0; i < (ll)fans.size(); i++) {
        fans[i] += b[i];
    }
    return fans;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    // cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        for (auto&x : res) {
            cout << x << " ";
        }   cout << "\n";
    }
    return 0;
}
