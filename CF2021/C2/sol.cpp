#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;
const ll INF = 1e9;
const ll M  = 450;
auto print(Vec<ll> v){
	for (auto&x:v){
		cout << x << " ";
	}	cout << "\n";
}
auto print(map<ll,ll> mp){
	for(auto&[u,v]:mp){
		cout<<u<<" "<<v<<"\n";
	}
}

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
#define dbg(...) 42
#endif

auto solve() {
	ll n, m, q;
	cin >> n >> m >> q;
	vector<ll> a(n), b(m);
	map<ll, ll> mp;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		mp[a[i]] = i;
	}
	for (ll i = 0; i < n; i++) {
		a[i] = mp[a[i]];
	}
	for (ll i = 0; i < m; i++) {
		cin >> b[i];
		b[i]--;
		b[i] = mp[b[i]];
	}
	dbg(b);
	map<ll, set<ll>> mp2;
	for (ll i = 0; i < m; i++) {
		mp2[b[i]].insert(i);
	}

	
	vector<bool> ok(M, true);
	vector<ll> fi(n, INF);

	auto query = [&] () {
		bool fans = true;
		for (ll i = 0; i < M; i++) {
			if (ok[i] == false) {
				fans = false;
			}
		}
		for (ll i = 0; i < M; i++) {
			ll l, r;
			l = i * M + M - 1;
			r = l + 1;
			if (r < n) {
				if (fi[l] > fi[r]) {
					fans = false;
				}
			} 
		}
		return fans;
	};
	dbg(fi);
	auto update = [&] (ll ind, ll val) {
		ll s = (ind / M) * M;
		fi[ind] = val;
		ok[ind/M] = true;
		for (ll i = s + 1; i < min(n, s + M); i++) {
			if (fi[i] < fi[i-1]) {
				ok[ind/M] = false;
			}
		}
	};

	for (auto& [u, v] : mp2) {
		dbg(u,v);
		if (!v.empty())
			update(u, *v.begin());
	}

	dbg(fi);

	if (query()) {
		cout << "YA\n";
	} else {
		cout << "TIDAK\n";
	}

	while (q--) {
		ll s, t;
		cin >> s >> t;
		s--; t--;
		t = mp[t];
		
		mp2[b[s]].erase(s);
		if (mp2[b[s]].size() == 0) {
			update(b[s],INF);
		} else {
			update(b[s], *((mp2[b[s]])).begin());
		}
		b[s] = t;

		mp2[b[s]].insert(s);
		update(b[s], *((mp2[b[s]])).begin());

		if (query()) {
			cout << "YA\n";
		} else {
			cout << "TIDAK\n";
		}
		dbg(b);
		dbg(fi);
	}

	return 0;
}

int main() {
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
        // cout << res << "\n";
    }
    return 0;
}
