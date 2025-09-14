#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

/*
Idea: 

1. Transformation

Let a be a sequence.
f(a) be the weight of the sequence.

f(a) means that there are f(a) no of moves we can make with a

each move will resut in a final token sequence t. 

We flip this problem: g(t) =>  no of moves of sequences a for each t.

fans = sigma (g(t)) for all t

for n = 2

Let X represent a token

t = [[0,0], [0,X], [X, 0], [X, X]]

we will do dp on t


For index i in t, removal can only happen if we place a number in  [i, n] and we can put  i values => [1....i] 

dp[i][x] : no of sequences such that we have filled from i to n and used x X's


dp[i][x] = dp[i + 1][x - 1] => Token not removed at i

dp[i][x] = dp[i + 1][x] * (k + 1) * i  => Token removed at i

*/

auto solve() {
	ll n, mod;
	cin >> n >> mod;

	vector<vector<ll>> dp(n + 1, vector<ll> (n + 1, 0));

	dp[n][0] = n;
	dp[n][1] = 1;
	for (ll i = n-1; i >= 1; i--) {
		dp[i][0] = (dp[i+1][0]*i)%mod;
		dp[i][n-i+1] = 1;
	}

	for (ll i = n - 1; i >= 0; i--) {
		for (ll j = 1; j < n - i + 1; j++) {
			dp[i][j] = dp[i+1][j-1];
			ll ans = dp[i+1][j];
			ans = (ans*(j+1));
			ans%=mod;
			ans = (ans * (i));
			ans%=mod;
			dp[i][j] += ans;
			dp[i][j] %= mod;
		}
	}

	ll fans=0;
	for(ll j=0;j<=n;j++){
		fans += dp[1][j];
		fans %= mod;
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
