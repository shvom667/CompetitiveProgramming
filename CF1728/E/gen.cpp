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
		ll n, m;
		n = rnd(1, 10);
		m = rnd(1, 10);
		ll a[n], b[n], X[m], Y[m];
		for (ll i = 0; i < n; i++) a[i] = rnd(1, 10);
		for (ll i = 0; i < n; i++) b[i] = rnd(1, 10);
		for (ll i = 0; i < m; i++) X[i] = rnd(1, 10);
		for (ll i = 0; i < m; i++) Y[i] = rnd(1, 10);

		cout << n << "\n";
		for (ll i = 0; i < n; i++) {
			cout << a[i] << " " << b[i] << "\n";
		}
		cout << m << '\n';
		for (ll i = 0; i < m; i++) {
			cout << X[i] << " " << Y[i] << '\n';
		}
    return 0;
}
