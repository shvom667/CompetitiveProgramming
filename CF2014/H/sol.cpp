#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;



mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(ll x, ll y) {
  return uniform_int_distribution<ll>(x, y)(rng);
}

auto solve() {
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n);

	map<ll, ll> mp;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]] = rnd(1, 1e18);
	}

	vector<ll> x(n);
	for (ll i = 0; i < n; i++) {
		x[i] = mp[a[i]];
	}
	for (ll i = 1; i < n; i++) {
		x[i] ^= x[i - 1];
	}
	auto X = [&] (ll l, ll r) {
		ll res = x[r];
		if (l > 0) res ^= x[l - 1];
		return res;
	};

	for (ll i = 0; i < q; i++) {
		ll l, r;
		cin >> l >> r;
		l--;r--;
		if (X(l, r) == 0) {
			cout << "YES\n";
		}else{
			cout<<"NO\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		// auto res = solve();
		// cout << res << "\n";
		solve();
	}
	return 0;
}
