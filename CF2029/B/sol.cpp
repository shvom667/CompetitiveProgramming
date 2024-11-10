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
    ll n;
    string s, r;
    cin >> n >> s >> r;
    ll c0, c1;
    c0 = c1 = 0;
    for (ll i = 0; i < n; i++) {
        c0 += s[i] == '0';
        c1 += s[i] == '1';
    }
    string no = "NO";
    string y = "YES";
    for (ll i = 0; i < n - 1; i++) {
        if (min(c0, c1) == 0) return no;
        c0 -= 1;
        c1 -= 1;
        c0 += r[i] == '0';
        c1 += r[i] == '1';
    }

    return y;
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
