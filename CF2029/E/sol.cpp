#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
 
// ============
const ll N= 5e5;
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
auto solve() {
	
	ll n;
	cin >> n;
	Vec<ll> a(n);
	ll p = -1;
	ll cnt = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		if (MinPrime[a[i]] == a[i]) {
			p = a[i];
			cnt++;
		}
	}
	if (cnt == 0) {
		cout << 2 << "\n";
		return;
	}

	if (cnt >= 2) {
		cout << -1 << "\n";
		return;
	}
	sort(begin(a), end(a));
	for (ll i = 0; i < n; i++) {
		if (a[i] < p) {
			cout << -1 << "\n";
			return;
		}
		if (a[i] > p && a[i] <= 2 * p - 1) {
			cout << -1 << "\n";
			return;
		}
		ll mpf = MinPrime[a[i]];
		
		if (mpf != p && a[i]&1)
		if (a[i] - mpf < 2 * p) {
			dbg(a[i], mpf, p);
			cout << -1 << "\n";
			return;
		}
	}

	cout << p << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       
	pre_calc_sieve(N);
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
		solve();
    }
    return 0;
}
