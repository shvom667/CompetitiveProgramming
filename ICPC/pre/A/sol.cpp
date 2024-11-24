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
const ll N = 2e6 + 5;
auto solve() {
    ll n, k;
    cin >> n >> k;
    if (k > (n - 1) * n / 2) {
        cout << -1 << '\n';
        return;
    }

    ll sum=0;
    vector<ll> a(n,-1);
    ll j = 2;
    ll last = -1;
    for (ll i = 0; i < n; i++) {
        if(sum>=k){
            break;
        }
        a[i] = PRIME[j++];
        sum+=i;
        last = i;
    }
    ll diff = sum -k;

    dbg(sum, diff, a);
    assert(diff<=last-1);

    for (ll ind=last;ind>=0;ind--) {
        if (ind >= last-diff+1)
            a[ind] *= a[0];
        else {
            a[ind] *= 2;
        }
    }
    for (ll i = 0; i < n; i++) {
        if (a[i] == -1) {
            a[i] = 6;
        }
    }

    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i; j < n; j++) {
            if (__gcd(a[i], a[j]) == 1) {
                cnt++;
            }
        }
    }

    if (cnt == k) {
        cout << "OK\n";
    }else{
        cout << "NOT OK\n";
    }

    for (ll i = 0; i < n; i++) {
        cout << a[i] << " ";
    }   cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       
    pre_calc_sieve(N);
    dbg(PRIME.size());
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        // auto res = solve();
        // cout << res << "\n";
        solve();
    }
    return 0;
}
