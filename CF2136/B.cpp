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
	string s; cin >> s;

	vector<ll> a(n, 0);
	if (s[0] == '1') {
		a[0] = 1;
	} 
	for (ll i = 1; i < n; i++){
		if(s[i] == '0'){
			a[i]=0;
		}else{
			a[i]=a[i-1]+1;
		}
		if(a[i]>=k){
			cout<<"NO\n";return 0;
		}
	}

	vector<ll> fans(n, 0);
	ll x = n;
	for (ll i = 0; i < n; i++) {
		if (s[i] == '0') {
			fans[i] = x--;
		}
	}
	for (ll i = 0; i < n; i++) {
		if (s[i] == '1') {
			fans[i] = x--;
		}
	}

	cout<<"YES\n";
	for (auto x : fans) {
		cout << x << " ";
	}	cout<<'\n';

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		auto res = solve();
		// cout << res << "\n";
	}
	return 0;
}


// 4 3
// 0010


// 5 2

// 1 1 0 1 1

// 7 5
// 1111110

// - if there are k consecutive 1's -> fail
// - there are no k consecutive 1's









