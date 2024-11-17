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
vector<ll> a101;
vector<ll> a(27);
auto solve(ll n) {
    
    vector<ll> fans;
    if (n & 1) {
        if (n < 27) {
            cout << -1 << "\n";
            return;
        }
        for (auto&x : a) {
          fans.pb(x);
        }
        for (ll i = 28; i <= n; i+=2) {
            fans.pb(i);
            fans.pb(i);
        } 

    } else {
        for (ll i = 0; i < n; i+=2) {
            fans.pb(i + 1);
            fans.pb(i + 1);
        }
    }
    

    for (auto&x:fans) {
        cout << x << " ";
    }   cout << '\n';
    
    
}

void bf() {
    for (ll n = 1; n <= 1000; n++) {
        dbg(n);
        solve(n);
    }
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    // a101 = vector<ll> (101, 0);
    // a101[0] = 1;
    // a101[36] = 1;
    // a101[100] = 1;

    // ll cnt = 2;
    // for (ll i = 1; i <= 35; i++) 
    // {
    //     a101[i] = cnt;
    //     a101[i + 36] = cnt;
    //     cnt++;
    // }

    // for (ll i = 72; i < 100; i+=2) {
    //     a101[i] = cnt;
    //     a101[i + 1] = cnt;
    //     cnt++;
    // }

    // dbg(a101);


    // for (ll i = 0; i < 101; i++) {
    //     for (ll j = 0; j < 101; j++){
    //         if (a101[i] == a101[j] && i != j) {
    //             ll d = abs(i - j);
    //             dbg(i, j, a101[i], a101[j]);
    //             assert(d == 1 || d == 4 || d == 16 || d == 36 || d == 64 || d == 100);
    //             dbg("hello");
    //         }
    //     }
    // }
    
    a[0] = 1;
    a[9] = 1;
    a[25] = 1;
    ll cnt = 2;
    for (ll i = 1; i < 9; i++) {
        a[i] = cnt;
        a[i + 9] = cnt;
        cnt++;
    }
    // dbg(a);
    
    for (ll i = 18; i < 22; i+=2) {
        
        a[i] = a[i + 1] = cnt;
        cnt++;
    }
    a[22] = cnt;
    a[26] = cnt;
    cnt++;
    a[23] = cnt;
    a[24] = cnt;

    // dbg(a);

    // bf();

    // return 0;

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        // auto res = solve();
        // cout << res << "\n";
        ll n; cin >> n;
        solve(n);
    }
    return 0;
}
