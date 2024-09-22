#include<bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve(ll n, vector<ll> a) {
    map<ll, ll> mp;
    for (auto&x:a) {
        mp[x]++;
    }
    ll fmax= 0;
    for (auto& [u, v] : mp) {
        fmax=max(fmax,v);
    }
    return n - fmax;
}

int main() {
    ll t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {    
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        auto res = solve(n, a);
        cout << res << "\n";
    }
}