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
    ll n = rnd(1,7);
    vector<ll> a(n);
    for (ll i = 0; i<n;i++){
        a[i] = i + 1;
    }
    shuffle(begin(a) + 1,end(a),rng);
    cout<<1<<'\n';
    cout<<n<<'\n';
    for(auto x:a)
        cout<<x<<' ';
    cout<<'\n';
    return 0;
}
