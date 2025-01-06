#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto&x:a)cin>>x;
    ll m=*min_element(begin(a),end(a));
    ll M=*max_element(begin(a),end(a));
    vector<ll> fans;

    while(M-m>1){
        if((M-m)%2==0){
        m/=2;
        M/=2;
        fans.pb(0);}else{
            if(m%2==0){
                fans.pb(0);
                m/=2;
                M/=2;
            }else{
                fans.pb(1);
                m++;M++;
                m/=2;
                M/=2;
            }

        }
    }
    if(M-m==1){
        if(m%2==0){
            fans.pb(0);
        }else{
            fans.pb(1);
        }
    }
    cout<<(ll)fans.size()<<'\n';
    if((ll)fans.size()<=n){
        for(auto x: fans){
            cout<<x<<" ";
        }
        cout<<'\n';
    }

    
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
    }
    return 0;
}
