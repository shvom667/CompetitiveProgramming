/*
    B. Jellyfish and Math
*/

#include <bits/stdc++.h>
using namespace std;
using ll = int;
using pl = pair<ll, ll>;
vector<ll> primes = {rand()+100, rand()+1, rand()+1};
ll M = 1e5 + 20;
const ll P = 998244353;

ll getHash(ll a, ll b) {    
    ll res =  (a + b) * (a + b + 1) / 2 + a;
    res=abs(res);
    return res%M;
}

ll U[(ll)1e5 + 20];

uint32_t Hash(ll x, ll y) {
    long long a, b;
    a = x;
    b = y;
    
    ll res =  (a * 0x1f1f1f1f) ^ b;
    cout << res%M << '\n';
    return abs(res);
}

auto genius(ll a, ll b, ll c, ll d, ll m) {

    // cout << a << " " << b << " " << c << " " << d << " " << m << "\n";
    queue<pl> Q;
    Q.push(make_pair(a, b));
    vector<ll> used;

    used.push_back(Hash(a, b));

    U[Hash(a, b)] = 0;
    
    ll t = 0;

    while (!Q.empty()) {
        t++;
        pl f = Q.front();

        if (f == make_pair(c, d)) {
            break;
        }
        Q.pop();
        vector<pl> nx;
        nx.push_back({(f.first & f.second), f.second});
        nx.push_back({f.first | f.second, f.second});
        nx.push_back({f.first, (f.first ^ f.second)});
        nx.push_back({f.first, f.second ^ m});
        for (auto& [p, q] : nx) {
            if (U[Hash(p, q)] == -1) {
                used.push_back(Hash(p, q));
                U[Hash(p, q)] = U[Hash(f.first, f.second)] + 1;
                Q.push({p, q});
            }
        }
    }

    ll fans = U[Hash(c, d)];

    if (used.size() >= 2000) {
        
        assert(false);

    } 
    
    for (auto& x : used) {
        U[x] = -1;
    }

    return fans;
}
auto solve(ll a, ll b, ll c, ll d, ll m) {
    ll fans = 0;

    map<pl, ll> w;

    w[{a, b}] = 0;
    queue<pl> Q;
    Q.push({a, b});

    ll t = 0;
    ll M = 2000;
    while (!Q.empty()) {
        t++;
        pl f = Q.front();
        // if (t >= 2000) {

        // }
        // if (f == make_pair(c, d)) {
        //     break;
        // }
        Q.pop();
        vector<pl> nx;
        nx.push_back({(f.first & f.second), f.second});
        nx.push_back({f.first | f.second, f.second});
        nx.push_back({f.first, (f.first ^ f.second)});
        nx.push_back({f.first, f.second ^ m});
        for (auto& [p, q] : nx) {
            if (w.find({p, q}) == w.end()) {
                w[{p, q}] = w[f] + 1;
                Q.push({p, q});
            }
        }
    }

    // if (w.find({c,d})  == w.end()) {
    //     return -1;
    // }
    // return (ll)w.size();
    // cout << w.size() << "\n";
    // assert((ll)w.size() <= 2000);
    return (ll)w.size();
}

auto getAll(ll a, ll b, ll c, ll d, ll m) {
    ll fans = 0;

    map<pl, ll> w;

    w[{a, b}] = 0;
    queue<pl> Q;
    Q.push({a, b});

    ll t = 0;
    ll M = 2000;
    while (!Q.empty()) {
        t++;
        pl f = Q.front();
        
        Q.pop();
        vector<pl> nx;
        nx.push_back({(f.first & f.second), f.second});
        nx.push_back({f.first | f.second, f.second});
        nx.push_back({f.first, (f.first ^ f.second)});
        nx.push_back({f.first, f.second ^ m});
        for (auto& [p, q] : nx) {
            if (w.find({p, q}) == w.end()) {
                w[{p, q}] = w[f] + 1;
                Q.push({p, q});
            }
        }
    }
    vector<pl> D[(ll)3e5];
    for (auto& [a, b]: w) {
        // cout << a.first << " " << a.second << " --> " << b << "\n";
        D[b].push_back(a);
    }
    for (ll i = 0; i <= 10; i++) {
        cout << "$$$$  " << i << "   $$$$" << '\n';
        for (auto & x : D[i]) {
            cout << x.first << " " << x.second << "\n";
        } 
    }
    return (ll)w.size();
}

