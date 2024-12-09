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
    vector<ll> a(n), p(n), pos;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = a[i];
        if (i) {
            p[i] += p[i - 1];
        }
        if (a[i] == 0) {
            pos.pb(i);
        }
    }
    ll res = 0;
    map<ll, ll> mp;
    for (ll i = n - 1; i >= 0; i--) {
        mp[p[i]]++;

        if (!pos.empty() && pos.back() == i) {
            ll fans = 0;
            for(auto&[u,v]:mp){
                fans=max(fans,v);
            }
            res += fans;
            mp.clear();
            pos.pop_back();
        }
    }

    res += mp[0];

    return res;
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
