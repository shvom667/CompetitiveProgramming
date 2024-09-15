/*
    C. Eri and Expanded Sets
*/

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int long long

void print(vector<ll> x) {
    for (auto&y : x) {
        cout << y << " ";
    }   cout << '\n';
}

ll gcd(ll a, ll b) {
    if (a == 0 || b == 0) {
        return max(a, b);
    }
    return __gcd(a, b);
}

auto solve(ll n, vector<ll> a) {
    ll fans = 0;

    for (ll i = 0; i < n; i++) {
        for (ll j = i; j < n; j++) {
            vector<ll> s;
            for (ll k = i; k <= j; k++) {
                s.push_back(a[k]);
            }
            sort(begin(s), end(s));
            ll g = 0;
            for (ll k = 1; k < s.size(); k++) {
                ll d = s[k] - s[k-1];
                g = gcd(d, g);
            }
            while (g > 0 && g % 2 == 0) {
                g/=2;
            }
            if (g<=1) {
                // print(s);
                fans++;
            }
        }
    }
    return fans;
}



auto genius(ll N, vector<ll> b) {
    ll fans = 0;
    ll n = N - 1;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        a[i] = abs(b[i+1] - b[i]);
    }

    vector<vector<ll>> g(30, vector<ll> (n));
    for (ll i = 0; i < 30; i++)
        for (ll j = 0; j < n; j++) 
            g[i][j] = 0;

    for (ll j = 0; j < n; j++) {
        g[0][j] = a[j];
    }
    for (ll i = 1; i < 30; i++) {
        for (ll j = 0; j < n; j++) {
            g[i][j] = gcd(g[i-1][min(n-1, j)], g[i-1][min(n-1, j + (1ll<<i-1))]);
        }
    }

    auto query = [&] (ll l, ll r) {
        ll g2 = log2(r-l);
        return gcd(g[g2][l], g[g2][r-(1ll<<g2)+1]);
    };


    // for (ll i = 0; i < n;  i++) {
    //     for (ll j = i + 1; j < n; j++) {
    //         cout << i << " " << j << " " << query(i, j) << "\n";
    //     }
    // }

    // print(a);

    for (ll i = 0; i < n; i++) {
        ll l = i, r = n - 1;

        while (l <= r) {
            ll mid = l + (r - l) / 2;
            auto cond = [&] (ll x) {
                ll g = query(i, x);
                while (g > 0 && g % 2 == 0) {
                    g /= 2;
                }
                if (g != 0 && g == 1) {
                    return true;
                }
                return false;
            };
            if (cond(mid)) {
                r = mid - 1;
                
            } else {
                l = mid + 1;
            }
        }
        // l = min(n-1,l);
        
        // cout << i << " " << r << "\n";
        // cout << i << " " << l << "\n";
        fans += (n - l);
    }

    ll inc=0;
    for (ll i=0,val=-1e9-20,cnt = 0; i < N; i++) {
        if(b[i] == val) {
            cnt++;
            inc += cnt;
        } else {
            val = b[i];
            cnt = 1;
            inc += cnt;
        }
    }
    fans += inc;
    // cout << "inc " << inc << '\n';

    return fans;
}

std::vector<int> generate_array(int n, int l, int r) {
    std::vector<int> arr;
    std::srand(std::time(0)); // Seed for randomness

    for (int i = 0; i < n; ++i) {
        int num = l + std::rand() % (r - l + 1); // Generate random number in the range [l, r]
        arr.push_back(num);
    }

    return arr;
}
void stress() {
    while (true) {
        ll n = (rand()+10)%50+1;
        vector<ll> a = generate_array(n, 1, 1000);
        if (solve(n, a) == genius(n, a)) {
            cout << "ok" << '\n';
            cout << n << "\n";
            print(a); 
        } else {
            cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$44\n";
            cout << "not ok" << "\n";
            cout << n << "\n";
            print(a);
            cout << solve(n, a) << " " << genius(n, a) << "\n";
            cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$44\n";
            assert(false);
        }

    }
}

signed main() {

    // stress();
    // return 0;

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        // cout << solve(n, a) << '\n';
        cout << genius(n, a) << "\n";
        // if (solve(n, a) == genius(n, a)) {
        //     cout << "ok" << '\n';
        // } else {
        //     cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$44\n";
        //     cout << "not ok" << "\n";
        //     cout << n << "\n";
        //     print(a);
        //     cout << solve(n, a) << " " << genius(n, a) << "\n";
        //     cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$44\n";
        // }
    }
}