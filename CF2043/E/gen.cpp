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
    ll n, m;
    n = m = 1e3;

    vector<vector<ll>> g(n, vector<ll> (m));
    auto a = g;
    auto b = g;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            a[i][j] = rnd(1, 1 << 30);
            b[i][j] = rnd(1, 1 << 30);

        }
    }

    cout << 1 << '\n';
    cout << n << " " << m << '\n';

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cout << b[i][j] << ' ';
        }
        cout << '\n';
    }



    return 0;
}
