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
 
auto solve() {
    string s;
    cin >> s;
    ll fans = 0;
    ll n = s.size();
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') {
            fans += i - cnt + 1;
            if (i - cnt + 1 == 1) {
                fans--;
            }
            cnt++;
        }
    }
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
