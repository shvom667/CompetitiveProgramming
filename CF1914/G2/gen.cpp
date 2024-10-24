#include <bits/stdc++.h>
using ll = int;
using namespace std;



int main(int argc, char *argv[])
{
    mt19937 rng(atoi(argv[1]));

    ll n;
    
    auto rand = [&] (int a, int b)
    {
        return a + rng() % (b - a + 1);
    };

    n = rand(1, 10);


    vector<ll> a(2 * n);

    for (ll i = 0; i < n; i++)
    {
        a[2 * i] = i + 1;
        a[2 * i + 1] = i + 1;
    }

    shuffle(begin(a), end(a), rng);

    cout << n << "\n";
    for (auto &x : a)
        cout << x << " ";
    cout << '\n';
}
