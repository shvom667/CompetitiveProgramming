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
    ll n=rnd(1,20);
    string s="";
    for(ll i=0;i<n;i++){
        ll x=rnd(0,1);
        s += 'A'+x;
    }
    cout<<n<<'\n';cout<<s<<'\n';
    return 0;
}
