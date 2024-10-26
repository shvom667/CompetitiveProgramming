#include<bits/stdc++.h>
using namespace std;
using ll=int;
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
    ll l, r, L, R;
    cin >> l >> r >> L >> R;
    if (max(L, l) > min(R, r)) {
        return 1;
    }
    if (L == l && R == r) {
        return R - L;
    }
    return min(R, r) - max(L, l) + 2 + (R == r ? -1 : 0) + (L == l ? -1 : 0);
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
