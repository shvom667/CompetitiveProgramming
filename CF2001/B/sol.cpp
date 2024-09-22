#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;


auto solve(ll n) {
    vector<ll> ans;
    if (!(n&1)) {
        ans = {-1};
        return ans;
    }
    ans = vector<ll> (n);
    for (ll i = n / 2; i < n; i++) {
        ans[i] = i - n / 2 + 1;
    }
    for (ll i = n / 2 - 1; i >= 0; i--) {
        ans[i] = n / 2 - i + (n + 1) / 2;
    }
    return ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--) {
    ll n;
    cin >> n;
    auto res = solve(n);
    for (auto&x : res) {
        cout << x << " ";
    }   cout << "\n";
  }
}