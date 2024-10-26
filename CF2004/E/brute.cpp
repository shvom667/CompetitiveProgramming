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


map<Vec<ll> , bool> mp;
map<Vec<ll>, ll> grundy;

bool dfs (vector<ll> a) {
    ll n = a.size();
    
    if (mp.find(a) != mp.end()) {
        return mp[a];
    }
    if (*max_element(begin(a),end(a)) == 0) {
        return mp[a] = false;
    }
    bool winning = false;
    for (ll i = 0; i < n; i++) {
        if (a[i] > 0) {
            for (ll v = 1; v <= a[i]; v++) {
                if (__gcd(v, a[i]) == 1) {
                    vector<ll> b = a;
                    b[i] -= v;
                    bool res = dfs(b);
                    if (res == false) {
                        winning = true;
                    }
                }
            }
        }
    }
    return mp[a] = winning;
}
 
auto solve() {
    mp.clear();
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll res = dfs(a);

    if (res == true) {
        cout << "winning\n"; 
    } else {
        cout << "losing\n";
    }
    // for (auto&[u, v] : mp) {
    //     dbg(u, v);
    // }
}

int main() {
	// ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        // auto res = solve();
        // cout << res << "\n";
        solve();
    }
    return 0;
}
