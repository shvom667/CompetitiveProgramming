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
    ll N=100;
    ll n = rnd(N, N);
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) {
        a[i] = rnd(1, 10);
    }
    cout << n << "\n";
    for (ll i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }   cout << '\n';
    return 0;
}
