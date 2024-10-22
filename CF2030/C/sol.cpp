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
    char s[n];
    for (ll i = 0; i < n; i++) cin >> s[i];
    string no = "NO";
    string yes = "YES";
    if (s[0] == '1' || s[n - 1] == '1') {
        return yes;
    }
    for (ll i = 1; i < n; i++) {
        if (s[i] == s[i - 1] && s[i] == '1')
            return yes;
    }
    return no;
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
