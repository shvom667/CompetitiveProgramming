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
    ll n,p,fans;
    cin >> n >> p;

    if (p == 0) {
        fans=__builtin_popcount(n);
        return fans;
    }
        for (ll k = 0; k <= 100; k++) {
            if (n - p * k >= k && __builtin_popcount(n - p * k) <= k) {
                return k;
            }
        }
        return -1ll;

    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
