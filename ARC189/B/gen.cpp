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
    ll n = rnd(1, 10);
    set<ll> s;
    for (ll i = 1; i <= n; i++) {
        s.insert(rnd(1, 10));
    }
    cout << s.size() << '\n';
    for (auto&x : s) {
        cout << x << " ";
    }   cout << '\n';
    return 0;
}
