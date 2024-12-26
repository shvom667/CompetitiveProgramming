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
    n = 5e5;
    pre_calc_sieve(n);
    ll fans = 0;
    for (ll i = 1; i <= n; i++) {
        map<ll, ll> mp;
        ll j = i;
        while (j > 1) {
            ll p = MinPrime[j];
            j /= p;
            mp[p]++;
        }
        bool ok = true;
        for (auto &[u, v] : mp) {
            if (v >= 2) {
                ok = false;
            }
        }
        if (ok) {
            fans++;
        }
    }
    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
