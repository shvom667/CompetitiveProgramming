#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Function to generate a random vector with elements between l and r
std::vector<int> generateRandomVector(int size, int l, int r) {
    // Create a random device and use it to seed a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(l, r);

    // Create a vector of the specified size and fill it with random numbers
    std::vector<int> vec(size);
    for (int i = 0; i < size; ++i) {
        vec[i] = dist(gen);
    }

    return vec;
}

int main() {
    int size = 2e5; // Example size
    int l = 1;     // Example lower bound
    int r = 1e8;   // Example upper bound

    std::vector<int> randomVector = generateRandomVector(size, l, r);

    cout << 1 << '\n';
    cout << size << " " << 1 << "\n";
    for (int num : randomVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

