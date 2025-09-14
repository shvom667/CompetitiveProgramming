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
	ll n, l, r, k;
	cin >> n >> l >> r >> k;

	if(n&1) {
		return l;
	}
	if (n == 2) {
		return -1ll;
	}
	ll hbit = 0;
	for (ll i = 0; i < 61; i++) {
		if((1ll<<i)&l){
			hbit = i;
		}
	}

	ll R = 1ll << (hbit + 1);
	if (r >= R) {
		if(k <= n - 2)	 return l;
		else return R;

	}
		
	return -1ll;	
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
