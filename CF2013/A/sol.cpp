#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll ub(ll x, ll y) {
	return (x + y - 1) / y;
}
auto solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		if (i < n - 2)
		sum += a[i];
	}
	cout << sum + a[n-1] - a[n-2] << "\n";
}

int main() {
	
	ll T;
	cin >> T;
	while (T--) {
		solve();
	}
}
