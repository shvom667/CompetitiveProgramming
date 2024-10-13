#include <bits/stdc++.h>

using namespace std;

mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y)
{
    return uniform_int_distribution<int>(x, y)(rng);
}
std::vector<int> generateRandomPermutation(int n) {
    // Create a vector containing elements from 1 to n
    std::vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1;
    }

    // Initialize the Mersenne Twister random number generator
    std::random_device rd;  // Seed with a real random value, if available
    std::mt19937 mt(rd());  // Initialize the Mersenne Twister engine

    // Shuffle the vector to get a random permutation
    std::shuffle(permutation.begin(), permutation.end(), mt);

    return permutation;
}
int main()
{
    int T = 1;
    cout << T << "\n";
    while (T--)
    {
        int n, q;
        n = rnd(63, 63);
        q = rnd(200000, 200000);
        cout << n << " " << q << "\n";
        for (int i = 2; i <= n; i++) {
            cout << i / 2 << " ";
        } cout << "\n";
        vector<int> p = generateRandomPermutation(n);
        for (auto& x: p)
            cout << x << " ";
            cout << "\n";
        
        while (q--)  {
            int x , y;
            x = rnd(1, n-1);
            y = rnd(x + 1, n);
            cout << x << " " << y << "\n";
        }
    }
}
