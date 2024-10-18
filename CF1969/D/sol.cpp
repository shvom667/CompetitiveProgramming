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
#endif
void chmax(ll& a, ll b){
    a = max(a, b);
}
auto solve(ll n, ll k, vector<ll> a, vector<ll> b) {
    for (ll i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            a[i] = b[i] = 0;
        }
    }
    vector<ll> I(n, 0);
    for (ll i = 0; i < n; i++) {
        I[i] = i;
    }
    sort(begin(I),end(I),[&](ll x, ll y){
        return b[x] < b[y];
    });
    for (ll i = 0; i < n; i++) {
        cout << a[I[i]] << " ";
    }   cout << "\n";
    for (ll i = 0; i < n; i++) {
        cout << b[I[i]] << " ";
    }   cout << "\n";
    multiset<ll> gr;
    ll totsum=0;
    for (ll j = 0; j < n; j++) {
        totsum += b[j] - a[j];
    }
    ll sum=0;
    for (ll j = n - 1; j >= n - k; j--) {
        ll i = I[j];
        gr.insert(2*b[i] + a[i]);
        sum += 2*b[i] + a[i];
        totsum -= b[i] - a[i];
    }
    dbg(totsum, sum);
    ll fans = 0;
    chmax(fans, totsum - sum);
    for (ll j = n - k - 1; j >= 0; j--) {
        ll i = I[j];
        totsum -= b[i] - a[i];
        if (!gr.empty() && *gr.rbegin() > 2*b[i] + a[i]) {
            sum -= *gr.rbegin();
            gr.erase(gr.find(*gr.rbegin()));
            sum += 2 * b[i] + a[i];
            gr.insert(2*b[i] + a[i]);
        }
        fans = max(fans, totsum - sum);
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

// auto stress() {
//     while (true) {
//         ll n, k;
//         n = rnd(1, 10);
//         k = rnd(0, n);
//         vector<ll> a(n), b(n);
//         for (ll i = 0; i < n; i++) {
//             a[i] = rnd(1, 10);
//             b[i] = rnd(1, 10);
//         }
//         ll sans = solve(n, k, a, b);
//         ll bans = bf(n, k, a, b);
//         if (sans == bans) {
//             cout << "OK\n";
//         } else {
//             cout << "NOT OK\n";
//             dbg(n, k);
//             dbg(a);
//             dbg(b);
//             dbg(bans);
//             dbg(sans);
//             exit(0);
//         }
//     }
// }

int main() {
    // stress();
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);

        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < n; i++)
            cin >> b[i];
        auto res = bf(n, k, a, b);
        cout << res << "\n";
    }
    return 0;
}
