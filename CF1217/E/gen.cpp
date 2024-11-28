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
    ll N = 2e5 + 20;
    ll n = rnd(N, N), m = rnd(N, N);
    cout << n << " " << m << '\n';
    ll a[n + 1];
    for (ll i = 1; i <= n; i++)  {
        a[i] = rnd(1, 100000000);
        cout << a[i] << " ";
    }cout << '\n';
    for (ll i = 1; i <= m; i++) {
        ll t = rnd(0, 2);
        if (t == 0) {
            cout << 1 << " " << rnd(1, n) << " " << rnd(1,100000000) << '\n';
        } else {
            ll x=rnd(1,n-1);
            ll y=rnd(x,n);
            cout << 2 << " " << x << " " << y << '\n';
        }
    }
    return 0;
}
