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

// vector<vector<ll>>

const ll M = 1e8;

vector<ll> R(M, 0);
Vec<ll> p10(19);

auto solve() {
    ll a, b, m;
    cin >> a >> b >> m;
    ll fans = 0;
    

    for (ll len = 1; len <= 8; len++) {
        ll s = p10[len-1];
        
        for (ll i = s; i < p10[len]; i++) {
        }
    }


    return 2 * fans;

}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       
    p10[0] = 1;
    for (ll i = 1; i<= 18; i++) {
        p10[i] =  p10[i - 1] * 10;
    }
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << "Case #" << tc << ": " << res << "\n";
    }
    return 0;
}
