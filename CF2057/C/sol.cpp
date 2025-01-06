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
    ll l, r;
    cin >> l >> r;
    ll fans = 0;
    dbg(r & (1<<7));
    dbg(l & (1<<7));
    ll a = 0;
    ll b = 0;
    for (ll bit = 30; bit >= 0; bit--) {
        if ((r & (1 << bit)) > 0) {
            if ((l & (1 << bit)) == 0) {
                fans += (1 << bit+1) - 1;
                fans *= 2;
                // ll a, b, c;
                dbg(bit);
                a ^= (1 << bit);
                b = a - 1;
                ll c = r;
                for (ll j = r; j >= l; j--) {
                    if (j != a && j != b) {
                        c = j;
                        break;
                    }
                }
                dbg(a,b,c);
                cout << a << " " << b << " " << c << '\n';
                assert(fans == ((a^b) + (b^c) + (c^a)));
                // cout << (1 << bit) << " " <<  << " " << 
                // cout << fans << '\n';
                return 0;
            } else {
                a ^= (1 << bit);
                dbg(a);
            }
        }
    }
    return 0;
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
