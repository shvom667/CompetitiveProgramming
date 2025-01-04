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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a(n + 1, 0), p(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        a[i] = s[i - 1] - '0';
        p[i] = p[i - 1] + a[i];
    }
    map<ll, ll> mp;
    for (ll i = 0; i <= n; i++) {
        p[i] = p[i] - i;
        mp[p[i]]++;
    }
    ll fans = 0;



    for (auto &[u, v] : mp) {
        fans += v * (v - 1) / 2;
    }
    return fans;
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
