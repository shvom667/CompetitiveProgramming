#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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

/* Miller Rabin Alogithm
 * Prime Number Check till 1e18 
 * C++20
 */ 
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
void chmax(ll &a, ll b) {
    a = max(a, b);
}
void solve() {
    ll p, q;
    cin >> p >> q;
    if (p % q != 0) {
        cout << p << '\n';
        return;
    }
    set<ll> s;
    for (ll i = 1; i <= sqrtl(q); i++) {
        if (q % i == 0) {
            ll fac1 = i;
            ll fac2 =  q/i;
            if (MillerRabin(fac1))
                s.insert(fac1);
            if (MillerRabin(fac2))
                s.insert(fac2);
        }
    }
    ll best = -1;
    for (auto& v : s) {
        ll pp = p;
        while (pp % q == 0) {
            pp /= v;
        }
        chmax(best, pp);
    }
    cout << best << '\n';
}
