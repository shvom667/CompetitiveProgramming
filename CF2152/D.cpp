#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
#include <functional>
#include <stack>

using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

// #ifndef ONLINE_JUDGE
// #include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
// #include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
// #else
// #define dbg(...) 42
// #define rnd(...) 42
// #endif


ll bc(ll x) {
    return __builtin_popcountll(x);
}

ll hb(ll x) {
    ll fans = 0;

    for (ll i = 0; i < 30; i++) {
        if ((1ll<<i)&x) {
            fans = i;
        }
    }
    return fans;
}

auto solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), p2(n, 0), p21(n, 0), e(n, 0), base(n, 0);


    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (bc(a[i]) == 1) {
            p2[i]++;
        }
        else if (bc(a[i]) == 2 && (a[i]&1)==1) {
            p21[i]++;
        } else {
            e[i]++;
        }
        base[i] = hb(a[i]);

        if (i) {
            p2[i] += p2[i-1];
            p21[i] += p21[i-1];
            e[i] += e[i-1];
            base[i] += base[i-1];
        }
    }

    auto get = [&] (ll l, ll r) {
        vector<ll>res;

        ll a, b, c, d;

        a = p2[r];
        if (l) {
            a -= p2[l-1];
        }
        b = p21[r];
        if (l) {
            b -= p21[l - 1];
        }
        c = e[r];
        if (l) {
            c -= e[l-1];
        }
        d = base[r];
        if (l) {
            d -= base[l - 1];
        }

        res.pb(a);
        res.pb(b);
        res.pb(c);
        res.pb(d);
        return res;
    };

    while(q--) {
        ll l, r; cin >> l >> r; l--; r--;

        auto res = get(l, r);

        ll fans = res[3];
        fans += (res[1]/2);
        fans += res[2];
        cout << fans << '\n';
    }

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		solve();
		// auto res = solve();
		// cout << res << "\n";
	}
	return 0;
}
