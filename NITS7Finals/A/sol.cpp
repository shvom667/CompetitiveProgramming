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

string Y = "YES";
string N = "NO";
auto solve() {
    ll n, t, k;
    cin >> n >> t >> k;
    if (n < k) {
        if (t <= 2 * n && t >= 2 && t != 2 && t != 2 * n) {
            return Y;
        } else {
            return N;
        }
    }
    if (n >= k) {
        if (t >= 0 && t <= 2 * (k - 1)) {
            if (n >= 2 * k)
                return Y;
            if (n < 2 * k) {
                if (t == 2 * (k - 1)) {
                    return N;
                }
                if (t == 0) {
                    return N;
                }
                // if (n > k) {
                //     if (t == 0) {
                //         return Y;
                //     }
                // }
                // if (t == 0) {
                //     if (n == k) {
                //         return N;
                //     }
                // }
                return Y;
            }
        } else {
            return N;
        }
    }

    return N;
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
