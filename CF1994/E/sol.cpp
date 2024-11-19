#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
 
auto solve() {
    ll k; cin >> k;
    vector<ll> sz(k);
    for (ll i = 0; i < k; i++) {
        cin >> sz[i];
        for (ll j = 0; j < sz[i] - 1; j++) {
            ll x;
            cin >> x;
        }
    }
    ll fans = 0;
    for (ll i = 0; i < k; i++) {
        fans |= sz[i];
    }
    vector<ll> cnt(60, 0);
    dbg(sz);
    ll j = -1;
    for (ll bit = 59; bit >= 0; bit--) {
        for (ll i = 0; i < k; i++) {
            cnt[bit] += ((sz[i] & (1ll << bit)) > 0);
        }
        if (cnt[bit] >= 2) {
            if (j == -1) {
                j = bit;
            }
        }
    }
    dbg(j);
    if (j >= 0) {
        for (ll bit = 0; bit <= j; bit++) {
            fans |= (1ll << bit);
        }
    }

    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
