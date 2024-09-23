#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> solve(ll n, ll g, vector<ll> d) {
    pair<ll, ll> f;
    sort(begin(d),end(d));
    auto it = upper_bound(begin(d),end(d),g);
    if (it == end(d)) {
        auto kt = it;
        kt--;
        f.first = 1;
        f.second = g - *kt;
    }
    else if (it == begin(d)) {
        f.first = n;
        f.second = *it - g;
    }
    else {
        auto kt = it;
        kt--;
        if (*it - g <= g - *kt) {
            f.first = n - (it - begin(d));
            f.second = *it - g;
        } else {
            f.first = n - (kt - begin(d));
            f.second = g - *kt;
        }
    }
    return f;
}

int main() {
    int t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        ll n, g;
        cin >> n >> g;
        vector<ll>  d(n);
        for (ll i = 0; i < n; i++) {
            cin >> d[i];
        }
        auto res = solve(n, g, d);
        cout << "Case #" << tc << ": " << res.first << " " << res.second << "\n";
    }
}
