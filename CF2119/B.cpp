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
ll inf = 1e18;
auto solve() {
	ll n; cin >> n;
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll x; cin >> x;
	ll L = x, R = x;
	//cout << L << " " << R << "\n";
	for (ll i = 1; i < n; i++) {
		ll v; cin >> v;
		ll k = inf;
		if (v >= L && v <= R) {
			k = 0;
		}
		L = min({abs(L - v), abs(R-v), k});
		R += v;
		//cout << L << " " << R << "\n";
	}

	if ((c-a)*(c-a) + (d-b)*(d-b) >= L * L && (c-a)*(c-a) + (d-b)*(d-b) <= R*R) {
		return "Yes";
	}


	return "No";
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
