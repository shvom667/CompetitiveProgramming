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
ll ub(ll x, ll y) {
    return (x + y -1) / y;
}
const ll inf = 2e18;
auto solve() {
    ll n, k, x; string s;
    cin >> n >> k >> x >> s;
    ll cnt = 0;
    vector<ll> f;
    for (ll i = 0; i < n; i++) {
        if (s[i] == 'a') {
            if (cnt > 0)
                f.pb(cnt);
            cnt=0;
        } else {
            cnt++;
        }
    }
    if (cnt > 0) 
        f.pb(cnt);
    dbg(f);

    ll sz = (ll)f.size();
    vector<ll> g(sz, -1);
    ll rem = x;
    dbg(rem);
    for (ll i = 0; i < sz; i++) {
        ll fans = 1;
        bool cont = false;
        for (ll j = i + 1; j < sz; j++) {
            if (fans >= inf / (f[j] * k + 1))  {
                cont = true;
            }
            dbg(j, f[j], k);
            fans *= f[j]*k + 1;
            if (fans > rem)
                cont = true;
            if (cont) break;
        }
        if (cont) {
            g[i] = 0;
            continue;
        }
        g[i] = max(0ll, ub(rem, fans)) - 1;
        rem -= g[i] * fans;
    }

    dbg(g);

    string fs = "";

    ll itrb = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == 'a') {
            if (i > 0 && s[i - 1] == '*') {
                for (ll j = 0; j < g[itrb]; j++) {
                    fs += 'b';
                }
                itrb += 1;
            }
            fs += 'a';
            continue;
        }
        if (s[i] == '*') {
            continue;
        }
        
    }
    dbg(itrb);
    dbg(sz);
    while (itrb < sz) {
        for (ll j = 0; j < g[itrb]; j++) {
            fs += 'b';
        }
        itrb++;
    }


    return fs;
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
