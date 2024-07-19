#include <iostream>
#include <vector>
#include <random>
using namespace std;
std::vector<std::vector<int>> generateRandomMatrix(int n, int m, int M) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, M);

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = dis(gen);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          matrix[i][j] += 100;
        }
    }

    return matrix;
}

int main() {
    int n = 100; // Number of rows
    int m = 100; // Number of columns
    int M = 1000; // Maximum value for random numbers

    std::vector<std::vector<int>> randomMatrix = generateRandomMatrix(n, m, M);
    cout << n << " " << m << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << randomMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
