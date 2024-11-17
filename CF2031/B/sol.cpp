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
    ll n; cin >> n; vector<ll> b(n); for (ll i = 0; i < n; i++) cin >> b[i];

    function<bool(int)> dfs = [&] (int i) {
        dbg(i);
        if (i == 0) {
            return b[i] == 1;
        }
        if (i == 1) {
            return ((b[0] == 1 && b[1] == 2) || (b[0] == 2 && b[1] == 1));
        }
        if (b[i] == i + 1) {
            return dfs(i  - 1);
        }
        if (b[i] == i && b[i - 1] == i + 1) {
            return dfs(i - 2);
        }
        return false;
    };

    return dfs( n - 1);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << (res?"YES":"NO") << "\n";
    }
    return 0;
}
