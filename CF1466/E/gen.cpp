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
    const ll inf =1e18;
    cout << 1 << '\n';
    ll N = 5e5;
    cout<<N<<'\n';
    for(ll i=1;i<=N;i++)
        cout<<rnd(0,inf)<<' ';
    cout<<'\n';
    return 0;
}
