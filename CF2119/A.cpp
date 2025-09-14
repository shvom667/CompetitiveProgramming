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
	ll a, b, x, y;
	cin >> a >> b >> x >> y;

	if (a == b) {
		return 0ll;
	}
	if (a > b) {
		if (a == b + 1) {
			if (a&1){
				return y;	
			}else {
				return -1ll;
			}
		} else {
			return -1ll;
		}
	} else {
		ll eo, oe, d;
		eo = oe = 0;
		d = b - a;

		if (a&1) {
			oe = (d + 1) / 2;
			eo = (d) / 2;
		} else {
			eo = (d + 1) / 2;
			oe = (d) / 2;
		}

		return min(eo*y+oe*x, (eo+oe)*x);
	}
	return 0ll;
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