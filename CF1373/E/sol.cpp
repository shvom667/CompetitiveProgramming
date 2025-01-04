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
    ll n, k;
    cin >> n >> k;
    if (k == 0) {
        string fans = "";
        while (n>9) {
            n -= 9;
            fans += "9";
        }
        if (n > 0) {
            fans += (char)('0' + n);
        }
        reverse(begin(fans),end(fans));
        cout << fans << '\n';
        return;
    }
    auto ezy = [&] (ll n) {
        string fans = "";
        while (n>9) {
            n -= 9;
            fans += "9";
        }
        if (n > 0) {
            fans += (char)('0' + n);
        }
        reverse(begin(fans),end(fans));
        return fans;
    };
    auto ezy2 = [&] (ll n) {
        string fans = "";
        if (n <= 8) {
            fans += (char)('0' + n);
            return fans;
        } else {
            n -= 8;
            fans += "8";
        }
        while (n>9) {
            n -= 9;
            fans += "9";
        }
        if (n > 0) {
            fans += (char)('0' + n);
        }
        reverse(begin(fans),end(fans));
        return fans;
    };
    k++;
    if (((k * (k - 1)) / 2) > n) {
        cout << -1 << '\n';
        return;
    }
    vector<string> res;
    dbg(n);
    dbg(k * (k -1 ) / 2);
    if ((n - (k * (k - 1) / 2)) % (k) == 0) {
        ll d = (n - (k * (k - 1) / 2)) / (k);
        dbg(d);
        ll x = min(10 - k, d);
        ll fy = d - x;
        string fans = ezy(fy);
        
        fans += (char('0' + x));
        // cout << fans << '\n';
        res.pb(fans);
    }

    dbg(res);
    ll nn = n;
    for (ll p = 1; p <= 9; p++)  {
        for (ll q = 1; q + p <= k; q++) {
            if (q + p == k) {
                ll extra = p * (p  - 1) / 2;
                extra += 45;
                extra -= (9 - q) * (10  - q) / 2;
                n = nn - extra;
                dbg(n);
                dbg(p);
                // now we solve q(fx) + p(f(x+1)) == n

                for (ll fx = 0; fx <= n; fx++) {
                    if ((n - q * fx) % p == 0) {
                        ll fxp = (n - q * fx) / p;
                        for (ll s9 = 0; s9 <= 16; s9++) {
                            ll fxd = fxp - 1;
                            if (fxd >= 0 &&
                                fx - 9 * s9 == fxd
                            ) {
                                dbg(p, q, fx, fxp, s9, fxd);
                                string fans = ezy2(fxd);
                                for (ll xx = 0; xx < s9; xx++) {
                                    fans += (char) ('0' + 9);
                                }
                                fans += (char) ('0' + 9 - q + 1);
                                res.pb(fans);
                            }   
                        }
                    }
                }

            }
        }
    }

    dbg(res);

    vector<ll> ff;
    for (auto x : res) {
        ff.pb(stoll(x));
    }
    if (ff.empty())
        cout << -1 << '\n';
    else {
        cout << *min_element(begin(ff),end(ff)) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        dbg(tc);
	    solve();
    }
    return 0;
}
