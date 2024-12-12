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
    vector<ll> v;
    for (ll i = 1; i <= n; i++) v.pb(i);

    do {
        vector<ll> u = v;
        for (ll i = 1; i < n; i++) {
            u[i] += u[i - 1];
        }
        vector<ll> cnt(n, 0);
        for (ll i = 0; i < n; i++) {
            cnt[u[i]%(n + 1)]++;
        }
        cnt[0]++;
        bool ok = true;
        for (ll i = 0; i < n; i++) {
            if (cnt[i] >= 2) {
                ok = false;
            }
        }
        if (ok) {
            dbg(v);
            
        }
    } while (next_permutation(begin(v),end(v)));

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    solve();
	    // cout << res << "\n";
    }
    return 0;
}
