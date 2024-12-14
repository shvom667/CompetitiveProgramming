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

auto solve() {
    ll n, k; string s;
    cin >> s >> k; n = s.size();

    ll len = n;
    for (ll j = 1; j <= n; j++) {
        if (k <= len) {
            return s[k-1];
        }
        ll rem = n - 1;
        for (ll i = 0; i < n; i++) {
            if (s[i]  > s[i + 1]) {
                rem = i;
                break;
            }
        }
        string ss = "";
        for (ll i = 0; i < n; i++) {
            if (i != rem) {
                ss += s[i];
            }
        }
        s = ss;
        k -= len;
        len--;
    }

    return '1';
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
