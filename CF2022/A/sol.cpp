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
    ll fans=0;

    ll n, r;
    cin >> n >> r;
    ll used=0;
    ll k=0;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        k += (x%2==1);
        used += x/2;
        fans+=(x/2)*2;
    }
    ll left = r-used;
    return fans + (k <= left ? k : 2*left-k);

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
