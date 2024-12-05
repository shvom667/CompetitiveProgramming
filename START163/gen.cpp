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
    ll n = rnd(1, 20); ll k=rnd(1,20);
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        a[i] = rnd(-20, 20);
    }
    cout << n << " " << k << '\n';
    for (auto&x : a) {
        cout << x << " ";   
    }   cout << '\n';
    return 0;
}
