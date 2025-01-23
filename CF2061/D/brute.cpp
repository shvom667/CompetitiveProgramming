#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);

    // Read arrays a and b
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    // Perform the operation k times
    for (int t = 0; t < k; t++) {
        int fans = 0;
        int best_i = 0, best_j = 0;

        // Loop over all pairs (i, j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cur = a[i] - (a[i] & b[j]);
                if (cur > fans) {
                    fans = cur;
                    best_i = i;
                    best_j = j;
                }
            }
        }

        // Update a[best_i] after the best pair is found
        a[best_i] = a[best_i] & b[best_j];
    }

    // Calculate the sum of the array a
    int sum_a = 0;
    for (int i = 0; i < n; i++) {
        sum_a += a[i];
    }

    // Output the result
    cout << sum_a << endl;

    return 0;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
