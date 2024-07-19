
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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
const ll N = 200;
void solve() {
  cout << N << "\n";
  for (ll i = 1; i <= N; i++)
    cout << 'a';
  cout << "\n";
}
