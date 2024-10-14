#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CompetitiveProgramming/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif
 
auto solve() {
    return 0;
}

auto bf() {
    for (ll s = 19; s <= 19; s++) {
    // ll s = 11;
        ll fans = 0;
        for (ll i = 0; i < (1ll<<s); i++) {
            vector<ll> v(s, 0);
            for (ll b = 0; b < s; b++) {
                if (i & (1ll<<b)) {
                    for (ll k = b; k < s; k += b+1) {
                        v[k] ^= 1;
                    }
                }
            }
            ll cnt = count(begin(v),end(v),1);
            if (cnt <= s/5) {
                // for (ll b = 0; b < s; b++) {
                //     if (i & (1ll<<b)) {
                //         cout << "1";
                //     } else {
                //         cout << "0";
                //     }
                // }
                // cout << "\n";
                cout << i << "\n";
                fans++;
            }
        }
        cout << fans << "\n";
    }
}

int main() {


    bf();

    // ll T;
    // cin >> T;
    // for (ll tc = 1; tc <= T; tc++) {
    //     auto res = solve();
    //     cout << res << "\n";
    // }
    // return 0;
}
