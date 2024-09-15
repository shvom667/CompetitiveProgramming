

#include<bits/stdc++.h>
using namespace std;
using ll=int;

void print(vector<ll> x) {
    for (auto&y : x) {
        cout << y << " ";
    }   cout << '\n';
}

ll gcd(ll a, ll b) {
    if (a == 0 || b == 0) {
        return max(a, b);
    }
    return __gcd(a, b);
}

std::vector<int> generate_array(int n, int l, int r) {
    std::vector<int> arr;
    std::srand(std::time(0)); // Seed for randomness

    for (int i = 0; i < n; ++i) {
        int num = l + std::rand() % (r - l + 1); // Generate random number in the range [l, r]
        arr.push_back(num);
    }

    return arr;
}

int way1(ll n, vector<ll> v) {
    ll g = 0;
    // sort(begin(v), end(v));
    for (ll i = 1; i < n; i++) {
        g = gcd(g, abs(v[i]-v[i-1]));
    }
    return g;
}

int way2(ll n, vector<ll> v) {
    ll g = 0;
    sort(begin(v), end(v));
    for (ll i = 1; i < n; i++) {
        g = gcd(g, abs(v[i]-v[i-1]));
    }
    return g;
}

int main() {
    int itr = 0;
    while (true) {
        ll n = 10;
        vector<ll> v = generate_array(n, 1, 1000);

        if (way1(n, v) == way2(n, v)) {
            cout << "ok " << itr << " " << way1(n, v) << "\n";
            
        } else {
            print(v);
            assert(false);
        }

        itr++;
    }    
}