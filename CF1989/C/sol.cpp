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
    ll n, a, b, c, d, x, y;
    cin >> n;
    a = b = c = d = x = y = 0;

    ll r[n][2];
    for (ll i = 0; i < n; i++) {
        cin >> r[i][0];
    }
    for (ll i = 0; i < n; i++) {
        cin >> r[i][1];
    }

    for (ll i = 0; i < n; i++) {
        ll p, q;
        p = r[i][0], q = r[i][1];
        if (p == 1 && q == 1) {
            c++;
        }
        if (p == 1 && q == -1) {
            a++;
        }
        if (p == -1 && q == 1) {
            b++;
        }
        if (p == -1 && q == -1) {
            d++;
        }
        if (p == 0 && q == 1) {
            b++;
        }
        if (p == 1 && q == 0) {
            a++;
        }
        
    }
    ll diff = (b + c - d - a)/ 2;
    
    ll fans = -1e9;
    dbg(a, b, c, d);
    for (ll diff = -d; diff <= c; diff++) {
        fans = max(fans, min(a + diff, b + c - d - diff));
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
