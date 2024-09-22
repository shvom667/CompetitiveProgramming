#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll ub(ll x, ll y) {
	return (x + y - 1) / y;
}
bool ask(string s) {
	cout << "? " << s << endl;
	ll ans;
	cin >> ans;
	return ans;
}
auto solve() {
	ll n;
	cin >> n;
	string res = "";
	bool b = true;
	for (ll i = 0; i < n; i++) {
		if (b && ask(res + "1")) {
			res += "1";
		} else if (b && ask(res + "0")) {
			res += "0";
			if (i == 0) {
				string fans = "";
				for (ll j = 0; j < n; j++) {
					fans += "0";
				}
				cout << "! " << fans << endl;
				return;
			}
		} else {
			b = false;
			if (ask("0" + res)) {
				res = "0" + res;
			} else {
				res = "1" + res;
			}
		}
	}
	
	cout << "! " << res << endl;
}

int main() {
	
	ll T;
	cin >> T;
	while (T--) {
		solve();
	}
}
