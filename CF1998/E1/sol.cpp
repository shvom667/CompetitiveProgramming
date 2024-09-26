#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto print(auto x) {
    for (auto&v:x)
        cout<<v<< " ";
    cout << '\n';
}

auto bf(ll n, ll x, vector<ll> a) {
    ll fans = 0;
    for (ll i = 0; i < n; i++) {
        ll cur = a[i];
        deque<ll> lft, rht;
        for (ll j = 0; j <= i - 1; j++) {
            lft.push_back(a[j]);
        }
        for (ll j = i + 1; j <= n-1; j++) {
            rht.push_back(a[j]);
        }
        while (!lft.empty() || !rht.empty()) {
            bool e = false;
            if (!lft.empty() && lft.back() <= cur) {
                e = true;
                cur += lft.back();
                lft.pop_back();
            }
            if (!rht.empty() && rht.front() <= cur) {
                e = true;
                cur += rht.front();
                rht.pop_front();
            }
            if (e == false) {
                break;
            }
        }
        if (lft.empty() && rht.empty())
            fans++;
    }

    return fans;
}
using pl = pair<ll, ll>;
auto genius(ll n, ll x, vector<ll> a) {
    vector<ll> p(n);
    for (ll i = 0; i < n; i++) {
        p[i] = a[i];
        if (i) {
            p[i] += p[i-1];
        }
    }
    auto cond = [&] (ll i, ll mid) {
        return p[mid] - p[i] < a[i];
    };
    set<pl> ans;
    for (ll i = 0; i < n; i++) {
        ll l, r;
        l = i + 1, r = n - 1;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (cond(i, mid)) {
                l = mid  + 1;
            } else {
                r = mid  - 1;
            }
        }
        if (r + 1 == n || a[r + 1] >= a[i]) {
            if (i + 1 <= r) {
            ans.insert({i + 1, r});
            }
        }
    }
    vector<ll> s(n, 0);
    for (ll i = n - 1; i >= 0; i--) {
        s[i] = a[i];
        if (i < n - 1) {
            s[i] += s[i + 1];
        }
    }
    auto cond2 = [&] (ll i, ll mid) {
        return s[mid] - s[i] < a[i];
    };
    for (ll i = n - 1; i >= 0; i--) {
        ll l = 0, r = i - 1;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (cond2(i, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (l == 0 || a[l - 1] >= a[i]) {
            if (l < i) {
                ans.insert({l, i-1});
            }
        }
    }
    vector<ll> g(n, 0);
    for (auto&[x,y] : ans) {
        g[x] += 1;
        if (y + 1 < n) {
            g[y + 1] += -1;
        }
    }
    for (ll i = 0; i < n; i++) {
        if (i) {
            g[i] += g[i-1];
        }
    }
    //print(g);
    ll fans = 0;
    for (auto& x : g) {
        fans += (x == 0);
    }
    return fans;
}

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}

void stress() {
    ll cnt = 0;
    while (true) { 
        ll n, x;
        n = 5000;
        x = n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            a[i] = rnd(1, (ll)2e8);
        }
        auto bans = bf(n, x, a);
        auto gans = genius(n, x, a);
        if (gans == bans) {
            cout << "ok " << cnt << "\n";
        } else {
            cout << n << " " << x << "\n";
            print(a);
            exit(0);
        }
        cnt++;
    }
}

int main() {
    //stress();
    //return 0;
    ll t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        //auto res = bf(n, x, a);
        auto res = genius(n, x, a);
        cout << res << '\n';
    }
}

