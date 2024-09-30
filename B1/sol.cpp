#include<bits/stdc++.h>
using namespace std;
using ll = long long;


auto solve(ll n, vector<ll> a) {
    vector<vector<ll>> ans(n, vector<ll> (n, 0));
    for (ll i = 0; i < n; i++) {
        deque<pair<ll, ll>> dq;
        ll pr = 0;
        for (ll j = i; j < n; j++) {
            ll l = a[j], r = a[j];
            while (!dq.empty() && dq.back().second > a[j]) {
                auto b = dq.back();
                l = min(l, b.first);
                r = max(r, b.second);
                dq.pop_back();
            }
            dq.push_back({l,r});
            ans[i][j] = dq.size();
        }
    }

    ll fans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i; j < n; j++) {
            fans += j - i + 1 - ans[i][j];
        }  
    }
    return fans;
}

int main() {
    int T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
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
