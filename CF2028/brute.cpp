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
    
    vector<vector<pair<ll,ll>>> adj(n + 1);

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
            adj[I[j]].pb({I[j - 1], i});
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
    vector<pair<ll,ll>>  par(n + 1, {-1, -1});
    vector<ll> ord;

    par[1] = {0, 0};
    while (!pq.empty()) {
        ll t = pq.top();
        if (t == n) {
            ok = true;
            break;
        }
        pq.pop();
        
        for (auto& [ch, e] : adj[t]) {
            if (ch > t) {
                if (seen[ch]) continue;
                seen[ch] = true;
                par[ch] = make_pair(t,e);
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

    vector<pair<ll, ll>> fans;

    while (par[ord.back()].first != 0) {
        fans.pb({ord.back(), par[ord.back()].second});  
        ord.pb(par[ord.back()].first);  
    }

    dbg(ord);

    dbg(fans);

    reverse(begin(fans),end(fans));

    cout << "YES\n";
    cout << (ll)fans.size() << "\n";
    for (auto&[x, y] : fans) {
        if (y == 1) {
            cout << 'k' << " " << x << '\n';
        }
        if (y == 2){
            cout << 'j' << " " << x << '\n';
        }
        if (y == 0) {
            cout << 'q' << " " << x << "\n";
        }
    }

    // return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
        // auto res = solve();
        // cout << res << "\n";
    }
    return 0;
}
