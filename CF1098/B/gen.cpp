#include <bits/stdc++.h>
using namespace std;
using ll = int;
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
const ll inf = 1e9;


auto solve() {
    ll n = 150000/2;

    
    cout<<2*n<<' ' << 2 << '\n';
    for (ll i = 0; i < n; i++) {
        cout << "GA\n";
        if(i&1)
            cout << "TC\n";
        else   
            cout << "CT\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
	    // auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
