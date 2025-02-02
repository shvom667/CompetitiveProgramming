#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif



auto solve() {
	ll n;
	cin >> n;
	ll sum_b = 0;
	vector<ll> a(n), b(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		sum_b += b[i];
	}
	ll m;
	cin >> m;
	vector<ll> X(m), Y(m);
	for (ll i = 0; i < m; i++) {
		cin >> X[i] >> Y[i];
	}

	vector<ll> d(n);

	for (ll i = 0; i < n; i++) {
		d[i] = a[i] - b[i];
	}
	sort(begin(d), end(d), greater<ll> ());

	for (ll i = 0; i < n; i++) {
		if (i)
			d[i] += d[i - 1];
	}

	dbg(d, sum_b);

	vector<ll> fans;

	for (ll i = 0; i < m; i++) {
		ll res = -1;
		for (ll x = 0; x * X[i] <= n; x++) {

			if ((n - x * X[i]) >= 0 && ((n - x * X[i]) % Y[i]) == 0) {
				// what is the answer of (x, y)
				if (x * X[i] > 0)
					res = max(res, d[x * X[i] - 1] + sum_b);
				else
					res = max(res, sum_b);
			}
		}
		fans.pb(res);
	}

	

	return fans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	T = 1;
	for (ll tc = 1; tc <= T; tc++) {
		auto res = solve();
		for (auto x : res) {
			cout << x << '\n';
		}
	}
	return 0;
}
