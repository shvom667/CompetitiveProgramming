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
 
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1, 0), aa(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        aa[i] = a[i];
        aa[i] *= i;
        if (i) {
            a[i] += a[i - 1];
            aa[i] += aa[i - 1];
        }
    }
    auto trinity = [&] (ll x, ll y) {
        return (1 + x + y) * (a[x + y] - a[x - 1]) - (aa[x + y] - aa[x - 1]);
    };


    vector<ll> T(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        T[i] = trinity(i, n - i);
        if (i) {
            T[i] += T[i - 1];
        }
    }

    auto f = [&] (ll x) {
        return x * n - ( (x) * (x - 1) ) / 2;
    };

    auto get = [&] (ll q) {
        ll L = 0, R = n;
        while (L <= R) {
            ll mid = L + (R - L) / 2;

            if (f(mid) <= q) {
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        if (f(R) == q) {
            return T[R];
        }

        assert(q > f(R));

        ll diff = q - f(R);
        ll sp, ep;

        sp = R + 1;
        ep = R + q - f(R);

        ll X = sp;
        ll Y = ep - sp;
        return T[R] + trinity(X, Y);
    } ;

    ll Q;
    cin >> Q;

    vector<ll> fans;
    for (ll itr =1 ; itr <= Q; itr++) {
        ll l, r;
        cin >> l >> r;
        ll res = get(r);
        if (l > 1) {
            res -= get(l - 1);
        }
        fans.pb(res);
    }

    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;

    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        for (auto& x : res) {
            cout << x << "\n";
        }
    }
    return 0;
}
