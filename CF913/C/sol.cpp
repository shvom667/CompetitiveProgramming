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
    ll n, L;
    cin >> n >> L;
    vector<ll> c(n);
    for (ll i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<ll> best(n, false);
    best[0] = true;

    ll best_val = 0;

    auto better = [&] (ll i) {
        return c[best_val] * (1ll << i) > (1ll << best_val) * c[i];
    };

    for (ll i = 1; i < n; i++) {
        if (better(i)) {
            best[i] = true;
            best_val = i;
        }
    }
    ll fans = 2e18;
    ll res = 0;
    for (ll i = n - 1; i >= 0; i--) {
        if (best[i]) {
            while (L >= (1ll << i)) {
                L -= (1ll << i);
                res += c[i];
            }
            fans = min(fans, res + c[i]);
        }
    }

    dbg(best);

    fans = min(fans, res);

    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
