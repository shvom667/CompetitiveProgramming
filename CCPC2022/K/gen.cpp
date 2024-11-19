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
    ll n = rnd(3, 10);
    cout << n << '\n';
    for (ll i = 0; i < n; i++) {
        ll t = rnd(1,2);
        ll k = rnd(3,10);
        ll x = rnd(10,50);
        cout << t << " " << k << " " << x << '\n';
    }
  return 0;
}
