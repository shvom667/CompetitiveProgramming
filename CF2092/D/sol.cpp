// Deepseek R1

#include <bits/stdc++.h>
using namespace std;

char getThird(char a, char b) {
    if (a > b) swap(a, b);
    if (a == 'L' && b == 'I') return 'T';
    if (a == 'L' && b == 'T') return 'I';
    if (a == 'I' && b == 'T') return 'L';
    return ' '; // Should not reach here
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        // Check if all characters are the same
        bool allSame = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[0]) {
                allSame = false;
                break;
            }
        }
        if (allSame) {
            if (n == 0) {
                cout << 0 << endl;
            } else {
                cout << -1 << endl;
            }
            continue;
        }

        // Check current counts
        int cntL = 0, cntI = 0, cntT = 0;
        for (char c : s) {
            if (c == 'L') cntL++;
            else if (c == 'I') cntI++;
            else if (c == 'T') cntT++;
        }
        if (cntL == cntI && cntI == cntT) {
            cout << 0 << endl;
            continue;
        }

        // Find possible k
        int max_cnt = max({cntL, cntI, cntT});
        int sum = n;
        int m = -1;
        int target_k = -1;
        bool found_k = false;
        for (int k = max_cnt; k <= (sum + 2 * n) / 3; ++k) {
            m = 3 * k - sum;
            if (m < 0 || m > 2 * n) continue;
            int dL = k - cntL;
            int dI = k - cntI;
            int dT = k - cntT;
            if (dL >= 0 && dI >= 0 && dT >= 0) {
                target_k = k;
                found_k = true;
                break;
            }
        }
        if (!found_k) {
            cout << -1 << endl;
            continue;
        }

        int dL = target_k - cntL;
        int dI = target_k - cntI;
        int dT = target_k - cntT;

        vector<char> current(s.begin(), s.end());
        vector<int> insertions;

        while (dL > 0 || dI > 0 || dT > 0) {
            bool found = false;
            for (size_t i = 0; i < current.size() - 1; ++i) {
                char a = current[i];
                char b = current[i + 1];
                if (a == b) continue;
                char c = getThird(a, b);
                int* delta = nullptr;
                if (c == 'L') delta = &dL;
                else if (c == 'I') delta = &dI;
                else if (c == 'T') delta = &dT;
                else continue;

                if (*delta > 0) {
                    // Insert c between i and i+1 (0-based)
                    current.insert(current.begin() + i + 1, c);
                    insertions.push_back(i + 1); // 1-based
                    (*delta)--;
                    found = true;
                    break;
                }
            }
            if (!found) {
                // Can't insert anymore
                break;
            }
        }

        if (dL != 0 || dI != 0 || dT != 0) {
            cout << -1 << endl;
        } else {
            cout << insertions.size() << endl;
            for (int pos : insertions) {
                cout << pos << endl;
            }
        }
    }
    return 0;
}