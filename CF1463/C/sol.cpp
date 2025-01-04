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
    ll n; cin >> n; vector<ll> t(n), x(n);
    for (ll i = 0; i < n; i++) cin >> t[i] >> x[i];
    vector<bool> exe(n, false);
    ll pt = 0, ppos = 0, pmovet = 0;
    for (ll i = 0; i < n; i++) {
        if (pt + pmovet > t[i]) {
            continue;
        } else {
            pt = t[i];
            exe[i] = true;
            pmovet = abs(x[i] - ppos);
            ppos = x[i];
        }
    }

    dbg(exe);

    ll fans = 0;
    ll dir = 1;

    pt = 0, ppos = 0, pmovet = 0;

    auto F = [&] (ll T) {
        if (T > pt + pmovet) {
            return ppos;
        }
        return ppos - (pt + pmovet - T) * dir;
    };


    for (ll i = 0; i < n - 1; i++) {
        if (exe[i]) {
            pt = t[i];
            pmovet = abs(x[i] - ppos);
            if (x[i] > ppos) dir = 1;
            else dir = -1;
            ppos = x[i];


            ll sp = F(t[i]);
            ll ep = F(t[i + 1]);
            dbg(sp, ep);
            if (x[i] <= max(sp, ep) && x[i] >= min(sp, ep)) {
                dbg(i);
                fans++;
            }

            continue;
        } else {
            ll sp = F(t[i]);
            ll ep = F(t[i + 1]);
            if (x[i] <= max(sp, ep) && x[i] >= min(sp, ep)) {
                fans++;
            }
        }
    }
    dbg(fans);
    dbg(ppos);
    if (!exe[n - 1]) {
        
        ll sp = F(t[n - 1]);
        ll ep = ppos;
        if (x[n - 1] <= max(sp, ep) && x[n - 1] >= min(sp, ep)) {
            fans++;
        }

            // if (dir == -1) {
            //     if (x[n - 1] <= ppos) {
            //         fans++;
            //     }
            // } else {
            //     if (x[n - 1] >= ppos) {
            //         fans++;
            //     }
            // }
    } else {
        fans++;
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
