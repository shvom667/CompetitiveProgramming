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

    deque<ll> a(n), b(m);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++) {
        cin >>b[i];
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));

    dbg(a);
    dbg(b);


    deque<pair<ll, ll>> opa, opb;

    Vec<ll> fans;

    ll res = 0;
    ll rem_1a = 0, rem_1b = 0;
    auto do_a = [&] () {
        res += a.back() - a[0];
        opa.pb({a[0], a.back()});
        a.pop_front();
        a.pop_back();
        rem_1b++;
    };
    auto do_b = [&] () {
        res += b.back() - b[0];
        opb.pb({b[0], b.back()});
        b.pop_front();
        b.pop_back();
        rem_1a++;
    };

    auto undo_a = [&] () {
        res -= opa.back().second - opa.back().first;
        opa.pop_back();
        res += b.back() - b[0];
        b.pop_back();
        b.pop_front();
        res += b.back() - b[0];
        b.pop_back();
        b.pop_front();
    };

    auto undo_b = [&] () {
        res -= opb.back().second - opb.back().first;
        opb.pop_back();
        res += a.back() - a[0];
        a.pop_back();
        a.pop_front();
        res += a.back() - a[0];
        a.pop_back();
        a.pop_front();
    };

    while ((ll)a.size() > rem_1a && (ll)b.size() > rem_1b) {
        if ((ll)a.size() - rem_1a == 1) {
            if ((ll)b.size() -rem_1b == 1) {
                break;
            } else {
                do_b();
                fans.pb(res);
            }
            continue;
        }
        if ((ll)b.size() - rem_1b == 1) {
            if ((ll)a.size() -rem_1a == 1) {
                break;
            } else {
                do_a();
                fans.pb(res);
            }
            continue;
        }

        if (a.back() - a[0] > b.back() - b[0]) {
            do_a();
            fans.pb(res);
        } else {
            do_b();
            fans.pb(res);
        }
    }

    dbg(a, rem_1a);
    dbg(b, rem_1b);

    // rem_1a=0;
    // rem_1b=0;
    dbg(opa);
    dbg(opb);

    dbg(fans);

    dbg((ll)a.size() - rem_1a + 1);

    while ((ll)a.size() - rem_1a + 1 >= 4 && !opb.empty()) {
        undo_b();
        rem_1a--;
        fans.pb(res);
    }

    while ((ll)b.size() -rem_1b + 1 >= 4 && !opa.empty()) {
        undo_a();
        rem_1b--;
        fans.pb(res);
    }


    dbg(fans);

    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto fans = solve();
        cout << (ll)fans.size() << '\n';
        for (auto x : fans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
