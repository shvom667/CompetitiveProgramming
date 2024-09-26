#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 60;
ll n;
ll a[N];

auto solve() {
    string fans="NO";
    map<ll, ll> mp;
    for (ll i = 1; i <= n; i++) {
        mp[a[i]]++;
    }
    for (auto& [u,v]: mp) 
        if (v&1) fans="YES";
    return fans;
}

int main() {
    int t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        cin >> n;
        for (ll i = 1; i <= n; i++)
            cin  >> a[i];
        auto res = solve();
        cout << res << "\n";
    }
}
