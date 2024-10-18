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
#endif
ll C[62][62];
auto solve(ll n, ll k, vector<ll> a, ll A, ll B) {    
    sort(begin(a),end(a));

    ll L, R;

    if (true) {
        ll l, r;
        l = 0, r = (1ll<<n);
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            ll sum = 0;
            for (ll bit = 0; bit < n; bit++) {
                if (mid & (1ll<<bit)) {
                    sum += a[bit];
                }
            }

            if (sum >= A) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        L = l;
    }
    if (true) {
        ll l, r;
        l = 0, r = (1ll<<n);
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            ll sum = 0;
            for (ll bit = 0; bit < n; bit++) {
                if (mid & (1ll<<bit)) {
                    sum += a[bit];
                }
            }

            if (sum <= B) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        R = r;
    }

    auto get = [&] (ll val, ll k) {
        if (val < 0) return 0ll;
        ll fans=0;
        ll suffix_bits=0;
        for (ll bit = 61; bit >= 0; bit--) {
            if (val & (1ll<<bit)) {
                ll choose = k - suffix_bits;
                if (choose < 0) {
                    break;
                }

                if (bit >= choose) {
                    dbg(bit, choose);
                    fans += C[bit][choose];
                }
                suffix_bits++;
            } else {

            }
        }
        if (__builtin_popcount(val) == k) fans++;
        // dbg(fans);
        return fans;
    };
    // dbg(L,R);
    // dbg(get(32,k), k);
    ll fans= get(R, k) - get(L-1, k);
    // return 0;
    dbg(fans);
    return fans;
}

auto bf2(ll n, ll k, vector<ll> a, ll A, ll B) {
    ll fans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            if (a[i] + a[j] >= A && a[i] + a[j] <= B) {
                fans++;
            }
        }
    }
    return fans;
}

auto bf3(ll n, ll k, vector<ll> a, ll A, ll B) {
    ll fans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            for (ll l = j + 1; l < n; l++) {
                if (a[i] + a[j] + a[l] >= A && a[i] + a[j] + a[l] <= B) {
                    fans++;
                }
            }
        }
    }
    return fans;
}


// auto stress2() {
//     ll itr= 0;
//     while (true) {
//         ll n = rnd(5, 20);
//         ll k = 2;
//         vector<ll> a(n);
//         a[0] = 1;
//         for (ll i = 1; i < n; i++) {
//             // cin >> a[i];
//             a[i] = a[i-1]*2+rnd(1,100);
//         }
//         ll A, B;
//         A = rnd(1, 500);
//         B = rnd(900,10000);
//         auto sans = solve(n, k, a, A , B);
//         auto bans = bf2(n, k, a, A, B);
//         if (sans == bans) {
//             dbg(sans, bans, itr);
//             cout << "OK\n";
//         } else {
//             dbg(n, k);
//             dbg(a);
//             dbg(A, B);
//             dbg(sans, bans);
//             cout << "NOT OK\n";
//             exit(0);
//         }
//         itr++;
//     }
// }


// auto stress3() {
//     ll itr= 0;
//     while (true) {
//         ll n = rnd(5, 20);
//         ll k = 3;
//         vector<ll> a(n);
//         a[0] = 1;
//         for (ll i = 1; i < n; i++) {
//             // cin >> a[i];
//             a[i] = a[i-1]*2+rnd(1,100);
//         }
//         ll A, B;
//         A = rnd(1, 100000);
//         B = rnd(A,10000000);
//         auto sans = solve(n, k, a, A , B);
//         auto bans = bf3(n, k, a, A, B);
//         if (sans == bans) {
//             dbg(sans, bans, itr);
//             cout << "OK\n";
//         } else {
//             dbg(n, k);
//             dbg(a);
//             dbg(A, B);
//             dbg(sans, bans);
//             cout << "NOT OK\n";
//             exit(0);
//         }
//         itr++;
//     }
// }

int main() {
	// ios_base::sync_with_stdio(0);cin.tie(0);       
    C[0][0] = 1;
    for (ll i = 1; i < 62; i++) {
        C[i][0] = 1;
    }
    for (ll i = 1; i < 62; i++){
        for (ll r = 1; r < 62; r++) {
            if (r <= i)
                C[i][r] = C[i-1][r] + C[i-1][r-1];
        }
    }
    // stress3();
    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        // solve();
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll  i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll A, B;
        cin >> A >> B;

        auto res = solve(n, k, a, A , B);
        cout << res << "\n";
    }
    return 0;
}
