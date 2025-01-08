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

auto solve(ll n, ll p, ll k) {
    assert(p >= 1 && p <= n);
    vector<ll> a(n + 1, 0);
    a[p] = 1;
    auto Q = [&] (ll l, ll r) {
        ll len = r - l + 1;
        ll ans = (p >= l && p <= r) ? 1 : 0;
        if (len >= k) ans ^= 1;
        return ans;
    };
    cout << n << endl;
    char c;
    cin >> c;
    if (c == "?") {
        ll l, r;
        cin >> l >> r;
        if (l > r || min(l, r) < 1 || max(l, r) > n) {
            cout << "Range Error\n";
            assert(false);
        } else {

        }
    }

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
