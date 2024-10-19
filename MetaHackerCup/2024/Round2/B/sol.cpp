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

char g[6][7];

auto process(ll r0, ll r1, ll r2, ll r3, ll r4, ll r5, ll r6) {
    ll r[7];
    r[0] = r0; 
    r[1] = r1; 
    r[2] = r2; 
    r[3] = r3; 
    r[4] = r4;
    r[5] = r5;
    r[6] = r6;

    ll cnt_c=0;
    ll cnt_f=0;
    
    for (ll c=0;c<=6;c++) {
        for (ll i = 0; i <= )
    }
}

auto solve() {
    
    for (ll i = 5; i >= 0; i--) {
        for (ll j = 0; j < 7; j++) {
            cin >> g[i][j];
        }
    }

    for (ll r0 = 0; r0 <= 5; r0++) {
    for (ll r1 = 0; r1 <= 5; r1++) {
    for (ll r2 = 0; r2 <= 5; r2++) {
    for (ll r3 = 0; r3 <= 5; r3++) {
    for (ll r4 = 0; r4 <= 5; r4++) {
    for (ll r5 = 0; r5 <= 5; r5++) {
    for (ll r6 = 0; r6 <= 5; r6++) {
        process(r0, r1, r2, r3, r4, r5, r6);
    }
    }
    }
    }
    }
    }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << "Case #" << tc << ": " << res << "\n";
    }
    return 0;
}
