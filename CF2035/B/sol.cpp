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
    cin >> n;
    if (n == 1) {
        return (string)"-1";
    }
    if (n == 2) {
        return (string)"66";
    }
    if (n == 3) {
        return (string)"-1";
    }
    if (n%2==0) {
        string res = "";
        for (ll i = 1; i <= n - 2; i++) {
            res += "3";
        }
        res += "66";
        return res;
    }
    string base = "36366";
    if (n >= 5) {
        string res = "";
        for (ll i = 0; i < n - 5; i++) {
            res += "3";
        }
        res += base;
        return res;
    }
    return base;
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
