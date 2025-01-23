#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Recursive function to process each element in sb
bool solve(int x, unordered_map<int, int>& sa) {
    if (sa.find(x) != sa.end() && sa[x] > 0) {
        // If x is present in sa, erase one instance from sa
        sa[x]--;
        return true;
    }
    
    // If x is smaller than the minimum element in sa, return false
    if (sa.empty() || x < sa.begin()->first) {
        return false;
    }
    
    // If x is even, break it into a = x/2, b = x/2
    if (x % 2 == 0) {
        return solve(x / 2, sa) && solve(x / 2, sa);
    }
    // If x is odd, break it into a = (x+1)/2, b = x/2
    else {
        return solve((x + 1) / 2, sa) && solve(x / 2, sa);
    }
}

// Function to solve the problem
string processTestCase(vector<int>& a, vector<int>& b) {
    long long sum_a = 0, sum_b = 0;
    
    // Calculate the sum of elements in a and b
    for (int x : a) sum_a += x;
    for (int x : b) sum_b += x;
    
    // If sums are not equal, return "No"
    if (sum_a != sum_b) return "No";
    
    // Remove common elements from a and b
    unordered_map<int, int> sa, sb;
    
    for (int x : a) sa[x]++;
    for (int x : b) sb[x]++;
    
    for (auto& [key, count] : sb) {
        if (sa.find(key) != sa.end() && sa[key] > 0) {
            int common_count = min(sa[key], count);
            sa[key] -= common_count;
            sb[key] -= common_count;
        }
    }

    // Now process elements in sb recursively
    bool all_good = true;
    for (auto& [x, count] : sb) {
        while (count-- > 0) {
            if (!solve(x, sa)) {
                all_good = false;
                break;
            }
        }
        if (!all_good) break;
    }

    return all_good ? "Yes" : "No";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        
        cout << processTestCase(a, b) << endl;
    }

    return 0;
}
