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
    ll n = rnd(2, 7);

    string s;
    s = "";
    for (ll i = 0; i < n; i++) {
        s += 'a' + rnd(0, 25);
    }
    cout << 1 << '\n';
    cout << s << '\n';
    cout << rnd(1, (n * (n + 1)) / 2) << '\n';
    return 0;
}
