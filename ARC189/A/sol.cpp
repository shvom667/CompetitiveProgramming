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
const ll N = 2e5 + 20;
const ll mod = 998244353;

ll fact[N];
ll ifact[N];

ll modpow(ll a, ll b) {
    if (b == 0) return 1ll;
    if (b == 1) return a;

    ll res = modpow(a, b / 2);
    res *= res;
    res %= mod;
    if (b & 1) {
        res *= a;
        res %= mod;
    }

    return res;
};

ll inv(ll x) {
    return modpow(x, mod - 2);
}

auto solve() {
    ll n;
    cin >> n;
    Vec<ll> a(n), f(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> v;
    ll sz = 0;
    for (ll i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            if (sz > 0) v.pb(sz);
            sz = 1;
        } else {
            sz++;
        }
    }
    v.pb(sz);


    if (a[0] == 0) return 0ll;
    for(auto&x : v) if (x % 2 == 0) return 0ll;

    dbg(v);

    ll fans = 1;
    f[1] = 1;
    for(ll i = 3; i <= n; i+=2) {
        f[i] = f[i - 2] * (i - 2); 
        f[i] %= mod;
    }

    for(auto&x: v) {
        fans *= f[x];
        fans %= mod;
    }

    vector<ll> moves;
    ll total_moves = 0;

    for (auto&x : v) {
        moves.pb((x - 1)/2);
        total_moves += moves.back();
    }

    dbg(total_moves);
    dbg(moves);

    fans *= fact[total_moves];
    fans %= mod;

    for (auto&x : moves) {
        fans *= ifact[x];
        fans %= mod;
    }

    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    fact[0] = 1;
    for (ll i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }

    for (ll i = 0; i < N; i++) {
        ifact[i] = inv(fact[i]);
    }
    
    // for(ll i = 0; i < 10; i++) {
    //     cout << fact[i] << " ";
    // }   cout << "\n";
    // for(ll i = 0; i < 10; i++) {
    //     cout << ifact[i] << " ";
    // }   cout << "\n";

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}


/*
Case
n = 7
1 0 1 0 1 0 1

1 1 1 1 0 1 1

*/