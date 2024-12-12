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
    if (!(n&1)) {
        cout << -1 << '\n';
        return  0;
    }
    vector<ll> a(n);
    ll l = 0, L=1, r = n-1,R=n - 1;
    // for (ll i = 0; i < n; i++) {
    //     if (i%2==0) {
    //         a[l++] = L++;
    //     } else {
    //         a[r--] = R--;
    //     }
    // }
    dbg(L,R);

    
    for (ll i = 0; i < n; i+=2) {
        a[i] = L;
        L+=2;
    }
    for (ll i = 1; i < n; i+=2) {
        a[i] = R;
        R-=2;
    }

    dbg(a);
    // if (n == 3) {
    //     a[0] = 1;
    //     a[1] = 2;
    //     a[2] = 3;
    // }

    auto check = [&] (vector<ll> v) {

        vector<ll> u = v;
        for (ll i = 1; i < n; i++) {
            u[i] += u[i - 1];
        }
        vector<ll> cnt(n, 0);
        for (ll i = 0; i < n; i++) {
            cnt[u[i]%(n + 1)]++;
        }
        cnt[0]++;
        bool ok = true;
        for (ll i = 0; i < n; i++) {
            if (cnt[i] >= 2) {
                ok = false;
            }
        }
        return ok;
    };

    // assert(check(a) == true);

    for (auto&x: a) {
        cout << x << ' ';
    }   cout << '\n';

    return 0;
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
