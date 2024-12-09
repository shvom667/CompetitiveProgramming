#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif
using ld = long double;

auto solve() {  
    ld c, m, p, v;
    cin >> c >> m >> p >> v;

    dbg(c, m, p, v);

    ld eps = 1e-16;

    function<ld(ld, ld, ld, ld)> f= [&](ld c, ld m, ld p, ld v) {

        ld res = 0;
        
        res += p * (1);

        dbg(1,c,m,p,v);
        if (m > eps) {

            ld diff;
            if (m - v > eps) {
                diff = v;
            } else {
                diff = m;
            }

            if (c > eps &&  p > eps) {

                res += m * (1 + f(c + diff / 2, m - diff, p + diff / 2, v));
            }
            else if (p > eps) {
                res += m * (1 + f(c, m - diff, p + diff, v));
            }
        }

        dbg(2,c,m,p,v);

        if (c > eps) {

            ld diff;
            if (c - v > eps) {
                diff = v;
            } else {
                diff = c;
            }

            if (m > eps &&  p > eps) {

                res += c * (1 + f(c - diff, m + diff / 2, p + diff / 2, v));
            }
            else if (p > eps) {
                res += c * (1 + f(c - diff, m, p + diff, v));
            }
        }

        return res;
    };


    return f(c, m, p, v);
  
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << fixed << setprecision(20) << res << "\n";
    }
    return 0;
}
