#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>


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

const ll T = 1000;
const ll D = T*T*T;

ll ask(char x, ll k) {
	cout << "? " << x << " " << k << endl;
	ll ans; cin >> ans; return ans;

}

void give(ll x, ll y) {
	cout << "! " << x << " " << y << endl;
}

auto solve() {
	ll n;
	cin >> n;
	vector<ll> x(n, 0), y(n, 0);

	for (ll i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}


	ll xmax = -D, xmin = D, ymax = -D, ymin = D;

	for(ll i=0;i<n;i++){
		xmax=max(xmax,x[i]);
		xmin=min(xmin,x[i]);
		ymax=max(ymax,y[i]);
		ymin=min(ymin,y[i]);
	}

	ll ans = -1;

	ans = ask('R', D);
	ans = ask('R', D);
	ans = ask('U', D);
	ans = ask('U', D);


	ll in_d = 10*D;
	for (ll i = 0; i < n; i++) {
		in_d = min(in_d, abs(xmax - x[i]) + abs(ymax - y[i]));
	}

	ll ab = ans - in_d;

	ans = ask('D', D);
	ans = ask('D', D);
	ans = ask('D', D);
	ans = ask('D', D);


	in_d = 10 * D;
	for (ll i = 0; i < n; i++) {
		in_d = min(in_d, abs(xmax - x[i]) + abs(ymin - y[i]));
	}

	ll ad = ans - in_d;

	ll bd = 4*D - (ymax - ymin);

	ll a = (ab+ad-bd)/2;

	ll b = ab - a;


	ll A = a + xmax - 2 * D;
	ll B = b + ymax - 2 * D;


	give(A, B);






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