void stress5() {
    ll tc = 0;
    for (ll a = 0; a < 10; a++) {
        for (ll b = 0; b < 10; b++) {
            for (ll c = 0; c < 10; c++) {
                for (ll d = 0; d < 10; d++) {
                    for (ll m = 0; m < 10; m++) {

                        genius(a, b, c, d, m);
                        // if (solve(a,b,c,d,m) == genius(a,b,c,d,m)) {
                        //     cout << a << " " << b << " " << c << " " << d <<
                        //     " " << m << "\n";
                        // } else {
                        //     assert(false);
                        // }
                    }
                }
            }
        }
    }
}

void stress4() {
    ll M = -1;
    while (true) {
        ll a, b, c, d, m;
        a = (rand() + 100);
        b = (rand() + 12);
        c = (rand() + 323);
        d = (rand() + 99);
        m = (rand() + 232);
        M = max(M, solve(a, b, c, d, M));
        cout << M << "\n";
    }
}
void stress3() {
    ll M = -1;
    for (ll a = 1000; a <= 1020; a++) {
        for (ll b = 1000; b <= 1020; b++) {
            for (ll c = 1000; c <= 1020; c++) {
                for (ll d = 1000; d <= 1020; d++) {
                    for (ll m = 1000; m <= 1020; m++) {
                        // cout << solve(a, b, c, d, m) << "\n";
                        M = max(M, solve(a, b, c, d, m));
                        cout << M << "\n";
                    }
                }
            }
        }
    }
}

void stress2() {
    ll M = -1;
    for (ll a = 100; a <= 1200; a++) {
        for (ll b = 100; b <= 1200; b++) {
            for (ll c = 100; c <= 1200; c++) {
                for (ll d = 100; d <= 1200; d++) {
                    for (ll m = 100; m <= 1200; m++) {
                        // cout << solve(a, b, c, d, m) << "\n";
                        M = max(M, solve(a, b, c, d, m));
                        cout << M << "\n";
                    }
                }
            }
        }
    }
}

void stress1() {
    ll M = -1;
    for (ll a = 1; a <= 20; a++) {
        for (ll b = 1; b <= 20; b++) {
            for (ll c = 1; c <= 20; c++) {
                for (ll d = 1; d <= 20; d++) {
                    for (ll m = 1; m <= 20; m++) {
                        // cout << solve(a, b, c, d, m) << "\n";

                        M = max(M, solve(a, b, c, d, m));
                        cout << M << "\n";
                    }
                }
            }
        }
    }
}

void stress6() {
    for (ll i = 0; i < 1e5; i++) {
        ll a, b, c, d, e;
        a = rand() % ((ll)1e9) + 1;
        b = rand() % ((ll)1e9) + 1;
        c = rand() % ((ll)1e9) + 1;
        d = rand() % ((ll)1e9) + 1;
        e = rand() % ((ll)1e9) + 1;
        // cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
        cout << i << " " << genius(a, b, c, d, e) << '\n';
        // if (solve(a,b,c,d,e) == genius(a,b,c,d, e)) {
        //     // cout << "ok" << "\n";
        // } else {
        //     // cout << a << " " << b << " " << c << " " << d << " " << e <<
        //     '\n'; assert(false);
        // }
    }
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    for (ll i = 0; i < 1e5 + 20; i++) {
        U[i] = -1;
    }

    // getAll(2,5,0,0,3);
    // return 0;

    // stress6();
    // return 0;

    int t;
    cin >> t;

    while (t--) {
        ll a, b, c, d, m;
        cin >> a >> b >> c >> d >> m;
        cout << genius(a, b, c, d, m) << '\n';
    }
}