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
    //ll n = 2e5;
    ll n = 2000;
    ll a[n + 1], p[n + 1];
    for (ll i = 1; i <= n; i++) {
        a[i] = rnd(1, (ll)1e9);
    }
    for (ll i = 2; i <= n; i++) {
        p[i] = rnd(1, i - 1);
    }
    cout << n << "\n";
    for (ll i = 1; i <= n ;i++)
        cout << a[i] << " \n"[i == n];
    for (ll i = 2; i <= n ;i++)
        cout << p[i] << " \n"[i == n];
    return 0;
}
