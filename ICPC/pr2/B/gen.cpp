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
    ll n, d, l;
    n = rnd(1, 20);
    d = rnd(1, n -1);
    l = rnd(1, n);
    cout << n << " " << d << " " << l << "\n";
    return 0;
}
