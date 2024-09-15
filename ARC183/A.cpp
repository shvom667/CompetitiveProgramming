#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void print(vector<ll> ans) {
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

vector<ll> genius(ll n, ll k);
vector<ll> solve(ll n, ll k);
int main() {
    ll n , k;
    cin >> n >> k;
    auto r = genius(n, k);
    print(r);
}
// int main() {
//     // cin.tie(nullptr)->sync_with_stdio(false);
//     ll t;
//     t = 1;

//     // brute force

//     for (ll n = 1; n <= 100; n++) {
//         for (ll k = 1; n * k <= 12; k++) {
//             vector<ll> act = genius(n, k);
//             vector<ll> bf = solve(n, k);
//             if (act == bf) {
//                 cout << "ok" << "\n";
//             } else {
//                 cout << "Failed : " << n << " " << k << "\n";
//                 print(act);
//                 print(bf);
//             }
//         }
//     }
//     return 0;
//     ll n, k;
//     cin >> n >> k;

//     vector<ll> act = genius(n, k);
//     vector<ll> bf = solve(n, k);

//     if (act == bf) {
//         cout << "ok" << "\n";
//     } else {
//         print(act);
//         print(bf);
//     }
// }

vector<ll> genius(ll n, ll k) {
    vector<ll> fans;
    ll r;
    if (n % 2 == 1) {
        r = k;
        while (r--) {
            fans.pb((n + 1) / 2);
        }
        vector<ll> oth;
        for (ll i = 1; i <= n; i++) {
            if (i == (n + 1) / 2) continue;
            r = k;
            while (r--) {
                oth.pb(i);
            }
        }
        if (n > 1) {
            fans.pb((n + 1) / 2 - 1);
        }
        for (ll i = n; i >= 1; i--) {
            if (i == (n + 1) / 2) {
                continue;
            }
            ll r = (i == (n + 1) / 2 - 1) ? k - 1 : k;
            while (r--) {
                fans.pb(i);
            }
        }
    }
    if (n % 2 == 0) {
        fans.pb(n / 2);
        for (ll i = n; i >= 1; i--) {
            r = (i != n / 2 ? k : k - 1);
            while (r--) fans.pb(i);
        }
    }
    return fans;
}
vector<ll> solve(ll n, ll k) {
    vector<ll> v;
    for (ll i = 1; i <= n; i++) {
        ll r = k;
        while (r--) {
            v.pb(i);
        }
    }

    vector<vector<ll>> res;
    do {
        res.push_back(v);

    } while (next_permutation(begin(v), end(v)));

    ll sz = res.size();
    return res[(sz - 1) / 2];
}

/*
if n is even:
    1 2 .. n/2

    n/2+1 ... n
    answer is The greates number n / 2 can form

if n is odd:
    1 2 3 .. (n-1)/2

    (n+1)/2 and it's median\

    1.2.3...(n-1)/2 intact

    (n + 1)/2 was present odd times.
    now it is present even times.


    (n+1)/2+1....n intact
    (n + 1) / 2 even terms left..
    then next term is again (n + 1) /

    (n+1)/2 + 1 .. n
*/