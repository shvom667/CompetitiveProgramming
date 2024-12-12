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
    const ll M = 1000;
    const ll inf = 1e9;
    ll n = rnd(2, M);
    ll L, R;
    L = rnd(0,inf-1), R = rnd(L + 1, inf);
    cout << n << " " << L << " " << R << "\n";
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        a[i] = rnd(0, inf);
    }
    for (ll i = 0; i < n; i++) {
        cout << a[i] << " ";
    }   cout << '\n';
    return 0;
}
