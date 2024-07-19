#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  t = 1;
  while (t--) solve();
}
std::vector<int> generateRandomArray(int size, int M) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, M);

    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }
    return arr;
}

void solve() {
  ll r, c;
  cin >> r >> c;
  Vec<ll> res = generateRandomArray(r*c, 1);
  Vec<Vec<ll>> g(r, Vec<ll> (c, 0));
  for (ll i = 0; i < r; i++)
    for (ll j = 0; j < c; j++)
      g[i][j] = res[i*c + j];

  cout << r << " " << c << "\n";
  for (ll i = 0; i < r; i++)
    for (ll j = 0; j < c; j++)
      cout << g[i][j] << " \n"[j == c - 1];
}
