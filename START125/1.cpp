#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) solve();
}

void solve() {
    ll n;
    cin >> n;
    Vec<ll> a(n);
    ll o = 0, e = 0;
    ll xall = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        xall ^= a[i];
        if (a[i] & 1) o++;
        else e++;
    }
    if (e == n) {
        cout << "Bob\n";
        return;
    }
    if (o & 1) {
        cout << "Alice\n";
        return;
    }
    if (o >= e) {
        cout << "Draw\n";
        return;
    }
    cout << "Bob\n";
}
