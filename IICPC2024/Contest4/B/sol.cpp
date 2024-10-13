#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;


auto solve() {
    string res;
    res="S";
    ll n,x,y;cin>>n>>x;
    for (ll i = 2; i <= n; i++) {
        cin>>y;
        if(y>x)res="N";
    }

    return res;
}

int main() {
    ll T;
    T=1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
