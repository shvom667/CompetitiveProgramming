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
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    dbg(a);
    ll sm = 0;
    ll fans = 0;
    for (ll i = 0; i < n; i++) 
    {
        // dbg(i, sm);
        if (sm == 0) {
            fans += a[i]/3;
            sm += a[i]%3;
        }else{
            ll take_sm = min(sm, a[i] / 2);
            a[i] -= take_sm * 2;
            // dbg(i, take_sm);
            fans += take_sm;
            sm -= take_sm;
            fans += a[i]/3;
            sm += a[i]%3;
        }
        dbg(fans,sm);
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
