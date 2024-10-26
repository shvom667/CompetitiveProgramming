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
const ll INF = 1e9;
auto solve() {
    ll n, q;
    cin >> n >> q;
    Vec<ll> coding(n, 0);
    vector<ll> ind[16];
    for (ll i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        dbg(a, b);
        if (a == 'B') {
            coding[i] ^= (1ll << 0);
        }
        if (a == 'G') {
            coding[i] ^= (1ll << 1);
        }
        if (a == 'Y') {
            coding[i] ^= (1ll << 2);
        }
        if (a == 'R') {
            coding[i] ^= (1ll << 3);
        }
        if (b == 'B') {
            coding[i] ^= (1ll << 0);
        }
        if (b == 'G') {
            coding[i] ^= (1ll << 1);
        }
        if (b == 'Y') {
            coding[i] ^= (1ll << 2);
        }
        if (b == 'R') {
            coding[i] ^= (1ll << 3);
        }
        ind[coding[i]].push_back(i);
    }

    vector<ll> fans;
    while (q--) {
        ll x, y;
        cin >> x >> y; --x; --y;
        if (x > y) swap(x, y);
        bool ok=false;
        for (ll bit = 0; bit < 4; bit++) {
            if ((coding[x]&coding[y]) & (1ll << bit)) {
                ok=true;
            }   
        }
        if (ok) {
            fans.push_back(y - x);
            continue;
        }
        ll cur = INF;
        for (ll c = 1; c < 16; c++) {
            if (__builtin_popcount(c) != 2) {
                continue;
            }
            if ((c & coding[x]) > 0 && (c & coding[y]) > 0) {
                auto it = upper_bound(ind[c].begin(), ind[c].end(), x);
                if (it != end(ind[c])) {
                    cur = min(cur, abs(x - *it) + abs(*it - y));
                }
                if (it != begin(ind[c])) {
                    auto jt = it;
                    jt--;
                    cur = min(cur, abs(x - *jt) + abs(*jt - y));
                }

            }
           
        }
        fans.pb(cur);
    }
    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        for (auto&x : res) {
            cout << (x >= 1e8 ? -1 : x) << "\n";
        }
    }
    return 0;
}
