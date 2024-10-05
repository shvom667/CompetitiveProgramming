#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;


auto solve(ll n, ll k, vector<ll> a) {
    return 0;
}

auto stress() {
    ll n = 15;

    for (ll i = 1; i <= n; i++) {
        cout << i << " " << n % i << "\n";
    }
    return;
}

int main() {
    stress();
    return 0;

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (auto& x: a) cin >> x;
        auto res = solve(n, k, a);
        cout << res << "\n";
    }
    return 0;
}
