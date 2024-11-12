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


pair<ll, ll> chmax (pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first * b.second > b.first * a.second) {
        
        return a;
    }
    return b;
}

const ll eps = 1e-10;

auto solve(ll n, vector<array<ll, 4>> a) {
    long double l = 0, r = 1e14;

    auto cond = [&] (long double mid) {
        long double fans = 0;
        for (ll i = 0; i < n; i++) {
            fans += max(a[i][0] - mid * a[i][1], a[i][2] - mid * a[i][3]);
        }
        return fans > 0;
    };
    ll itr = 2000;
    while (r - l > eps && itr--) {
        long double mid = l + (r - l) / 2;
        dbg(mid);
        if (cond(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(10) << r << "\n";
}

auto bf(ll n, vector<array<ll, 4>> a) {

    pair<ll, ll> fans;
    fans.first = 0;
    fans.second = 1;


    
    for (ll i = 0; i < (1ll << n); i++) {
        ll num = 0, den = 0;
        for (ll bit = 0; bit < n; bit++) {
            if (i & (1ll << bit)) {
                den += a[bit][3];
                num += a[bit][2];
            } else {
                den += a[bit][1];
                num += a[bit][0];
            }
        }
        fans = chmax(fans, make_pair(num, den));
    }

    dbg(fans);

    return fans;
}


auto cf() {
    long double eps = 1e-5;
    long double out = 3.736842105116;
    for (ll i = 1; i <= 100; i++) {
        for (ll j = 1; j <= 100; j++) {
            if (gcd(i, j) > 1) continue;
            long double ans = (long double)j / (long double)i;
            if (fabs(ans-out) < eps) {
                cout << j << " " << i << "\n";
            }
        }
    }
}

// void test() {
//         ll n;
//         n = rnd(1, 2);
//         vector<array<ll, 4>> a(n);

//         for (ll i = 0; i < n; i++) {
//             ll p, q, r, s; 
//             p = rnd(1, 10);
//             q = rnd(1, 10);
//             r = rnd(1, 10);
//             s = rnd(1, 10);
//             a[i] = {q, p, s, r};
//         }

//         auto sans = solve(n, a);
//         auto bans = bf(n, a);

//         if (sans.first * bans.second == sans.second * bans.first) {
//             cout << "OK\n";
//         } else {
//             dbg(n);
//             dbg(a);
//             dbg(sans);
//             dbg(bans);
//             cout << "Not Ok\n";
//             exit(0);
//         }
// }

int main() {

    // cf();
    // return 0;
    // while (true)
    // {
    //     test();
    //     /* code */
    // }
    
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        ll n; cin >> n;
        vector<array<ll, 4>> a(n);

        for (ll i = 0; i < n; i++) {
            ll p, q, r, s; cin >> p >> q >> r >> s;
            a[i] = {q, p, s, r};
        }

        solve(n, a);
        
        // dbg(res);
    }
    return 0;
}
