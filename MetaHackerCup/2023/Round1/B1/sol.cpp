#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ============
auto solve(ll n) {
    vector<ll> f;
    while (n > 1) {
        ll mf = 44;
        for (ll i = 2; i <= 41; i++) {
            if (n % i == 0) {
                n /= i;
                mf = i;
                break;
            } 
        }
        if (mf > 41) {
            f.clear();
            f.push_back(-1);
            return f;
        } else {
            f.push_back(mf);
            continue;
        }
    }
    ll sum = 0;
    for (auto&x : f) {
        sum += x;
    }
    if (sum > 41) {
        f.clear();
        f.push_back(-1);
        return f;
    } else {
        while (sum < 41) {
            sum += 1;
            f.push_back(1);
        }
        return f;
    }
}

int main() {
    ll t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        ll n;
        cin >> n;
        auto res = solve(n);
        cout << "Case #" << tc << ": " ;
        if (res[0] == -1)
            for (auto&x : res)
                cout << x << " ";
        else {
            cout << res.size() << " ";
            for (auto&x : res)
                cout << x << " ";
        }
        cout << "\n";
    }
}
