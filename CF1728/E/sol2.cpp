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
	ll n = 3e5 + 1;
	// ll n = 10;

	vector<vector<ll>> fans;
	for (ll i = n; i >= 2; i--) {
		vector<ll> res;
		for (ll j = 1; j <= sqrt(i); j++) {
			if (i % j == 0) {
				res.pb(j);
				if (j != i / j) {
					res.pb(i / j);
				}
			}
		}
		// dbg(res);
		fans.pb(res);

	}
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
		auto res = solve();
		cout << res << "\n";
	}
	return 0;
}
