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
    cout << 1 << '\n';
    ll n = rnd(1, 10);
    ll m = rnd(1, 10);

    set<ll> a, b;

    for (ll i = 0; i < n; i++) {
	    a.insert(rnd(1, 200));
    }
    for (ll i = 0; i < m; i++) {
	    b.insert(rnd(1,200));
    }

    cout << a.size() << " " << b.size() << "\n";
    for (auto x : a) {
	    cout << x << " ";
    }	cout << '\n';
    for (auto x : b) {
	    cout << x << " ";
    }	cout << '\n';
    return 0;
}
