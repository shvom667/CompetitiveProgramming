#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
vector<vector<ll>> adj;
string s;
auto solve() {
    ll fans = 0;
    ll c0, c1, cq, tq;
    c0 = c1 = cq = tq = 0;
    tq = count(begin(s),end(s),'?');
    for (ll i = 2; i <= n; i++) {
        if (adj[i].size() == 1) {
            c0 += s[i-1] == '0';
            c1 += s[i-1] == '1';
            cq += s[i-1] == '?';
        }
    }
    if (s[0] == '1') {
        fans = c0 + (cq + 1) / 2;
    } else if (s[0] == '0') {
        fans = c1 + (cq + 1) / 2;
    } else {
        fans = max(c0, c1) +  cq/2;
        if (tq & 1) {
            if (c0 == c1) {
                fans = max(fans, c0 + (cq+1)/2);
            }
        }
    }
    return fans;

}

int main() {
    ll t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        cin >> n;
        adj = vector<vector<ll>> (n + 1, vector<ll> ());
        for (ll i = 1; i < n; i++) {
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin >> s;
        auto res = solve();
        cout << res << '\n';
    }
}
