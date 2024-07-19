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
  cin >> t; 
  while (t--) solve();
}

void solve() {
  ll n,  m;
  cin >> n >> m;
  deque<ll> a(n), b(m), res;
  for (auto&x : a)
    cin >> x;
  for (auto&x : b)
    cin >> x;
  sort(begin(b), end(b));
  while (!a.empty() && !b.empty()) {
    ll p = a.back();
    ll q = b.front();
    if (a.back() >= b.front()) {
      res.push_front(b.front());
      b.pop_front();
    } else {
      res.push_front(a.back());
      a.pop_back();
    }
  }
  while (!a.empty()) {
    res.push_front(a.back());
    a.pop_back();
  }
  while (!b.empty()) {
    res.push_front(b.front());
    b.pop_front();
  }
  for(auto&y : res)
    cout << y << " ";
  cout << '\n';
}
