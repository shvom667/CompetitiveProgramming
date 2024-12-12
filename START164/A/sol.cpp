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
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    ll ca;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            ca = a[i];
        } else {
            ca = (ca & a[i]);
        }
    }
    for (ll i = 0; i < n; i++) {
        a[i] ^= ca;
        mp[a[i]]++;
    }
    bool zero = false;
    for (auto&[u, v] : mp) {
        if (v >= 2) zero = true;
    }
    if (zero) {
        if (l <= 0 && r >= 0) {
            return "YES";
        }
        return "NO";
    }
    dbg(a);
    ll ce, co; ce = co = 0;
    bool ok = true;
    for (ll i = 0; i < n; i++) {
        if (a[i] > 1) {
            ok = false;
        }
        if (a[i]&1) co++;
        else ce++;
    }
    if (ok) {
        ll res = ce * co;
        // ll bf_res = 0;
        // for (ll i = 0; i < n; i++) {
        //     for (ll j = i + 1; j < n; j++) {
        //         bf_res += (a[i] ^ a[j]);
        //     }
        // }
        // dbg(res, bf_res);
        // assert(bf_res == res);
        if (res >= l && res <= r) {
            return "YES";
        } else {
            return "NO";
        }
    }
    if (n >= 50) {
        return "NO";
    }
    ll fans = 1;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            if ((a[i] ^ a[j]) > r) return "NO";
            fans *= (a[i] ^ a[j]);
            if (fans > r) {
                return "NO";
            }
        }
    }
    dbg(fans);
    if (fans >= l && fans <= r){
        return "YES";
    }
    return "NO";
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
