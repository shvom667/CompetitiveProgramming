#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CompetitiveProgramming/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif
 
auto solve() {
    ll n,sum=0,x,M=0;
    cin >> n >> x;
    for (ll i = 0; i < n; i++) {
        ll y; cin >> y;
        sum += y;
        M=max(M,y);
    }

    return max((sum+x-1)/x, M);
}

int main() {
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
