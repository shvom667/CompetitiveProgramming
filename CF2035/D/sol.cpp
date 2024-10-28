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
    ll n;
    cin >> n;
    vector<ll> a(n), c2(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        while (a[i] % (1ll << c2[i]+1) == 0) {
            c2[i]++;
        }
    }
    dbg(c2);

    for (ll i = 1; i < n; i++) {
        c2[i] += c2[i - 1];
    }

    for (ll j = 0; j < n; j++) {
    }

    
    return 0;
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
