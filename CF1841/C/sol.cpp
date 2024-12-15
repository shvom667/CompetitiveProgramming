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

Vec<ll> p = {1, 10, 100, 1000, 10000};

auto solve() {
    string s;
    cin >> s;
    vector<ll> a((ll)s.size(), 0);
    ll n = (ll)a.size();
    for (ll i = 0; i < n; i++) {
        a[i] = s[i] - 'A';
    }
    dbg(a);
    ll smax = -1;
    vector<ll> suf_max(n, 0);
    Vec<ll> contri(n, 0);
    for (ll i = n - 1; i >= 0; i--) {
        if (a[i] >= smax) {
            contri[i] = p[a[i]];
        } else {
            contri[i] = -p[a[i]];
        }
        smax = max(smax, a[i]);
        suf_max[i] = smax;
    }
    dbg(contri);
    Vec<ll> pcontri = contri, scontri = contri;
    for (ll i = 1; i < n; i++) {
        pcontri[i] += pcontri[i - 1];
    }
    for (ll i = n - 2; i >= 0; i--) {
        scontri[i] += scontri[i + 1];
    }

    dbg(pcontri);
    dbg(scontri);

    ll fans = scontri[0];

    vector<ll> pos(5, 0), neg(5, 0);

    vector<ll> xcnt(5, 0);

    for (ll i = 0; i < n; i++) {

        for (ll new_val = 0; new_val < 5; new_val++) {
            ll cur_ans = 0;
            if (i + 1 < n) cur_ans = scontri[i + 1];
            if (i + 1 >= n || new_val >= suf_max[i + 1]) {
                cur_ans += p[new_val];
            } else {
                cur_ans -= p[new_val];
            }
            if (i - 1 >= 0)
                cur_ans += pcontri[i - 1];
            for (ll p_val = 0; p_val < 5; p_val++) {
                if (p_val < new_val && p_val < a[i]) continue;
                if (p_val >= a[i] && p_val >= new_val) continue;

                if (p_val < a[i] && p_val >= new_val) {
                    if (i + 1 < n && suf_max[i + 1] > p_val) {

                    } else {
                        dbg("hello");
                        // cur_ans += 2 * xcnt[p_val] * p[p_val];
                    }

                }
                if (p_val >= a[i] && p_val < new_val) {
                    //  - -- - - ++ + ++ + 
                    cur_ans -= 2 * pos[p_val] * p[p_val];
                }

                // if (p_val < new_val) {
                //     cur_ans -= 2 * pos[p_val] * p[p_val];
                // } else {
                //     // cur_ans += 2 * neg[p_val] * p[p_val];
                // }
            }
            dbg(cur_ans);
            fans = max(fans, cur_ans);
        } 

        if (contri[i] > 0) {
            pos[a[i]]++;
        } else {
            neg[a[i]]++;
        }
        for (ll j = 0; j < a[i]; j++) {
            xcnt[j] = 0;
        }
        xcnt[a[i]]++;

        dbg(xcnt);
    }



    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
