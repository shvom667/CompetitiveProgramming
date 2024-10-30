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
    3. 
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
    for (ll i = 0; i < q; i++) {
        ll l, r, u;
        cin >> l >> r >> u;
        Q.push_back({l, r, u});
        G[l].push_back({u, i});
        if (r + 1 <= n) {
            G[r + 1].push_back({-u, i});
        }
    }
    set<ll> gjs;
    ll prev_val = 0;
    for (ll i = 0; i < q; i++) {
        gjs.insert(i);
    }

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
        dbg(gjs, prev_val);
        ll cnt = 0;
        ll cur_min = INF;
        for (auto& [u, j] : G[i]) {
            if (gjs.count(j) == 0) continue;
            cnt++;
            cur_min = min(cur_min, u + prev_val);
        }
        dbg(cur_min, cnt);
        if (cnt != gjs.size()) {
            if (cur_min < prev_val) {
                for (auto& [u, j] : G[i]) {
                    if (gjs.count(j) == 0) continue;
                    if (u + prev_val == cur_min) {
                        gjs.insert(j);
                    }
                }
                prev_val = cur_min;
            }
            if (cur_min > prev_val) {
                for (auto& [u, j] : G[i]) {
                    if (gjs.count(j) == 0) continue;
                    gjs.erase(j);
                }

                // prev_val remains same
            } 
            if (cur_min == prev_val) {
                for (auto& [u, j] : G[i]) {
                    if (gjs.count(j) == 0) continue;
                    if (u + prev_val > prev_val) {
                        gjs.erase(j);
                    }
                }
                // prev_val remains same
            }

        }
        if (cnt == gjs.size()) {
            // gjs.clear();
            set<ll> ngjs;
            for (auto& [u, j] : G[i]) {
                if (gjs.count(j) == 0) continue;
                if (u + prev_val == cur_min) {
                    ngjs.insert(j);
                }
            }
            gjs = ngjs;
            prev_val = cur_min;
        }

        fans.push_back(prev_val);
    }


    assert((ll)fans.size() == n);
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
        auto res = bf();
        for (auto&x : res) {
            cout << x << " ";
        }   cout << "\n";
    }
    return 0;
}
