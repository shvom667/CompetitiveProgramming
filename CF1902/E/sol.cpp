#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
#define SZ(x) (ll)x.size()

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif
 
const ll M1 = 1000000321;
const ll M2 = (int) ((1ll << 31) - 1);
ll P1, P2, X1, X2;

ll get_hash(string s) {
	ll v1, v2;
	v1 = v2  = 0;
	for (ll j = 0; j < SZ(s); j++) {
		v1 = v1 * P1 + (ll)s[j];
		v1 %= M1;
		v2 = v2 * P2 + (ll)s[j];
		v2 %= M2;
		string a = to_string(v1);
		a += to_string(v2);
	}
	return v1 + v2 ^ 923324;
}

string S(string a, string b) {
    // dbg(a, b);
    if (a == "") return b;
    if (b == "") return a;
    if (a[SZ(a)-1] == b[0]) {
        string ad(begin(a),end(a)-1), bd(begin(b)+1,end(b));
        return S(ad, bd);
    }
    return a + b;
}

auto bf() {
    ll n;
    cin >> n;
    vector<string> s(n);
    for (ll i = 0; i < n; i++) {
        cin >> s[i];
    }
    dbg(s);
    ll fans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            auto res = S(s[i], s[j]);
            fans += (ll)res.size();
            dbg(i, j, s[i], s[j], res);
        }
    }
    return fans;
}

mt19937 rng((ll) std::chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll x, ll y) {
  return uniform_int_distribution<ll>(x, y)(rng);
}

ll pi (ll k1, ll k2) {
	ll fans = 0;
	fans = k2;
	fans += (k1 + k2) * (k1 + k2 + 1) / 2;
	return fans;
}

ll Szudzik(ll a, ll b) {
	return a >= b ? a * a + a + b : a + b * b;
}

unordered_map<ll, ll> mp;

void init() {
  ll L, R;
  L = 1e6 + 10;
  R = 1e9 + 10;
  P1 = rnd(L, R) * 2 + 1;
  P2=  rnd(L, R) * 2 + 1;
  X1 = rnd(1e5 , 1e12);
  X2 = rnd(1e5, 1e12);
}

auto solve() {
  ll n, tot_len = 0;
  cin >> n;
  vector<string> s(n), r(n);
  for (ll i = 0; i < n; i++) {
    string a;
    cin >> a;
    s[i] = a;
    reverse(begin(a),end(a));
    r[i] = a;
    tot_len += a.size();
  }
  ll fans = 0;
  if (true) {
    ll v1, v2;
    for (ll i = 0; i < n; i++) {
        v1 = v2  = 0;
        for (ll j = 0; j < SZ(s[i]); j++) {
            v1 = v1 * P1 + (ll)s[i][j];
            v1 %= M1;
            v2 = v2 * P2 + (ll)s[i][j];
            v2 %= M2;
            mp[Szudzik(v1, v2)]++;
        }
    }
  }
  dbg(s);
  dbg(r);
  if (true) {
    ll v1, v2;
    for (ll i = 0; i < n; i++) {
        v1 = v2  = 0;
        for (ll j = 0; j < SZ(r[i]); j++) {
            v1 = v1 * P1 + (ll)r[i][j];
            v1 %= M1;
            v2 = v2 * P2 + (ll)r[i][j];
            v2 %= M2;

            fans += mp[Szudzik(v1, v2)];
        }
    }
  } 
  return 2 * n * tot_len - 2 * fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    init();
    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
