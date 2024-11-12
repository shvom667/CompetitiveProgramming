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
    
    vector<vector<ll>> adj(n + 1);

    for (ll i = 0; i < 3; i++) {
        vector<ll> a(n + 1), I(n + 1);
        for (ll j = 1; j <= n; j++) {
            cin >> a[j];
            I[j] = j;
        }
        sort(begin(I) + 1, end(I), [&] (auto x, auto y) {
            return a[x] < a[y];
        });
        for (ll j = 2; j <= n; j++) {
            adj[I[j]].pb(I[j - 1]);
        }
    }

    for (ll i = 1; i <= n; i++) {
        dbg(adj[i]);
    }

    vector<bool> seen (n + 1, false);
    seen[1] = true;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    pq.push(1);
    bool ok = false;
    vector<ll> ord, par(n + 1, -1);

    par[1] = 0;
    while (!pq.empty()) {
        ll t = pq.top();
        if (t == n) {
            ok = true;
            break;
        }
        pq.pop();
        
        for (auto& ch : adj[t]) {
            if (ch > t) {
                if (seen[ch]) continue;
                seen[ch] = true;
                par[ch] = t;
                pq.push(ch);
            }
        }
    }
    
    if (!ok) {
        cout << "NO\n";
        return;
    }
    dbg(ord);
    ord.push_back(n);
    while (par[ord.back()] != 0) {
        ord.pb(par[ord.back()]);
    }

    dbg(ord);

    cout << "YES\n";
    // return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
        // auto res = solve();
        // cout << res << "\n";
    }
    return 0;
}
