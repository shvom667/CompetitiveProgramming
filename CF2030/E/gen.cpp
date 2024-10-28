#include <bits/stdc++.h>
using ll = int;
using namespace std;

int rand(int a, int b)
{
    return a + rand() % (b - a + 1);
}



int main(int argc, char *argv[])
{
    srand(atoi(argv[1]));    
    std::mt19937 rng(atoi(argv[1])); 

    auto rnd = [&] (ll a, ll b) {
        return a + rng() % (b - a + 1);
    };
    ll n;
    n = rnd(16, 16);
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        a[i] = rnd(0, n-1);
    }
    
    cout << n << '\n';
    for (auto&x: a){
        cout << x << " ";
    }   cout << '\n';
}
