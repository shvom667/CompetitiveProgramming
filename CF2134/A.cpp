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
	ll n, a, b;
	cin >> n >> a >> b;

	if (n&1) {
		if (b >= a) {
			if (b & 1) {
				return "YES";
			} else {
				return "NO";
			}
		} 
		else {
			if (b%2==1 && a%2==1){
				return "YES";
			}else{
				return "NO";
			}
		}

	}

	if (n % 2 == 0) {
		if (b >= a) {
			if (b % 2 == 0) {
				return "YES";
			} else{
				return "NO";
			}
		}
		if (a % 2 == 0 && b % 2 ==0) {
			return "YES";
		}else{
			return "NO";
		}
	}

	return "";
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
