#include <bits/stdc++.h>
#define int long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define ford(i, n) for (int i = n - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = (l); i < (r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) ((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

using namespace std;

using ll = long long;
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = ll(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;



const ll mod = 998244353;

int gcd(int a, int b, int& x, int& y) {
	if (!a) {
		x = 0, y = 1;
		return b;
	}
	int xx, yy, g = gcd(b % a, a, xx, yy);
	x = yy - b / a * xx;
	y = xx;
	return g;
}

int normal(int n) {
	n %= mod;
	(n < 0) && (n += mod);
	return n;
}

int inv(int a) {
	int x, y;
	assert(gcd(a, mod, x, y) == 1);
	return normal(x);
}

int add(int a, int b) { a%=mod; b%=mod; return (a+b)%mod;}
int sub(int a, int b) { a%=mod; b%=mod;  return ((a-b)%mod+mod)%mod;}
int mul(int a, int b) { a%=mod; b%=mod; return ((a * 1ll * b) % mod); }
int _div(int a, int b) { return mul(a, inv(b)); }

int binPow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = mul(ans, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ans;
}

int calc(const vector<int>& y, int x) {
	int ans = 0;
	int k = 1;
	fore(j, 1, sz(y)) {
		k = mul(k, normal(x - j));
		k = _div(k, normal(0 - j));
	}
	forn(i, sz(y)) {
		ans = add(ans, mul(y[i], k));
		if (i + 1 >= sz(y)) break;
		k = mul(k, _div(normal(x - i), normal(x - (i + 1))));
		k = mul(k, _div(normal(i - (sz(y) - 1)), normal(i + 1)));
	}
	return ans;
}

ll nCk(ll n, ll k) {
  ll res = 1;
  for (ll j = 0; j < k; j++) {
    res = mul(res, normal(n-j));
  }
  for (ll i = 1; i <= k; i++) {
    res = _div(res, i);
  }
  return res;
}
void solve() {
  ll n, k;
  cin >> n >> k;
  
  vector<ll> hash(30, 0);
  for (ll i = 0; i < 30; i++) {
    hash[i] = nCk(k+i, i+1);
  }
 

  vector<ll> a(n+1,0), fans(n+1, 0);
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }


  for(ll b = 0; b < 30; b++) {
    for (ll i = 1; i <= n; i++) {
      if ((i&-i) == (1ll<<b)) {
        vector<ll> s(30, 0);
        ll itr = i&-i;
        ll j = i;
        for (ll sub = 0; sub < (i&-i); sub++) {
          s[__builtin_popcount(sub)] = add(s[__builtin_popcount(sub)], fans[j]);
          j--;
        }
        fans[i] = a[i];
        ll to_sub=0;
        for (ll bv = 0; bv < 30; bv++) {
          to_sub = add(to_sub, mul(hash[bv-1], s[bv]));
        }
        fans[i] = sub(fans[i], to_sub);
      }
    }
  }
  for (ll i = 1; i <= n; i++) {
    cout << fans[i] << " ";
  } cout << '\n';
}

signed main() {
    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}
