#include<bits/stdc++.h>

using namespace std;
using ll = long long;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

int main() {
    ll t;
    cin >> t;  // Number of test cases

    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;  // Read n, m, k

        vector<ll> a(n), b(m);

        // Read the arrays a and b
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < m; i++) {
            cin >> b[i];
        }

        // Perform the operation k times
        for (ll t = 0; t < k; t++) {
            ll fans = 0;
            ll best_i = 0, best_j = 0;

            // Loop over all pairs (i, j)
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < m; j++) {
                    ll cur = a[i] - (a[i] & b[j]);
                    if (cur > fans) {
                        fans = cur;
                        best_i = i;
                        best_j = j;
                    }
                }
            }

            dbg(fans);

            // Update a[best_i] after the best pair is found
            a[best_i] = a[best_i] & b[best_j];
        }

        // Calculate the sum of the array a
        ll sum_a = 0;
        for (ll i = 0; i < n; i++) {
            sum_a += a[i];
        }

        // Output the result for the current test case
        cout << sum_a << endl;
    }

    return 0;
}
