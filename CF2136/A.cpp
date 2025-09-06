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

bool ok1(ll x, ll y) {
	if (x > y) {
		swap(x,y);
	} // x <= y

	return y <= 2 * x + 2;
}

auto solve() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	if (ok1(a, b) && ok1(c-a,d-b)){
		return "YES";
	} 
	return "NO";
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
