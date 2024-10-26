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
    vector<ll> a(n), b(n);
    map<ll, Vec<ll>> mb;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i] + i;
        mb[b[i]].push_back(i);
    }
    queue<ll> Q;
    Q.push(n);
    map<ll, bool> seen;
    ll fans = 0;

    seen[n] = true;
    dbg(mb);
    while (!Q.empty()) {
        ll f = Q.front();
        fans = max(fans, f);
        Q.pop();
        dbg(f);
        for (auto&ind : mb[f]) {
            if (ind == 0) continue;
            if (seen.find(f + ind) == seen.end()) {
                seen[f + ind] = true;
                Q.push(f + ind);
            }
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
