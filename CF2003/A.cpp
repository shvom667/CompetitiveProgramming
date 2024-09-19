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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == s[n-1]) {
        cout << "No\n";
    }else{
        cout<<"Yes\n";
    }
}