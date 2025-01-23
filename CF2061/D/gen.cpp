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
    ll n , m;
    n = rnd(1, 10);
    m = rnd(1, 10);
    vector<ll> a(n), b(m);
    for (auto&x:a)
	    x=rnd(1,20);
    for (auto&x:b)
	    x=rnd(1,20);
    cout << 1 << '\n';
    cout << n << " " << m << "\n";
    for (auto x : a)
	    cout << x << " ";
    cout << '\n';
    for (auto x : b)
	    cout << x << " ";
    cout << '\n';
    return 0;
}
