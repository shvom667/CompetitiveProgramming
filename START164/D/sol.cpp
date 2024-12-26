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
    ll n;
    cin >> n;

    vector<vector<ld>> ans(n, vector<ld> (n, 0));

    ans[0][0] = 1;

    ld eps = 1e-18;

    for (ll i = 1; i < n; i++) {
        ll pcnt = 0;
        ll psum = 0;
        for (ll j = n - 1; j >= 1; j--) {
            ll cnt = 0;
            ll csum = 0;
            for (ll v = 9; v >= 0; v--) {
                if ((ld)v - ans[i - 1][j - 1] > eps) {
                    cnt++;
                }
            }
            ll diff_cnt = pcnt - cnt;
            ll diff_sum = psum - csum;
            ans[i][j] = ((ld)diff_sum) / ((ld)10) + ans[i-1][j-1];
        }
    }


    string s;
    cin >> s;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
