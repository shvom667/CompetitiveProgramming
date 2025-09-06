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
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n),b(n);
	map<int, int> mp;
	for(ll i=0;i<n;i++){
		cin >> a[i];
		if (a[i] % k > (k/2)) {
			mp[a[i]%k]++;
		}else{
			mp[abs((a[i]%k)-k)]++;
		}
	}
		map<int, int> mp2;
	for(ll i=0;i<n;i++){
		cin >> b[i];
		if (b[i] % k > (k/2)) {
			mp2[b[i]%k]++;
		}else{
			mp2[abs((b[i]%k)-k)]++;
		}
	}

	for (auto& [u, v]:mp) {
		if(mp2[u] != v) {
			return "NO";
		}
	}

	return "YES";
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
