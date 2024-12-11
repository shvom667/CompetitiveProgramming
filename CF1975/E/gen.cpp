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
    ll q = rnd(1,M);

    vector<ll> col(n, 0);
    for (ll i = 0; i < n; i++) {
        col[i] = rnd(0,1);
    }
    cout << n << " " << q << '\n';
    for (ll i = 0; i < n; i++) {
        cout << col[i] << " ";
    }   cout << '\n';

    for(ll i=1;i<n;i++){
        cout << i + 1 << " " << rnd(0, i - 1) + 1 << '\n';
    }

    for(ll j = 0; j < q; j++) {
        cout << rnd(1, n) << '\n';
    }

    return 0;
}
