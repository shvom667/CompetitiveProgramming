#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
#define SZ(x) (ll)x.size()
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
string fans = "No";
auto solve() {
    string s, x, y;
    cin >> s >> x >> y;

    ll c0x, c0y, c1x, c1y;
    c0x = c0y = c1x = c1y = 0;

    c0x = count(begin(x), end(x), '0');
    c1x = count(begin(x), end(x), '1');
    c1y = count(begin(y), end(y), '1');
    c0y = count(begin(y), end(y), '0');

    if (c0x == c0y) {
        fans = "Yes";
        return fans;
    }

    if (c1y == c1x) {
        fans = "No";
        return fans;
    }

    if (((abs(c0x - c0y) * SZ(s)) % abs(c1x - c1y)) > 0) {
        fans = "No";
        return fans;
    }

    ll len_t = 0;


    len_t = (abs(c0x - c0y) * SZ(s)) / abs(c1x - c1y);

    ll g = gcd(len_t, SZ(s));

    if (c0x * SZ(s) + c1x * len_t != c0y * SZ(s) + c1y * len_t) {
        fans = "No";
        return fans;
    }

    for (ll i = 0; i < SZ(s); i++) {
        if (s[i] != s[i % g]) {
            fans  = "No";
            return fans;
        }
    }

    fans = "Yes";
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
