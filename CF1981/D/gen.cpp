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
    ll n = 4;
    vector<vector<ll>> adj(n + 1, vector<ll> (n + 1, 0));
    for (ll i = 1; i <= 4; i++) {
        for (ll j = i + 1; j <= 4; j++) {
            adj[i][j] = 1;
        }
    }
    for (ll i = 2; i <= n - 2; i+=2) {
        adj[i][i+1] = 0;
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
