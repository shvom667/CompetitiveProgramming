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

    ll n = rand(5, 5);
    ll q = rand(1, 3);

    vector<ll> a(n);

    for (ll i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    shuffle(begin(a), end(a), rng);

    vector<char> s(n);

    for (ll i = 0; i < n; i++) {
        s[i] = (rand(0,1) == 0 ? 'L' : 'R');
    }

    vector<ll> Q(q);
    
    for (ll i = 0; i < q; i++) {
        Q[i] = rand(1, n);
    }

    cout << n << " " << q << "\n";
    for (auto &x : a)
        cout << x << " ";
    cout << '\n';
    for (auto&x : s) {
        cout <<x;
    }
    cout << '\n';
    for (auto& x: Q) {
        cout << x << "\n";
    }
        
}
