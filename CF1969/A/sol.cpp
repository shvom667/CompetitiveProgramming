#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif
 
auto solve() {
    ll n;
    cin >> n;
    vector<ll> p (n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = i + 1; j <= n; j++) {
            if (p[i] == j &&  p[j] == i) {
                return 2;
            }
        }
    }

    return 3;

    return 4;
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
