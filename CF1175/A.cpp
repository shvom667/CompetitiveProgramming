#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--) solve();
}

void solve() {
	ll n;
	cin >> n;
	n++;
	ll y = log2(n);
	cout << y << '\n';

}
