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


ll ask(ll l, ll r) {
    cout << "? " << l << " " << r << endl;
    ll fans;
    cin >> fans;
    if (fans == -1) {
        assert(false);
    }
    return fans;
}
void give(ll res) {
   cout << "! " << res << endl;
}

auto solve() {
    ll n;
    cin >> n;
    ll ans_l = 0, ans_r = 0, ans_mid = 0;
    ans_l = ask(1, n >> 2);
    ans_r = ask(n - (n >> 2) + 1, n);
    ans_mid = ask((n >> 2) + 1, n - (n >> 2));

    if (ans_l == 0 && ans_r == 0 && ans_mid == 0) { // k <= n / 2
        ll ans_left = ask(1, (n >> 1));
        if (ans_left == 1) { // contains all zero
            ll L = 1, R = (n  >> 1);
            ll SL = L, SR = R;
            auto cond = [&] (ll MID) {
                return ask(SL, SL + MID - 1) == 1;
            };
            while (L <= R) {
                ll MID = L + (R - L) / 2;
                if (cond(MID)) {
                    R = MID - 1;
                } else {
                    L = MID + 1;
                }
            }                
            give(L);
            return;

        } else { // contains all zero
            ll L = 1, R = (n >> 1);
            ll SL = (n >> 1) + 1, SR = n;
            auto cond = [&] (ll MID) {
                return ask(SL, SL + MID - 1) == 1;
            };
            while (L <= R) {
                ll MID = L + (R - L) / 2;
                if (cond(MID)) {
                    R = MID - 1;
                } else {
                    L = MID + 1;
                }
            }
            give(L);
            return;
        }
    }   

    if (ans_l == 0 && ans_r == 0 && ans_mid == 1) { // n / 2 < k
        ll L = (n >> 1) + 1, R = n;
        auto cond = [&] (ll MID) {
            if (MID >= (n >> 1) + (n >> 2)) {
                return ask(1, MID) == 0;
            }
            return ask((n >> 2) + 1, (n >> 2) + MID) == 0;
        };
        while (L <= R) {
            ll MID = L + (R - L) / 2;
            if (cond(MID)) {
                R = MID - 1;
            } else {
                L = MID + 1;
            }
        }
        give(L);
        return;
    }
    
    if (ans_l == 1 && ans_r == 1 && ans_mid == 0) { // k <= n / 4
        ll L = 1, R = (n  >> 2);
        ll SL = L, SR = R;
        auto cond = [&] (ll MID) {
            return ask(SL, SL + MID - 1) == 1;
        };
        while (L <= R) {
            ll MID = L + (R - L) / 2;
            if (cond(MID)) {
                R = MID - 1;
            } else {
                L = MID + 1;
            }
        }                
        give(L);
        return;
    }


    if (ans_l != ans_r && ans_mid == 0) {// k > n / 2
        // either one of l and r contains 1
        if (ask(1, (n >> 1)) == 1) { // left contains 1
            ll L = (n >> 1) + 1, R = n;
            auto cond = [&] (ll MID) {
                return ask(1, MID) == 0;
            };
            while (L <= R) {
                ll MID = L + (R - L) / 2;
                if (cond(MID)) {
                    R = MID - 1;
                } else {
                    L = MID + 1;
                }
            }
            give(L);
            return;
        } else { // right contains 1
            ll L = (n >> 1) + 1, R = n;
            auto cond = [&] (ll MID) {
                return ask(n - MID + 1, n) == 0;
            };
            while (L <= R) {
                ll MID = L + (R - L) / 2;
                if (cond(MID)) {
                    R = MID - 1;
                } else {
                    L = MID + 1;
                }
            }
            give(L);
            return;

        }
        
    }


    if (ans_l != ans_r && ans_mid == 1) { // k <= n / 2
        if (ask(1, (n >> 1)) == 1) { // left all zeroes
            ll L = 1, R = (n >> 1);
            auto cond = [&] (ll MID) {
                return ask(1, MID) == 1;
            };
            while (L <= R) {
                ll MID = L + (R - L) / 2;
                if (cond(MID)) {
                    R = MID - 1;
                } else {
                    L = MID + 1;
                }
            }               
            give(L);
            return;
        } else { // right all zeroes
            ll L = 1, R = (n >> 1);
            auto cond = [&] (ll MID) {
                dbg(MID);
                return ask(n - MID + 1, n) == 1;
            };
            while (L <= R) {
                dbg(L, R);
                ll MID = L + (R - L) / 2;
                if (cond(MID)) {
                    R = MID - 1;
                } else {
                    L = MID + 1;
                }
            }
            give(L);
            return;
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        // ll n;
        // cin >> n;
        solve();
    }
    return 0;
}
