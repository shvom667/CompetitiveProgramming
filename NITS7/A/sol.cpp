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
    ll n,m,r1,r2;
    
    cin >> n >> m >> r1 >> r2;
    if (n > m) swap(n, m); // n <= m
    
    if (r1 > r2) swap(r1, r2); // r1 <= r2
    if (2* r2 + 1 > n) return -1ll;
    if (2* r2 + 1 > m) return  -1ll;
    dbg(n, m);
    ll a1, a2;
    a1 = a2 = 1e18;
    dbg("hello");
    if (true) {
        ll x1, y1, x2, y2;
        x1 = y1 = r1 + 1;
        x2 = max(r2 + 1, 3*r1 + 3);
        y2 = r2 + 1;
        dbg(x1, y1, x2, y2);
        ll diff = x2 + r2 - m;
        if (diff > 0) {
            if (y2 + diff + r2 <= n) {
                x2 -= diff;
                y2 += diff;
            }
        }
        if (x2 + r2 <= m) {
            a1 = x1 + y1 + x2 + y2;
        }
    }


    // if (true) {
    //     ll x1, y1, x2, y2;
    //     x2 = y2 = r2 + 1;

    //     x1 = 2*r1 +  r2 + 3;
    //     y1 = r1 + 1;

    //     dbg(x1, y1, x2, y2);
    //     if (x1 + r1 <= m) {
    //         a2 = x1 + y1 + x2 + y2;
    //     }
        
    // }
    dbg(a1, a2);
    ll fans = min(a1, a2);

    if (fans < 1e18) {
        return fans;
    }

    return -1ll;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
