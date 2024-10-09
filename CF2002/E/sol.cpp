#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;


auto solve(ll n, vector<ll> a, vector<ll> b) {

    vector<ll> fans;

    ll pans = 0;
    deque<pair<ll, ll>> dq;
    map<ll, ll> mp;

    for (ll i = 0; i < n; i++) {
        ll cans = 0;
        if (mp[b[i]] + a[i] >= pans) {
            cans = mp[b[i]] + a[i];
            dq.clear();
            mp.clear();
            mp[b[i]] = cans;
            dq.push_back({b[i], cans});
        } else {
            cans = pans;
            ll x = a[i];
            ll cnt = 0;
            while (x > 0 && !dq.empty()) {
                auto bck = dq.back();
                dq.pop_back();
                mp[bck.first] -= bck.second;
                if (bck.first != b[i]) {
                    ll dec = min(x, bck.second);
                    bck.second -= dec;
                    cnt += dec;
                    x -= dec;
                    if (bck.second > 0) {
                        dq.push_back(bck);
                        mp[bck.first] += bck.second;
                    }
                } else {
                    cnt += bck.second;
                }
            }
            cnt  += x;
            dq.push_back({b[i], cnt});
            mp[b[i]] += cnt;
        }
        pans = cans;
        fans.push_back(cans);
    }

    return fans;
}

int main() {
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        auto res = solve(n, a, b);
        for (auto& x: res) {
            cout << x << " ";
        }   cout << "\n";
    }
    return 0;
}
