
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
  cin >> t;
  while (t--) solve();
}
const ll N = 1000;
void solve() {
    ll n;
    cin >> n;
    ll nn = n;
    while (nn % 2 == 0) {
        nn /= 2;
    }
    if (nn == 1) {
        cout << -1 << '\n';
        return;
    }
    cout << nn << '\n';
}
