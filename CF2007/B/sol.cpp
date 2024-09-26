#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 20;
ll n, q;
ll a[N];
auto solve() {
    ll M = *max_element(a+1, a+n+1);
    while (q--) {
        char c;
        ll l , r;
        cin >> c;
        cin >> l >> r;
        if (M >= l && M <= r) {
            if (c == '+') M++;
            else M--;
        }
        cout << M << " ";
    }
    cout << "\n";

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        solve();
    }
      
}
