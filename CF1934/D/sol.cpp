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

    ll sb = __builtin_popcountll(n);

    auto AliceTurn = [&] (ll n) {
        ll sb = __builtin_popcountll(n);
        assert(sb % 2 == 0);

        ll hb = -1;
        for (ll i = 0; i < 63; i++) {
            if ((1ll << i) & n) {
                hb = i;
            }
        }
        ll a = (1ll << hb);
        ll b = n ^ a;
        cout << a << " " << b << endl;
    };

    auto BobTurn = [&] () {
        ll p1, p2;
        cin >> p1 >> p2;
        if (p1 == p2 && p2 == 0) {
            return -1ll;
        }
        ll bp1, bp2;
        bp1 = __builtin_popcountll(p1);
        bp2 = __builtin_popcountll(p2);
        if (bp1 % 2 == 0) {
            return p1;
        }
        return p2;
    };

    dbg(sb);

    if (sb & 1) {
        // first person loses
        cout << "second" << endl;
        
        ll itr = 1;
        while (true) {
            if (itr % 2 == 0) {
                AliceTurn(n);
            } else {
                n = BobTurn();
                if (n == -1) {
                    return;
                }
            }
            itr++;
        }


    } else {
        // first person wins 
        // even number of bits as input
        cout << "first" << endl;

        ll itr = 0;
        while (true) {
            if (itr % 2 == 0) {
                AliceTurn(n);
            } else {
                n = BobTurn();
                if (n == -1) {
                    return;
                }
            }
            itr++;
        }

    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
    }
    return 0;
}
