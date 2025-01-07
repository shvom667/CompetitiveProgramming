#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

int main(int argc, char** argv) {
    mt19937 rng(atoi(argv[1]));
    auto rnd = [&] (ll a, ll b) {
        return a + rng() % (b - a + 1);
    };
    ll M = 7;
    ll n = rnd(2, M);
    ll m = rnd(2, M);
    cout << n << " " << m << '\n';
    for (ll i = 1; i <= n; i++) {
        cout << rnd(0, 1) << " ";
    } cout << '\n';
    vector<ll> g[m + 1];
    for (ll i = 1; i <= n; i++) {
        ll s1 = rnd(1, m - 1);
        ll s2 = rnd(s1 + 1, m);
        g[s1].pb(i);
        g[s2].pb(i);
    }
    for (ll i = 1; i <= m; i++) {
        cout << (ll) g[i].size() << " ";
        for (auto x: g[i]) {
            cout << x << " ";
        }
        cout << '\n';
    }
    return 0;
}
