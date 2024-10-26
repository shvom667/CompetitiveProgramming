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
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (ll i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<ll> ());
    ll sum = 0, B = 0;
    for (ll i = 1; i < n; i+=2) {
        sum += a[i - 1];
        ll diff = min(k, a[i-1] - a[i]);
        // a[i] -= diff;
        k -= diff;
        sum += a[i] + diff;
        B += a[i] + diff;
    }
    if ((n-1)%2==0){
        sum += a[n-1];
    }
    return sum - 2 * B;
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
