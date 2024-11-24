#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifdef SHIVOM
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif

map<ll, ll> mp;
ll cnt = 0;
ll get(ll n) {
    cnt++;
    if (n == 1) {
        return 0ll;
    }
    if(mp.find(n) != mp.end()) {
        return mp[n];
    }
    return mp[n] = get(n/2)+get((n+1)/2) + n - 1;
}

auto solve() {
    
    return 0;
}

auto bf() {
    ll m = 20;
    vector<ll>fans(m);
    // for (ll i = 1; i <= m; i++) {
    //     fans[i] = get(i);
    // }
    ll n = 1e15;

    dbg(get(n));
    dbg(cnt);
    // dbg(fans);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    bf();
    return 0;

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}


// 1,6,27,220