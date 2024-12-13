#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

const ll mod = 998244353;
const ll N = 1e6 + 20;
vector<ll> f(N, 0);

auto solve() {
    ll n;
    cin >> n;


    vector<vector<ll>> adj(n + 1);

    for (ll i = 2; i <= n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<ll> cnt_ch(n + 1, 0);

    function<void(ll, ll)> dfs = [&] (ll i, ll p) {
        for (auto& ch : adj[i]) {
            if (ch == p) continue;
            cnt_ch[i]++;
            dfs (ch, i);
        }
    };

    ll fans = 1;


    dfs(1, 0);

    fans *= n;

    for (ll i = 2; i <= n; i++) {
        fans *= f[cnt_ch[i] + 1];
        if (fans >= mod) fans %= mod;
    }

    fans *= f[cnt_ch[1]];
    
    if (fans >= mod) fans %= mod;


    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    f[0] = 1;
    for (ll i = 1; i < N; i++) {
        f[i] = f[i - 1] * i;
        f[i] %= mod;
    }

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
