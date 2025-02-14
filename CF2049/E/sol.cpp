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

ll gn, gp, gk;
ll TotQ = 0;
ll ask(ll l, ll r) {
    TotQ++;
    if (TotQ > 33) {
        assert(false);
    }
    // dbg(l ,r);
    // cout << "? " << l << " " << r << endl;
    // ll fans;
    // cin >> fans;
    // return fans;
    // dbg(l, r);
    auto Q = [&] (ll l, ll r) {
        ll len = r - l + 1;
        ll ans = (gp >= l && gp <= r) ? 1 : 0;
        if (len >= gk) ans ^= 1;
        return ans;
    };
    if (l > r || min(l, r) < 1 || max(l, r) > gn) {
        cout << "Range Error\n";
        assert(false);
    }
    ll res =  Q(l, r);

    dbg(l, r, res);

    return res;
}
void give(ll res) {
    if (res == gk) {
        cout << "Ok\n";
    } else {
        cout << "Final answer not correct";
        assert(false);
    }
   cout << "! " << res << endl;
}

auto solve(ll n) {
    // ll n;
    // cin >> n;
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
        }
    }
}



auto test(ll n, ll p, ll k) {
    gn = n;
    gp = p;
    gk = k;
    TotQ = 0;
    // gn = 8;
    // gp = 1;
    // gk = 2;
    cout << gn << " " << gp << " " << gk << '\n';
    solve(n);
    if (TotQ > 33) {
        assert(false);
    }
    return true;
}

auto bf() {
    while (true) {
        ll n, p, k;
        n = 4;
        p = rnd(1, n);
        k = rnd(2, n - 1);
        dbg(n,p, k);
        cout << TotQ << '\n';
        bool test_res =  test(n, p, k);
        
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    bf();

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}
