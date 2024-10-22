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
const ll INF = 1e9;
auto solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<char> s(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> s[i];
    }
    bool start = true;
    ll l = -1, r = -1, m = INF, M = -INF;
    set<ll> st;
    for (ll i = 1; i <= n; i++) {
        if (start == true) {
            st.insert(i);
            start = false;
            l = i;
            r = -1;
        }

        m = min(m, a[i]);
        M = max(M, a[i]);
        
        if (m == l && M == i) {
            r = i;
            start = true;
            l = r = -1;
            m = INF, M = -INF;
        }
    }
    dbg(st);
    set<ll> imp, bad;

    for (ll i = 2; i <= n; i++) {
        if (s[i] == 'R' && s[i - 1] == 'L') {
            imp.insert(i);
        }
    }
    for (auto& x : imp) {
        if (st.count(x)) {

        }   else {
            bad.insert(x);
        }
    }
    dbg(imp);
    dbg(bad);
    vector<ll> fans;
    while (q--) {
        ll x;
        cin >> x;
        if (x > 1)
        if (s[x] == 'R' && s[x-1] == 'L') {
            if (imp.count(x))
                imp.erase(x);
            if (bad.count(x))
                bad.erase(x);
        }
        if (x + 1 <= n)
        if (s[x + 1] == 'R' && s[x] == 'L') {
            if (imp.count(x + 1))
                imp.erase(x + 1);
            if (bad.count(x + 1))
                bad.erase(x + 1);
        }
        if (s[x] == 'R') s[x] = 'L';
        else s[x] = 'R';

        if (x > 1)
        if (s[x] == 'R' && s[x-1] == 'L') {
            imp.insert(x);
            if (st.count(x) == 0)
                bad.insert(x);
        }
        if (x + 1 <= n)
        if (s[x + 1] == 'R' && s[x] == 'L') {
            imp.insert(x + 1);
            if (st.count(x + 1) == 0)
                bad.insert(x + 1);
        }
        if (bad.size() > 0) {
            fans.pb(0); 
        }   else {
            fans.pb(1);
        }
        dbg(imp);
        dbg(bad);
    }
    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        for (auto&x : res) {
            cout << (x == 1 ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
