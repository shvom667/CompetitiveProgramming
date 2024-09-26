#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto print(auto x) {
    for (auto& y : x) {
        cout << y << " ";
    }   cout << '\n';
}

auto solve(ll n, vector<ll> a) {
    ll fans = 0;
    for (ll i = 0; i < n; i++) {
        if (i) {
            a[i] ^= a[i-1];
        }
    }
    set<ll> s;
    s.insert(0);
    for (ll i = 0; i < n; i++) {
        if (s.find(a[i]) != s.end()) {
            fans++;
            s.clear();
            s.insert(a[i]);
            continue;
        }
        if (s.find(a[i]) == s.end()) {
            s.insert(a[i]);
            continue;
        }
    }
    return n - fans;
}

auto solve2(ll n, vector<ll> a) {
    ll fans = 0;
    for (ll i = 0; i < n; i++) {
        if (i) {
            a[i] ^= a[i-1];
        }
        if (a[i] == 0) {
            fans++;
        }
    }
    return n - fans;
}

auto printBits(ll n, vector<ll> a) {
    ll B = 15;
    for (ll i = 0; i < n; i++) {
        for (ll b = 0; b <= B; b++) {
            if ( a[i] & (1ll<<b) ) {
                cout << '1';
            } else {
                cout << '0';
            }
        }
        cout << '\n';
    }
}


mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}

auto stress() {
    while (true) {
        ll n;
        n = 500;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            a[i] = rnd(1, 2000);
        }
        auto res0 = solve(n, a);
        auto res1 = solve2(n, a);
        if (res0 != res1) {
            cout << "not ok\n";
            cout << res0 << " " << res1 << "\n";
        } else {
            cout << "ok\n";
        }
    }
}

int main() {
    //stress();
    //return 0;

    int t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        //printBits(n, a);
        //return 0;
        auto res0 = solve(n, a);
        auto res1 = solve2(n, a);
        cout << res0 << "\n";
    }
}
