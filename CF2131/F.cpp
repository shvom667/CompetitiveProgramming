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

auto solve(int tc) {
	ll n;
	cin >> n;

	vector<ll> a(n), b(n);



	for (ll i = 0; i < n; i++) {
		char x;cin>>x;
		a[i] = x - '0';
	}
	for (ll i = 0; i < n; i++) {
		char x;cin>>x;
		b[i] = x - '0';
	}

	// if (tc==40){
	// 	// cout<<n<<"\n";
	// 	for(auto x:a){
	// 		cout<<x;
	// 	}
	// 	for(auto x:b){
	// 		cout<<x;
	// 	}
	// 	cout<<'\n';
	// 	return 0ll;
	// }


	vector<pair<ll,pair<ll,ll>>> col01(n, {0, {0,0}});

	vector<ll> row10(n, 0);

	vector<ll> r0(n, 0);
	vector<ll> r1(n, 0);

	for (ll i = 0, d=0; i < n; i++) {
		d += (a[i] == 1 ? 1 : -1);
		row10[i] = d;	
		r0[i] += a[i] == 0;
		if (i){
			r0[i] += r0[i-1];
		}
		r1[i] += a[i] == 1;
		if (i) {
			r1[i] += r1[i-1];
		}
	}


	for(ll i=0,d=0,c0=0,c1=0;i<n;i++){
		d+=(b[i]==0?1:-1);
		c0+=(b[i]==0);
		c1+=(b[i]==1);
		col01[i].first=d;
		col01[i].second.first = c0;
		col01[i].second.second = c1;
	}

	sort(begin(col01), end(col01), [&](auto x, auto y) {
		return y.first > x.first;
	});

	// for (ll i = 0; i < n; i++) {
	// 	cout << col01[i].first << " " << col01[i].second.first << " " << col01[i].second.second << "\n";
	// }

	for (ll i = 0; i < n; i++) {
		if (i > 0) {
			col01[i].second.first += col01[i - 1].second.first;
		}
		if (i > 0) {
			col01[i].second.second += col01[i - 1].second.second;
		}
	}

	ll fans = 0;

	// if (a[0] == b[0]) {
	// 	// easy
	// 	if (a[0] == 1) {
	// 		for (ll i = 0; i < n; i++) {
	// 			if (a[i] == 0) {
	// 				fans += (n - i) * n;
	// 			}
	// 		}
	// 		for (ll i = 0; i < n; i++) {
	// 			if (b[i] == 0) {
	// 				fans += (n - i) * n;
	// 			}
	// 		}
	// 	} else {
	// 		for (ll i = 0; i < n; i++) {
	// 			if (a[i] == 1) {
	// 				fans += (n - i) * n;
	// 			}
	// 		}
	// 		for (ll i = 0; i < n; i++) {
	// 			if (b[i] == 1) {
	// 				fans += (n - i) * n;
	// 			}
	// 		}
	// 	}
	// 	return fans;
	// } 

	// cout<<"row10\n";
	// for (ll i = 0; i < n; i++) {
	// 	cout << row10[i] << " ";
	// }	cout<<'\n';
	// cout<<"r1\n";
	// for (ll i = 0; i < n; i++) {
	// 	cout << r1[i] << " ";
	// }	cout<<'\n';


	for (ll i = 0; i < n; i++) {

		ll l = 0, r = n - 1;

		auto cond = [&] (ll m) {
			return col01[m].first >= row10[i];
		};

		while (l <= r) {
			ll mid = (l + r) / 2;
			if (cond(mid)) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		// l -> final value
		// change to 0 as final value
		// cout<<"i : " << i << " and l : " << l << '\n';
		if (l < n) {
			fans += col01[n - 1].second.second;
			if (l - 1 >= 0)
				fans -= col01[l-1].second.second;
			fans += (n - l) * r1[i];
		}

		// change to 1 as final value
		if (l - 1 >= 0) {
			fans += col01[l - 1].second.first;
			fans += (l) * r0[i]; 
		}
	}
	

			return fans;



	return 0ll;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		auto res = solve(tc);
		cout << res << "\n";
	}
	return 0;
}
