#include <iostream>
#include <unordered_map>

using namespace std;

bool cond(int M) {
    unordered_map<int, int> d;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= M; ++j) {
            d[i * j]++;
        }
    }

    cout << d.size() << endl;
    return d.size() >= 1000000;
}

int main() {
    int L = 1;
    int R = 2043;
    int result = -1;

    while (L <= R) {
        int mid = L + ((R - L) >> 1);
        if (cond(mid)) {
            result = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }

    cout << L << endl;
    return 0;
}
