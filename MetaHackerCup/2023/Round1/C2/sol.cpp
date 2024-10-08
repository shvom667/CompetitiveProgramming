#define ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) begin(x), end(x)
#define pb push_back
// =================

template <typename T>
void makeUniq(vector<T>& vec) {
    sort(begin(vec),end(vec));
    vec.resize(unique(ALL(vec)) - vec.begin());
}

auto bf(auto n, auto a, auto q, auto x) {
    vector<ll> vals;
    auto calc = [&] (vector<ll> a) {
        ll fans = 0;
        for (ll i = 0; i < n; i++) {
            if (a[i] == 1) {
                fans++;
                ll v = i + 1;
                for (ll i = v - 1; i < n; i += v) {
                    a[i] ^= 1;
                }
            }
        }
        return fans;
    };
    
    vals.push_back(calc(a));
    
    for (auto&v : x) {
        for (ll i = v - 1; i < n; i += v) {
            a[i] ^= 1;
        }
        vals.push_back(calc(a));
    }
    ll fans = 0;
    
    for (ll i = 1; i < vals.size(); i++) {
        fans+=vals[i];
    }
    return fans;
}

auto solve(auto n, auto a, auto q, auto x) {
    ll cur = 0;
    vector<ll> op(n, 0);
    for (ll i = 0; i < n; i++) {
        if (a[i] == 0) {
            continue;
        } else {
            ll v = i + 1;
            cur++;
            for (ll j = i; j < n; j+=v) {
                a[j] ^= 1;
            }
            op[i] = 1;
        }
    }
    ll fans = 0;
    
    for (auto& i : x) {
        i--;
        cur += ((op[i] ^ 1) == 1 ? 1 : -1);
        op[i] ^= 1;
        fans += cur;
        
    }
    return fans;
}

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}
auto stress1() {
    while (true) {
        ll n, q;
        n = rnd(2, 10);
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            a[i] = rnd(0,1);
        }
        q = rnd(1, 10);
        vector<ll> x(q);
        for (auto& y: x) {
            y = rnd(1, n);
        }
        auto bvals = bf(n, a, q, x);
        auto svals = solve(n, a, q, x);
        
        if (bvals == svals) {
            cout << "ok\n";
        } else {
            cout << "not ok\n";
            exit(0);
        }
        
    }
}

int main() {
    // stress1();
    int t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        ll n;
        cin >> n;
        vector<int> a(n);
        for (ll i = 0; i < n; i++) {
            char c;
            cin >> c;
            a[i] = c - '0';
        }
        ll q;
        cin >> q;
        vector<ll> x(q);
        for (auto&y : x) cin >> y;
        auto bans = solve(n, a, q, x);
        
        cout << "Case #" << tc << ": " << bans << "\n";
    }
}
