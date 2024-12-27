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
    ll N = 4;
    ll n , m;
    n = rnd(1, N);
    m = rnd(1, N);
    Vec<ll> a(n), b(m);
    for (ll i = 0; i < n; i++) {
        a[i] = rnd(1, 2*N);
    }
    for (ll i = 0; i < m; i++) {
        b[i] = rnd(1, 2*N);
    }
    cout << 1 << '\n';
    cout << n << " " << m << '\n';
    for (auto x : a) {
        cout << x << " ";
    } cout << '\n';
    for (auto x : b) {
        cout << x << " ";
    } cout << '\n';



    return 0;
}
