#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;


auto solve() {
    ll x,y;
    cin>>x>>y;
    ll t=x*y;
    Vec<ll>res;
    for (ll k=10;k<=90;k+=10){
        res.pb((k*t+100-1)/100);
    }
    return res;
}

int main() {
    ll T;
    T=1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        for(auto&x:res)
            cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
}
