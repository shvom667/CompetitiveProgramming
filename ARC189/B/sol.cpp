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
    Vec<ll> x(n);
    for (ll i = 0; i < n; i++) 
    {
        cin >> x[i];
    }

    set<ll> s;
    for (ll i = 0; i < n; i++) {
        s.insert(x[i]);
    }   
    ll fans = 0;
    vector<ll> final_vec;
    while (s.size() >= 4) {
        auto it = s.begin();
        auto m0 = *it;
        auto m1 = *(++it);
        auto m2 = *(++it);
        auto m3 = *(++it);
        dbg(m0, m1, m2, m3);
        if (m3 + m0 <= m1 + m2) {
            s.erase(m1);
            s.erase(m2);

            s.insert(m0 + m3 - m2);
            s.insert(m0 + m3 - m1);
        }
        dbg(*s.begin());
        final_vec.push_back(*s.begin());
        fans += *s.begin();
        s.erase(*s.begin());
    }
    for (auto&x : s) {
        final_vec.push_back(x);
        dbg(x);
        fans += x;
    }

    for (ll i = 0; i < n - 3; i++) {

    dbg(final_vec);        // assert(final_vec[i] + final_vec[i + 3] >= final_vec[i + 1] + final_vec[i + 2]);
    }


    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
