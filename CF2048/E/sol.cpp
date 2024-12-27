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
    ll n, m;
    cin >> n >> m;
    if (m <= 2 * n - 1) {
        cout << "YES\n";
        for (ll i = 1; i <= 2 * n; i++) {
            for (ll j = 1; j <= m; j++) {
                cout << ((i + j) % (2 * n)) / 2  + 1 << " ";
            }
            cout << '\n';
        }
    } else {
        cout << "NO\n";
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    solve();
	    // cout << res << "\n";
    }
    return 0;
}

/*



*/
