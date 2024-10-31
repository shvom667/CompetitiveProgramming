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

    const ll M = 1000;
    ll n, q;
    n = rnd(1, M);
    q = rnd(1, M);

    vector<pair<ll,ll>> vp;

    for (ll i = 1; i <= q; i++) {
        ll p, v;
        p = rnd(1, n);
        v = rnd(1, M);

        vp.pb({p, v});
    }

    cout << n << " " << q << "\n";
    for (auto& [x, y] : vp) {
        cout << x << " " << y << "\n";
    }

    return 0;
}
