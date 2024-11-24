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

ll ub(ll x, ll y) {
    return (x + y - 1) / y;
}

auto solve() {
    ll n, d, l; cin >> n >> d >> l;

    if (d == 1) {
        if (l == 2 && n == 2) {
            cout << 1 << " " << 2 << "\n";
        } else {
            cout << -1 << "\n";
        }
        return;
    }


    ll max_leaf = n - d - 1 + 2;
    if (max_leaf < l) {
        cout << -1 << "\n";
        return;
    }

    vector<pair<ll,ll>> edges;


    if (((d/2)-1) * (l - 2) >= n - d -1 - (l - 2)) {

        ll mid = (d + 2) / 2;
        for (ll i = 1; i <= d; i++) {
            edges.pb({i, i + 1});
        }
        ll k = d + 2;
        vector<ll> leaf;
        l -= 2;
        for (ll j = 0; j < l; j++, k++) {
            edges.pb({mid, k});
            leaf.pb(k);
        }
        
        ll litr = 0;
        while (k < n + 1) {
            edges.pb({leaf[litr%l], k});
            leaf[litr%l] = k;
            litr++;

            k++;
        }

        for (auto&[u,v]:edges){
            cout << u << " " << v << "\n";
        }


    } else{
        cout << -1 << "\n";
        return;
    }

}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    // T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        // auto res = solve();
        // cout << res << "\n";
        solve();
    }
    return 0;
}


// 1,3,5,8,11,14,17,21,25,29