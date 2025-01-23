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
    ll n, m, k;
    n = rnd(1, 5), m = rnd(1, 5), k = rnd(1, 2);

    cout << 1 << '\n';
    cout << n << " " << m << " " <<  k << "\n";
    vector<int> a(n),  b(m);
    for (int i = 0; i < n; i++) {
	    a[i] = rnd(1, 20);
    }
    for (int j = 0; j < m; j++) {
	    b[j] = rnd(1, 20);

    }
    for (auto x : a)
	    cout << x << " ";
    cout << '\n';
    for (auto x : b)
	    cout << x << " ";
    cout << '\n';
    return 0;
}
