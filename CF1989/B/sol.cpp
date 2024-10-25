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
    ll n, m;
    string a, b;
    cin >> a >> b;
    n = a.size(), m = b.size();
    ll max_common = 0;
    for (ll i = 0; i < m; i++) {
        ll j = i;
        for (ll k = 0; k < n; k++) {
            if (j < m && b[j] == a[k]) {
                j++;
            }
        }
        max_common = max(max_common, j - i);
    }
    return n + m - max_common;
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
