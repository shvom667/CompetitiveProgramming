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
ll g[21][21];
auto solve() {
    ll n;
    cin >>n;
    bool ok=true;
    for (ll i = 0; i < n; i++) {
        ll d, l, r, c;
        cin >> d >> l >> r >> c;
        if (d == 0) {
            for (ll y = c; y <= c + l - 1; y++) {
                g[r][y] += 1;
            }
        } else {
            for (ll x = r; x <= r + l - 1; x++) {
                g[x][c] += 1;
            }
        }
    }
    for (ll i = 1; i <= 10; i++) {
        for (ll j = 1; j <= 10; j++) {
            if (g[i][j] > 1) {
                return false;
            }
        }
    }
    for (ll i = 11; i <= 20; i++) {
        for (ll j = 1; j <= 20; j++) {
            if (g[i][j] > 0) {
                return false;
            }
        }
    }

    for (ll i = 1; i <= 20; i++) {
        for (ll j = 11; j <= 20; j++) {
            if (g[i][j] > 0) {
                return false;
            }
        }
    }

    return true;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T =1 ;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        string fans = res ? "Y\n" : "N\n";
        cout << fans << "\n";
    }
    return 0;
}
