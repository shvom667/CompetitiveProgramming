#include<bits/stdc++.h>

using namespace std;

// Function to generate a random array
std::vector<int> generateRandomArray(int n, int m, int M) {
    // Check if m is less than or equal to M
    if (m > M) {
        throw std::invalid_argument("Minimum value m should be less than or equal to maximum value M.");
    }

    // Create a random device and seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister engine

    // Define the range for random numbers
    std::uniform_int_distribution<> dis(m, M);

    // Generate the random array
    std::vector<int> array(n);
    for (size_t i = 0; i < n; ++i) {
        array[i] = dis(gen);
    }

    return array;
}

int main() {
    int len = 200000;
    vector<int> res = generateRandomArray(len, 1, 1e9);
    cout << 1 << "\n";
    cout << len << " " << (int)1e9 << '\n';
    // cout << *min_element(begin(res), end(res)) << '\n';
    for (int i = 0; i < len; i++) {
        cout << res[i] << " ";
    }   cout << "\n";
    vector<int> res2 = generateRandomArray(len, 1, 1e9);
    for (int i = 0; i < len; i++) { 
        cout << 1 << " ";
    }   
}