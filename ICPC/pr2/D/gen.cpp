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

    cout << 1e6 -1 << "\n";
    for (ll i = 2; i <= 1e6; i++) {
        cout << i << "\n";
    }
    return 0;
}
