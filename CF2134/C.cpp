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
	ll fans = 0;
	for (ll i = 1; i < n; i+=2) {

		if (i + 1 >= n) {
			if (a[i - 1] <= a[i]) {
				continue;
			} else {
				ll reduction_reqd = a[i - 1] - a[i];
				fans += reduction_reqd;
				a[i - 1] -= reduction_reqd;
			}
		}
		else {
			if (a[i - 1] + a[i + 1] <= a[i]) {
				continue;
			}
			else {
				ll reduction_reqd = a[i - 1] + a[i + 1] - a[i];
				ll front_reduction = min(reduction_reqd, a[i + 1]);
				a[i + 1] -= front_reduction;
				fans += front_reduction;
				ll remaining_reduction = reduction_reqd - front_reduction;
				ll back_reduction = min(remaining_reduction, a[i - 1]);
				if (back_reduction > 0) {
					assert(a[i - 1] >= back_reduction);
					a[i - 1] -= back_reduction;
					fans += back_reduction;
				}
			}
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
