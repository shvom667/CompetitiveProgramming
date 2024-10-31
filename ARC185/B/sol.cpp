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

auto solve() {

    string no = "No";
    string yes = "Yes";

    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<ll> b(n);

    ll cnt = 1;

    for (ll j = n - 1; j >= 0; j--) {
        b[j] = sum / n;
        if (cnt <= sum % n) {
            cnt++;
            b[j]++;
        }
    }

    dbg(b);

    ll sup = 0;
    for (ll i = n - 1; i >= 0; i--) {
        if (a[i] > b[i]) {
            sup += a[i] - b[i];
        }
        if (a[i] < b[i]) {
            ll diff = min(sup, b[i] - a[i]);
            if (diff < b[i] - a[i]) {
                return no;
            }
            sup -= diff;
        }
    }


    return yes;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
