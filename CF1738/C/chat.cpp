#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);

    int ce = 0, co = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            ce++;
        } else {
            co++;
        }
    }

    if (ce == 0) {
        // Just odd case
        if (co % 4 == 0 || co % 4 == 3) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    } else if (co == 0) {
        // Just even case
        cout << "Alice\n";
    } else {
        if (ce % 2 == 0) {
            // ce is even, normalization by Bob
            if (co % 4 == 0 || co % 4 == 3) {
                cout << "Alice\n";
            } else {
                cout << "Bob\n";
            }
        } else {
            // ce is odd, Alice makes a move
            int half_n = n / 2;
            half_n += (n & 1);
            if (half_n % 2 == 1) {
                // floor(n / 2) is odd
                cout << "Alice\n";
            } else {
                // floor(n / 2) is even
                if (n % 2 == 0) {
                    cout << "Alice\n";
                } else {
                    cout << "Bob\n";
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
