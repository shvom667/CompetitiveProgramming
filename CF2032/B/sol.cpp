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
    vector<ll> fans;
    if (n == 1) {
        fans.pb(1);
        return fans;
    }
    if (n >= 3) {
        if (k == 1 || k == n) {
            fans.pb(-1);
            return fans;
        }
    }
    if (k & 1) {
        fans.pb(1);
        fans.pb(k - 1);
        fans.pb(k + 2);
        return fans;
    }
    fans.pb(1);
    fans.pb(k);
    fans.pb(k + 1);
    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        if (res[0] == -1) {
            cout << -1 << "\n";
            continue;
        }
        cout << res.size() << "\n";
        for (auto&x : res) {
            cout << x << " ";   
        }   cout << "\n";
    }
    return 0;
}
