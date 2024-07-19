#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/* GP HASH TABLE
 * Faster than unordered map
 * Uses more memory
 * 1024 mb, 524 mb
 * In this code 2d map, where map[x] = y, is inserted in array, gives a 2d structure
 */

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct splitmix64 {
    size_t operator()(size_t x) const {
        static const size_t fixed = chrono::steady_clock::now().time_since_epoch().count();
        x += 0x9e3779b97f4a7c15 + fixed;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
};

const ll N = 1e5;
gp_hash_table<int, int, splitmix64> mp[N];

void solve() {
}

int main() {

  return 0;
}
