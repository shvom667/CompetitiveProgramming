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
    ll k;
    cin >> k;
    Vec<ll> a(n + 1, -1);
    ll val = 1;
    for (ll j = k; j <= n; j += k) {
        a[j] = val++;
    }
    for (ll i = 1; i <= n; i++) {
        if (a[i] == -1) {
            a[i] = val++;
        }
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
        for (ll i = 1; i < res.size(); i++) {
            cout << res[i] << ' ';
        }   cout << '\n';
    }
    return 0;
}
