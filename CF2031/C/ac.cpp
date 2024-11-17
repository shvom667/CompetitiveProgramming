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
vector<ll> a101;
auto solve(ll n) {
    
    
    
}

void bf() {
    for (ll n = 20000 - 100; n <= 20000; n++) {
        dbg(n);
        solve(n);
    }
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll n = 100;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            for (ll k = 1; k <= n; k++) {
                if (i * i == j * j + k * k && i%2==0) {
                    dbg(i);
                    exit(0);
                }
            }
        }
    }

    return 0;
}
