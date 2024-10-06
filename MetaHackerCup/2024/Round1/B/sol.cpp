#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// ============
const ll M = 1e7 + 20;
vector<int> MinPrime;
vector<int> PRIME;
vector<int> A;
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
    
}

int main() {
    pre_calc_sieve(M);
    A.push_back(5);
    for (ll i = 3; i < M; i++) {
        if (MinPrime[i] == i && MinPrime[i + 2] == i + 2) {
            A.push_back(i + 2);
        }
    }
    
    int T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n;
        cin >> n;
        ll res = upper_bound(begin(A), end(A), n) - begin(A);
        cout << "Case #" << tc << ": " << res << "\n";
        
    }
}
