
#include<bits/stdc++.h>
using namespace std;


#define pyes cout << "YES\n";
#define pno cout << "NO\n";

using ll=long long;

template <typename T>
using V = vector<T>;

#define pb push_back

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)solve();
}

void solve() {
    ll n,k;
    cin>>n>>k;
    ll c[n];
    for (ll i=0; i<n; i++) {
        cin >> c[i];
    }
    if (c[0] == c[n-1]) {
        ll cnt = count(c,c+n,c[0]);
        if (cnt >= k) {
            pyes;
        } else {
            pno;
        }
        return;
    }
    V<ll> fst, lst;
    for (ll i = 0; i < n; i++) {
        if (c[i]==c[0]) fst.pb(i);
    }
    for (ll i = n - 1; i >= 0; i--) {
        if (c[i] == c[n-1]) lst.pb(i);
    }
    while(fst.size() > k) fst.pop_back();
    while(lst.size() > k) lst.pop_back();
    if (fst.size() < k || lst.size() < k) {
        pno;
        return;
    }
    if (fst.back() > lst.back()) {
        pno;
        return;
    }
    pyes;

}
