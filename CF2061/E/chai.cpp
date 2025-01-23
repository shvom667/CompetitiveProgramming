#include<bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

// Function to handle a single test case
long long solve(int n, int m, int k, vector<int>& a, vector<int>& b) {
    long long sum = 0;

    // Initial sum of all elements in a
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    // Map to track all AND combinations from subsets of b

    // Frequency map for the prefixes of elements in a
    map<long long, int> mp;

    // Fill the map with prefixes of elements in a
    for (int i = 0; i < n; i++) {
        int prefix = 0;
        for (int bit = 29; bit >= 0; bit--) {
            if (((a[i] >> bit) & 1)) {
                prefix |= ((a[i] >> bit) & 1) << bit;
                mp[prefix]++;
            }
        }

    }
    
    dbg(mp);
    // Process k times
    for (int t = 0; t < k; t++) {
        int cur = 0;
        vector<int> seen_prefixes;

        // Try setting bits from 29 to 0
        for (int bit = 29; bit >= 0; bit--) {
            cur |= (1LL << bit);  // Set the current bit in cur
            bool ok = false;

            for (int j = 0; j < m; j++) {
                int rcur  = (cur & b[j]);
                if (rcur == 0) {
                    ok = true;
                }
            }
            if (mp.find(cur) != mp.end() && mp[cur] > 0 && ok) {  // Check if the current prefix exists in map and seen in b
                seen_prefixes.push_back(cur);
            } else {
                cur &= ~(1 << bit);  // Unset the bit if condition is not met
            }
        }

        dbg(cur);

        dbg(seen_prefixes);
        // Decrease the frequency of all seen prefixes
        for (auto& prefix : seen_prefixes) {
            mp[prefix]--;
            if (mp[prefix] == 0) {
                mp.erase(prefix);
            }
        }

        dbg(mp);

        // Subtract the current value of cur from sum
        sum -= cur;
    }

    return sum;
}

int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;  // Read n, m, k

        vector<int> a(n), b(m);

        // Read arrays a and b
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        // Call the solve function for each test case and print the result
        cout << solve(n, m, k, a, b) << endl;
    }

    return 0;
}
