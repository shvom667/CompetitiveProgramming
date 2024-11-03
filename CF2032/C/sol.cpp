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
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(begin(a), end(a));
    ll fans = n;
    if (a[0] + a[1] > a[n - 1]) {
        return 0ll;
    }
    for (ll i = 1; i < n - 1; i++) {
        auto it = lower_bound(begin(a), end(a), a[i] + a[i - 1]) - begin(a);
        dbg(i, it);
        ll cur = i + n - 1- it;
        fans = min(fans, cur);
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
