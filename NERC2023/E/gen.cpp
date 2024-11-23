#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

int main(int argc, char** argv) {
    mt19937 rng(atoi(argv[1]));
    auto rnd = [&] (ll a, ll b) {
        return a + rng() % (b - a + 1);
    };
    ll n = rnd(2, 100); 
    set<pair<ll,ll>> v;
    for (ll i = 1; i <= n; i++) {
        ll r=rnd(0,1);
        if (r==0)
            v.insert({1,rnd(2,50)});
        if(r==1)
            v.insert({rnd(2,50),1});
    }
    n = v.size();
    cout << n << "\n";
    for (auto&[u,v]:v){
        cout << u << " " << v << '\n';
    }
    return 0;
}
