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
    ll M = m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
    }
    ll my = a[0];
    sort(begin(a),end(a));
    sort(begin(b),end(b));

    while (!b.empty() && b.back() > a.back()) {
        b.pop_back();
    }
    m = (ll)b.size();


    dbg(b);
    reverse(begin(b),end(b));
    dbg(b);
    while (!b.empty() && b.back() <= my) {

        b.pop_back();
    }
    reverse(begin(b),end(b));

    m = (ll)b.size();

    vector<ll> fans;

    // ll pos_gr = -1;
    // for (ll i = 0; i < m; i++) {
    //     if (b[i] > my) {
    //         pos_gr = i;
    //         break;
    //     }
    // }

    dbg(a);
    dbg(b);
    
    ll ie, is;
    for (ll k = 1; k <= M; k++) {
        // ie = m - 1;
        // is = max(M%k, m - k);
        ie = min(m - 1, (M % k) + k - 1);
        is = M % k;
        dbg(k, ie, is);

        ll cur = 0;
        dbg("$$$$$$", k);
        while (is >= M % k && is <= ie && ie <= m - 1 && is <= m - 1) {
            auto it = lower_bound(begin(a),end(a),b[is]);
            cur += end(a) - it;
            dbg(ie, is);

            if (is > m - 1) {
                break;
            }
            ie += k;
            is += k;
            // if (ie < (M%k)) break;
            if (is > m - 1) break;
            if (ie >= m - 1) ie = m - 1;
            // if (is < (M%k)) is = M%k;
        }

        fans.pb(cur + M / k);
    }
    
    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
        for(auto x : res) {
            cout << x << " ";
        }   cout << '\n';
    }
    return 0;
}
