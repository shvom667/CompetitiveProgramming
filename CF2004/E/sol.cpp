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

const ll N = 1e7 + 20;


// ============

vector<int> MinPrime;
vector<int> PRIME;
vector<int> kthPrime;

void pre_calc_sieve(int N) {
	MinPrime = vector<int> (N + 1, 0);
	kthPrime = vector<int> (N + 1, 0);
    ll itr = 0;
	for (int i = 2; i <= N; ++i) {
		if (MinPrime[i] == 0) {
			MinPrime[i] = i;
			PRIME.push_back(i);
            kthPrime[i] = ++itr;
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

ll grundy[N];



void init() {
    pre_calc_sieve(N);

    for (ll i = 1; i < N; i++) {
        grundy[i] = kthPrime[MinPrime[i]];
    }

    grundy[1] = 1;
    for (ll i = 2; i < N; i+=2) {
        grundy[i] = 0;
    }
}
 
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll fans = 0;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        fans ^= grundy[a[i]];
    }
    return (fans == 0 ? "Bob" : "Alice");
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       
    init();
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
