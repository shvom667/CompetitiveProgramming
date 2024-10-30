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
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll fans = 1;
    if (n & 1) {
        ll best = 1e18;
        for (ll i = 0; i < n; i++) {
            ll cur_ans = 1;
            vector<ll> cur;
            for (ll j = 0; j < n; j++) {
                if (j != i) {
                    cur.pb(j);
                }
            }
            dbg(cur);
            for (ll i = 1; i < cur.size(); i+=2) {
                cur_ans = max(cur_ans, a[cur[i]] - a[cur[i-1]]);
            }
            best = min(best, cur_ans);
        }
        return best;
    } else {
        for (ll i = 1; i < n; i += 2) {
            fans = max(fans, a[i] - a[i - 1]);
        }
    }

    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
