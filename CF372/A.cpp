#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0, s; i < n; ++i) {
        std::cin >> s;
        v[i] = s;
    }
    std::sort(v.begin(), v.end());
    int min_kangaroos, kangaroos = 0;
    bool n_odd = n % 2 == 1;
    std::unordered_multiset<int> s;
    if (n == 1) {
        min_kangaroos = 1;
    } else {
        for (int i = 0; i < n / 2; ++i) {
            bool temp = v[i + n / 2 + n_odd] >= 2 * v[i];
            if (temp) {
                ++kangaroos;
            } else {
                s.insert(i);
                kangaroos += 2;
            }
        }
        min_kangaroos = kangaroos + n_odd;
        for (int i = 1; i < n / 2; ++i) {
            if (v.back() >= 2 * v[n / 2 - i]) {
                ++kangaroos;
            }
            auto j = s.begin();
            while (j != s.end()) {
                if (*j >= n / 2 - i) {
                    j = s.erase(j);
                } else if (v[*j + n / 2 + i + n_odd] >= 2 * v[*j]) {
                    j = s.erase(j);
                    --kangaroos;
                } else {
                    ++j;
                }
            }
            if (kangaroos < min_kangaroos) {
                min_kangaroos = kangaroos;
            }
        }
    }
    std::cout << min_kangaroos << std::endl;
    return 0;
}
