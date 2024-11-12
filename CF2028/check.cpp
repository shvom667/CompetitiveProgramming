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
    vector<ll> Q(n + 1), K(n + 1), J(n + 1);
    for (ll i = 1; i <= n; i++) cin >> Q[i];
    for (ll i = 1; i <= n; i++) cin >> K[i];
    for (ll i = 1; i <= n; i++) cin >> J[i];

    string s;
    cin >> s;
    if (s == "NO") {
        cout << s << "\n";
        return;
    }

    ll sz;
    cin >> sz;
    ll cur_card = 1;

    bool ok = true;

    ll fans_sz = sz;
    vector<char>fans1;
    vector<ll>fans2;
    while (sz--) {
        char c; ll k;
        cin >> c >> k;
        fans1.pb(c);
        fans2.pb(k);
        if (k <= cur_card) ok = false;

        if (c == 'q') {
            if (Q[k] > Q[cur_card]) {
                ok = false;
            } else {
                // ok = true;
                cur_card = k;
            }
        }
        if (c == 'k') {
            if (K[k] > K[cur_card]) {
                ok = false;
            } else {
                // ok = true;
                cur_card = k;
            }

        }
        if (c == 'j') {
            if (J[k] > J[cur_card]) {
                ok = false;
            } else {
                // ok = true;
                cur_card = k;
            }
        }
    }   
    if (cur_card != n) {
        ok = false;
    }

    if (ok)  {
        cout << s << '\n';
        cout << fans_sz << "\n";
        for (ll i = 0; i < fans_sz; i++) {
            cout << fans1[i] << " " << fans2[i] << "\n";
        }
        return;
    }
    cout << -1 << "\n";

}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        // auto res = solve();
        // cout << res << "\n";
        solve();
    }
    return 0;
}
