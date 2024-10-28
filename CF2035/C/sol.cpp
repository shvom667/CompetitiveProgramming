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

vector<ll> p2;

auto solve(ll n) {
    if (n == 5) {
        vector<ll> fans;
        fans.pb(2);
        fans.pb(1);
        fans.pb(3);
        fans.pb(4);
        fans.pb(5);
        return fans;
    }
    if (binary_search(begin(p2), end(p2), n)) {
        auto fans = solve(n - 1);
        fans.pb(n);
        return fans;
    }
    if (n & 1) {
        auto fans = solve(n - 1);
        fans.pb(n);
        return fans;
    }
    if (n % 2 == 0) {
        ll good = -1;
        for (ll bit = 0; bit < 30; bit++) {
            if (n & (1ll << bit)){
                good = bit;
            }
        }
        dbg(n, good);
        vector<ll> fans(n);
        fans[n - 1] = (1ll << (good)) - 1;
        fans[n - 2] = n;
        fans[n - 3] = n - 1;
        ll itr = 0;
        for (ll i = 1; i <= n; i++ ) {
            if (i != fans[n-1] && i != fans[n-2] && i != fans[n-3]) {
                fans[itr++]=i;
            }
        }
        return fans;
    }
    vector<ll> fans;
    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       
    p2.pb(1);

    while (p2.back() <= 1e9) {
        p2.push_back(p2.back() * 2);
    }
    dbg(p2);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n;
        cin >> n;
        auto res = solve(n);
        ll fans = 0;
        for (ll i = 1; i <= res.size(); i++) {
            if (i&1) {
                fans &= res[i-1];
            } else {
                fans |= res[i-1];
            }
        }
        cout << fans << "\n";
        for (auto&x : res) {
            cout << x << " ";
        }   cout << "\n";
    }
    return 0;
}
