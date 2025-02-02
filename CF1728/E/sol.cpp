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

// ============

const ll N = 4e5 + 20;

vector<int> MinPrime;
vector<int> PRIME;
void pre_calc_sieve(int N) {
	MinPrime = vector<int> (N + 1, 0);
	for (int i = 2; i <= N; ++i) {
		if (MinPrime[i] == 0) {
			MinPrime[i] = i;
			PRIME.push_back(i);
		}
		for (int j = 0; i * PRIME[j] <= N; ++j) {
			MinPrime[i * PRIME[j]] = PRIME[j];
			if (PRIME[j] == MinPrime[i]) {
				break;
			}
		}
	}
}

// ============

auto find_factors(vector<ll>& factors, vector<ll>& fac_cnt, ll i, ll res, vector<ll>& fans) {
	if (i == (ll)factors.size()) {
		fans.pb(res);
		return;
	}
	ll cur_fac = 1;
	for (ll j = 0; j <= fac_cnt[i]; j++) {
		find_factors(factors, fac_cnt, i + 1, res * cur_fac, fans);
		cur_fac *= factors[i];
	}
};	

auto solve() {
	ll N = 3e5 + 1;
	// ll N = 10;

	vector<vector<ll>> fans(N + 1);
	for (ll i = N; i >= 2; i--) {
		// prime factorize N
		ll j = i;
		vector<ll> factors;
		vector<ll> fac_cnt;
		while (j > 1) {
			ll mp = MinPrime[j];
			ll cnt = 0;
			while (j % mp == 0) {
				j /= mp;
				cnt++;
			}
			factors.pb(mp);
			fac_cnt.pb(cnt);
		}

		vector<ll> res;
		find_factors(factors, fac_cnt, 0, 1, res);
		// fans.pb(res);
		fans[i] = res;
		// dbg(i, factors, fac_cnt);
		// dbg(res);
	}

	fans[1] = {1};
	fans[0] = {0};

	ll res = 0;
	for (ll i  = 0; i < (ll)fans.size(); i++) {
		// cout << (ll)fans[i].size() * (ll)fans[(ll)fans.size() - i - 1].size() << "\N";
		
		res += (ll)fans[i].size() * (ll)fans[(ll)fans.size() - i - 1].size();
	}




	dbg(res);



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


	// vector<ll> fans;

	// for (ll i = 0; i < m; i++) {
	// 	ll res = -1;
	// 	for (ll x = 0; x * X[i] <= n; x++) {

	// 		if ((n - x * X[i]) >= 0 && ((n - x * X[i]) % Y[i]) == 0) {
	// 			// what is the answer of (x, y)
	// 			if (x * X[i] > 0)
	// 				res = max(res, d[x * X[i] - 1] + sum_b);
	// 			else
	// 				res = max(res, sum_b);
	// 		}
	// 	}
	// 	fans.pb(res);
	// }

	map<pair<ll, ll>, ll> mp;

	vector<ll> best(n, -1);

	for (ll m = 0;  m <= n; m++) {
		dbg(m, fans[m]);
		dbg(fans[n]);
		for (auto x : fans[m]) {
			for (auto y : fans[n - m]) {
				// [x, y]
				dbg(x, y);
				if (y == 0) {
					if (m > 0)
						best[m] = max(best[m], d[m - 1]);
					else 
						best[m] = 0;
				}
				if (m > 0)
					mp[{x,y}] = max(mp[{x, y}], d[m - 1]);
				else 
					mp[{x, y}] = 0;
			}
		}
	}

	dbg(X, Y);

	for (ll i = 0; i < m; i++) {
		if (mp.find({X[i], Y[i]}) != mp.end()) {
			cout << -1 << '\n';
		} else {

			cout << max(mp[{X[i], Y[i]}], best[m]) + sum_b << '\n';
		}
	}

	

	// return fans;

	// dbg(fans);
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre_calc_sieve(N);
	ll T;
	T = 1;
	for (ll tc = 1; tc <= T; tc++) {
		solve();
	}
	return 0;
}
