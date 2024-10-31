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
const ll N = 2e5 + 20;
ll a[N];
ll n, m;
auto solve() {
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 3, a + n + 1);
    ll fans = 1e18;
    for (ll i = 3; i + m - 1 <= n; i++) {
        ll cur = 0;
        cur += max(0ll, a[1] - a[i]);
        cur += max(0ll, a[i + m - 1] - a[2]);
        fans = min(fans, cur);
    }
    cout << fans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    solve();
    return 0;
}
