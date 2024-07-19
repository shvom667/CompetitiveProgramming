
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
    ll n, m;
    cin >> n >> m;
    deque<char> a(n),b(m);
    for(auto&x:a)cin>>x;
    for(auto&x:b)cin>>x;
    ll f=0;
    ll j = 0;
    for (ll i = 0; i < n; i++) {
        while (!b.empty() && b.front() != a[i]) {
            b.pop_front();
        }
        if (b.empty())
            break;
        if (!b.empty() && b.front() == a[i]) {
            b.pop_front();
            f++;
        }
    }
    cout << f << "\n";
}
