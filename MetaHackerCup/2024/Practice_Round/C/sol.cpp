#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}

auto solve(ll n, vector<ll> x, vector<ll> y) {
	ll M = 0;
	for (ll itr = 1; itr <= 100; itr++) {
		ll i, j;
		i = rnd(0,n-2);
		j = rnd(i+1,n-1);
		ll cur = 0;
		for (ll k = 0; k < n; k++) {
			if ((x[k]-x[i]) * (y[k]-y[j]) == (x[k]-x[j]) * (y[k]-y[i])) {
				cur++;
			}
		}
		M = max(M, cur);
	}
	return n - M;
}

int main() {
	
    int t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
		ll n;
		cin >> n;
		vector<ll> x(n), y(n);
		for (ll i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
		}
        auto res = solve(n, x, y);
        cout << "Case #" << tc << ": " << res << "\n";
    }
}
