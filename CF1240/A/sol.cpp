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
    ll n;
    cin >> n;
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
    }
    ll x, a, y, b, k;
    cin >> x >> a >> y >> b >> k;

    ll L, R;
    L = 0, R = n;

    sort(begin(p),end(p),greater<ll>());

    ll ab = a * b / gcd(a,b);
    dbg(ab);

    auto cond = [&] (ll mid) {
        ll itr = 0;
        ll res = 0;
        for (ll v = ab; v <= mid; v+=ab) {
            res += (p[itr++] / 100) * (x + y);
        }
        dbg(res);
        if (x >= y) {
            for (ll v = a; v <= mid; v += a) {
                if (v % ab == 0) continue;
                res += (p[itr++] / 100) * x;
            }
            for (ll v = b; v <= mid; v += b) {
                if (v % ab == 0 || v % a == 0) continue;
                res += (p[itr++] / 100) * y;
            }
        } else {
            for (ll v = b; v <= mid; v += b) {
                if (v % ab == 0) continue;
                res += (p[itr++] / 100) * y;
            }
            dbg(res);
            for (ll v = a; v <= mid; v += a) {
                if (v % ab == 0 || v % b == 0) continue;
                res += (p[itr++] / 100) * x;
            }
            dbg(res);
        }
        return res >= k;
    };

    // auto res = cond(6);
    // exit(0);

    while (L <= R) {
        ll mid = L + (R - L) / 2;
        if (cond(mid)) {
            R = mid - 1;
        }else{
            L = mid + 1;
        }
    }

    if (L > n) {
        return -1ll;
    }
    return L;
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
