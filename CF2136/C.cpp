#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

// #ifndef ONLINE_JUDGE
// #include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
// #include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
// #else
// #define dbg(...) 42
// #define rnd(...) 42
// #endif

auto solve() {
	ll n;
	cin >> n;

	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}


	vector<ll> upto(n, 0), ending(n, 0), pi(n, -1);

	vector<deque<ll>> dq(n+1, deque<ll> ());

	for (ll i = 0; i < n; i++) {
		dq[a[i]].push_back(i);
		if(dq[a[i]].size() > a[i]) {
			dq[a[i]].pop_front();
		}
		if (dq[a[i]].size() == a[i]) {
			pi[i] = dq[a[i]].front();
		}
	}

	
	for (ll i = 0; i < n; i++) {

		if (pi[i] == -1) {
			ending[i] = 0;
		} else {
			ending[i] = a[i];
			if (pi[i] - 1 >= 0) {
				ending[i] += upto[pi[i] - 1];
			}
		}

		upto[i] = ending[i];
		if (i) {
			upto[i] = max(upto[i], upto[i - 1]);
		}
	}


	return upto[n-1];
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
