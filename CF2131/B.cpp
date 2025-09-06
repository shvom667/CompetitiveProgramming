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
	if (n == 2) {
		cout << "-1 2\n";
		return;
	}
	if (n == 3) {
		cout << "-1 3 -1\n";
		return;
	}
	vector<ll> fans;
	for (ll i = 1; i <= n; i++) {
		if(i&1){
			fans.pb(-1);
		}else{
			fans.pb(3);
		}
	}
	if(n%2==0){
		fans[n-1]=2;
	}
	for(auto x:fans){
		cout<<x<<' ';
	}cout<<'\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
solve();
		// cout << res << "\n";
	}
	return 0;
}
