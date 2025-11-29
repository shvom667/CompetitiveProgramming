#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
#include <functional>
#include <stack>

using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/Users/shivom.1/development/CompetitiveProgramming/DataStructures/debug.cpp"
#include "/Users/shivom.1/development/CompetitiveProgramming/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif


const ll MOD = 1e9 + 7;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> deg(n , 0);
    vector<pair<ll,ll>> edge;
    vector<vector<ll>> adj(n);
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        deg[u]++;
        deg[v]++;
        edge.pb({u,v});
        adj[u].pb(v);adj[v].pb(u);
    }

    vector<ll> parity(n, -1);
    parity[0] = 0;
    vector<bool> seen(n, false);

    bool fuck = false;

    function<void(int)> dfs = [&] (int i) {
        seen[i] = true;
        for (auto ch: adj[i]) {
            if (!seen[ch]) {
                parity[ch] = parity[i] ^ 1;
                dfs(ch);
            }
        }
    };

    dfs(0);

    dbg(fuck);

    dbg(parity);

    if (m > n - 1) {
        fuck = true;
    }




    vector<ll> relation2(n, 0);
    vector<ll> single(n, 0);

    for (auto [u, v] : edge) {
        if (parity[u] == parity[v]) {
            fuck = true;
        }
        if (deg[u] >= 2) {
            relation2[v]++;
        }
        if (deg[v] >= 2) {
            relation2[u]++;
        }
        if (deg[u] == 1) {
            single[v]++;
        }
        if (deg[v] == 1) {
            single[u]++;
        }
    }

    for (ll i = 0; i < n; i++) {
        if (relation2[i] > 2) {
            fuck = true;
        }
    }

    ll fans = 1LL;


    if (fuck) {
        cout << 0 << "\n";
        return;
    }
    
    if (n == 2) {
        cout << 2 << '\n';
        return;
    }


    vector<ll> fac(n + 20, 0);
    fac[0] = 1;
    for (ll i = 1; i < n + 20; i++) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= MOD;
    }

    dbg(single);

    for (ll i = 0; i < n; i++) {
        fans *= fac[single[i]];
        fans %= MOD;
    }

    ll mul = 2;
    for (ll i = 0, cnt = 0; i < n; i++) {
        if (deg[i] >= 2) {
            cnt++;
        }
        if (cnt>=2) {
            mul = 4;
        }
    }


    cout << ((fans * mul) % MOD) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		solve();
		// auto res = solve();
		// cout << res << "\n";
	}
	return 0;
}
