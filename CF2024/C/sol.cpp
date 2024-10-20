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
 
auto solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n), vv(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        vv[i] = v[i];
        if (v[i].first > v[i].second) {
            swap(v[i].first, v[i].second);
        }
    }
    vector<ll> I(n, 0);
    for (ll i = 0; i < n; i++) {
        I[i] = i;
    }
    sort(begin(I),end(I), [&] (ll x, ll y) {
        if (v[x].first + v[x].second < v[y].first + v[y].second) {
            return true;
        }
        if (v[x].first + v[x].second > v[y].first + v[y].second) {
            return false;
        }
        if (v[x].first + v[x].second == v[y].first + v[y].second) {
            return v[x].first < v[y].second;
        }
        
        return true;
    });

    for (ll i = 0; i < n; i++) {
        ll j = I[i];
        cout << vv[j].first << " " << vv[j].second << " ";
    }   cout << "\n";

}



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        // auto res = solve();
        // cout << res << "\n";
        solve();
    }
    return 0;
}
