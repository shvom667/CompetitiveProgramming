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
    return 0;
}

const ll N = 1e5;

auto bf() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll fans = 0;
    for (ll i = 0; i < (1ll << n); i++) {
        ll ans = 0;
        for (ll bit = 0; bit < n; bit++) {
            if (i & (1ll << bit)) {
                ans |= a[bit];
            }
        }
        fans = max(fans, (ll)__builtin_popcount(i)-(ll) __builtin_popcount(ans));
    }
    return fans;
}   

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = bf();
        cout << res << "\n";
    }
    return 0;
}
