#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
 
auto solve(ll n, ll k, vector<ll> a, vector<ll> b) {
    vector<ll> I(n, 0);
    for (ll i = 0; i < n; i++) {
        I[i] = i;
    }
    sort(begin(I),end(I),[&] (ll x, ll y) {
        return b[x] < b[y];
    });
    vector<ll> dp(n, 0);

    // for (ll i = 0; i < n; i++) {
    //     cout << a[I[i]] << " \n"[i == n - 1];
    // }
    // for (ll i = 0; i < n; i++) {
    //     cout << b[I[i]] << " \n"[i == n - 1];
    // }

    for (ll j = 0; j < n; j++) {
        ll i = I[j];
        dp[j] = max(0ll, b[i] - a[i]);
        if (j) {
            dp[j] += dp[j-1];
        }
    }
    multiset<ll> sm;
    ll sum = 0;
    for (ll i = n - 1; i >= n - k; i--) {
        ll j = I[i];
        sm.insert(a[j]);
        sum += a[j];
    }
    ll fans = 0;
    if (k < n) {
        fans = max(fans, dp[n-k-1] - sum);
        for (ll j = n -k -1; j >= 0; j--) {
            ll i = I[j];
            sm.insert(a[i]);
            sum += a[i];
            if (sm.size() > k) {
                ll b = *sm.rbegin();
                sum -= b;
                sm.erase(sm.find(b));
            }
            if (j - 1 >= 0) {
                fans = max(fans, dp[j - 1] - sum);
            }
        }
    }
    return fans;
}

auto bf(ll n, ll k, vector<ll> a, vector<ll> b) {
    ll fans=0;
    for (ll mask=1;mask<(1ll<<n);mask++) {
        if (__builtin_popcount(mask)<k)continue;
        vector<ll> cura,curb;
        for (ll bit=0; bit<n; bit++) {
            if (mask&(1ll<<bit)) {
                cura.pb(a[bit]);
                curb.pb(b[bit]);
            }       
        }
        ll sum=0;
        for(auto&x:cura) sum-=x;
        for(auto&x:curb) sum +=x;
        sort(begin(curb),end(curb),greater<ll>());
        for(ll i=0;i<k;i++) sum-=curb[i]; 
        fans=max(fans,sum);
    }
    return fans;
}

auto stress() {
    while (true) {
        ll n, k;
        n = rnd(1, 20);
        k = rnd(0, n);
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++) {
            a[i] = rnd(1, 1000);
            b[i] = rnd(1, 1000);
        }
        ll sans = solve(n, k, a, b);
        ll bans = bf(n, k, a, b);
        if (sans == bans) {
            cout << "OK\n";
        } else {
            cout << "NOT OK\n";
            dbg(n, k);
            dbg(a);
            dbg(b);
            dbg(bans);
            dbg(sans);
            exit(0);
        }
    }
}

int main() {

    // stress();

	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> b(n);
        for (ll i = 0; i < n; i++) {
            cin >> b[i];
        }
        auto res = solve(n,k,a,b);
        cout << res << "\n";
    }
    return 0;
}
