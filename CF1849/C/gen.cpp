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
    cout << 1 << '\n';
    ll M = 5;
    ll n = rnd(2, M);
    ll m = rnd(2, M);

    set<pair<ll, ll>> Q;
    for (ll i = 0; i < m; i++) {
        ll l, r;
        l = rnd(1, n - 1);
        r = rnd(l + 1, n);
        Q.insert({l, r});
    }
    m = Q.size();
    cout << n << ' ' << m << '\n';

    for (ll i = 0; i < n; i++) {
        cout << rnd(0,1);
    }   cout << '\n';

    for (auto& [x,y]: Q) {
        cout << x << ' ' << y << '\n';
    }

    return 0;
}
