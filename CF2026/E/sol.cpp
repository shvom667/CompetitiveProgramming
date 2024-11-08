#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif


mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}

/* Hints
    maximum-matching
    Hopcroft-Karp algorithm
*/

auto solve(ll n, vector<ll> a) {
    sort(begin(a), end(a));
    ll fans = 0;
    for (int sh = 0; sh <= 100; sh++) {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ll o = 0;
                for (ll k = i; k <= j; k++) {
                    o |= a[k];
                }
                fans = max(fans, j - i + 1 - (ll)__builtin_popcount(o));
            }
        }
        shuffle(begin(a), end(a), rng);
    }

    return fans;
}

auto bf(ll n, vector<ll> a) {

    ll fans = 0;
    for (ll i = 0; i < (1ll << n); i++) {
        ll ans = 0;
        for (ll bit = 0; bit < n; bit++) {
            if (i & (1ll << bit)) {
                ans |= a[bit];
            }
        }
        fans = max(fans, (ll)__builtin_popcount(i)-(ll) __builtin_popcount(ans));
    }
    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll res;
        if (n >  15)
            res = solve(n , a);
        else
            res = bf(n, a); 
        cout << res << "\n";
    }
    return 0;
}
