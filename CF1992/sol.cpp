#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

auto solve() {
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	vector<ll> f;
	for(ll i = 1; i <= sqrtl(x); i++) {
		if (x % i == 0) {
			f.pb(i);
			if (i != x / i) f.pb(x /  i);
		} 
	}
	sort(begin(f),end(f));
	ll sz = (ll)f.size();

	for(ll i=0;i<n;i++)cin>>a[i];


	ll fans = 1;

	map<ll, ll> mp;
	mp[1] = 1;
	// factors of x that are possible
	for (ll i = 0; i < n; i++) {
		if (x % a[i] != 0) continue;
		if (mp.find(x / a[i]) != mp.end()) {
			dbg(i, a[i]);
			mp.clear();
			mp[1] = 1;
			mp[a[i]] = 1;
			fans++;
			continue;
		}
			vector<ll> new_fac;
		for (auto fac : f) {
			if (fac % a[i] == 0) {
				dbg(fac, fac / a[i]);
				if(mp.find(fac / a[i]) != mp.end()) {
					new_fac.pb(fac);
				}
			}
		}
			for (auto x : new_fac) {
				mp[x]= 1;
			}
		dbg(i, mp);
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
